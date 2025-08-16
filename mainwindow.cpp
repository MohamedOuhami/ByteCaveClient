#include "mainwindow.h"

using namespace std;
using json = nlohmann::json;

MainWindow::MainWindow(QString username,QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the username sent from the hellowindow
    QString current = ui->usernameTag->text();
    ui->usernameTag->setText(current + username);

    // Connect the send Message to the send Message function
    connect(ui->sendMessageBtn,&QPushButton::clicked,this,[this,username](){

        if (activeChatroom != "" && ui->messageLE->text().toStdString() != ""){
            // Get the active chatroom
            json j;

            j["chatroom"] = activeChatroom;
            j["username"] = username.toStdString();
            j["message"] = ui->messageLE->text().toStdString();

            client->sendMessage("MESSAGE_SENT",j.dump());

            ui->messageLE->clear();
        }

    });

    // Connect the create chatroom button with the oncreatechatroombuttonclicked
    connect(ui->createChatroomBtn,&QPushButton::clicked,this,&MainWindow::showCreateChatroomDialog);

    // Connect the Refresh button to sending a command message to the server
    connect(ui->refreshChatroomsBtn,&QPushButton::clicked,this,[this](){
        cout << "Refreshing chatrooms" << endl;
        client->sendMessage("GET_CHATROOMS","{}");
    });

    // Connecting clicking on an item in the list
    connect(ui->chatroomsList,&QListWidget::itemClicked,this,&MainWindow::changeActiveChatroom);

    // Instantiate Client
    client = new ByteCaveClient("127.0.0.1","8080",ui->chat,nullptr);

    // After creating a new Service instance, the server will send the uuid of the new user
    // We need to store It in the uuid member

    client->sendMessage(username.toStdString());

    // Starts reading messages
    client->readMessagesLoop(*ui);

    // Poll the context
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[this]() {
        client->pollContext();
    });

    timer->start(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage(){
    if(client){
        std::string message = ui->messageLE->text().toStdString();
        client->sendMessage("MESSAGE",message);
    }
}

// A callback function for when pressing the create a chatroom
void MainWindow::showCreateChatroomDialog(){

    // Create a new instance of the Create Chatroom dialog
    chatroomCreation chatroomDialog(this);

    // Connect the chatroom dataerady signal to the main window
    connect(&chatroomDialog, &chatroomCreation::chatroomDataReady,
            this, [this](const QString &name, const QString &description){

        // Send the chatroom data to the server to create the new chatroom
        vector<string> chatroomClients;
        chatroomClients.push_back(boost::uuids::to_string(client->uuid));

        // Create a new Chatroom object
        Chatroom newChatroom {name.toStdString(),description.toStdString(),chatroomClients};

        // Parse the object into JSON
        json j;
        j["name"] = newChatroom.name;
        j["description"] = newChatroom.description;
        j["chatroomClients"] = newChatroom.connectedClients;

        // Convert the json into string
        string chatroomJsonStr = j.dump();

        // Send the json through the socket
        client->sendMessage("CREATE_CHATROOM",chatroomJsonStr);

    });

    chatroomDialog.exec();

}

void MainWindow::changeActiveChatroom(QListWidgetItem* item){


    // Clear the users list
    ui->usersList->clear();

    // Clear the chat
    client->chatTB.clear();

    // Set the activeChatroom
    activeChatroom = item->text().toStdString();

    json j;
    j["chatroom"] = activeChatroom;
    j["user_uuid"] = boost::uuids::to_string(client->uuid);

    cout << j["chatroom"] << "-" << j["user_uuid"] << endl;
    // Get the list of users connected to the chatroom
    client->sendMessage("GET_USERS",j.dump());

}
