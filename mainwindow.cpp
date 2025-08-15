#include "mainwindow.h"

using namespace std;
using json = nlohmann::json;

MainWindow::MainWindow(QString username,QWidget *parent)
    : QMainWindow(parent), username(username)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the username sent from the hellowindow
    QString current = ui->usernameTag->text();
    ui->usernameTag->setText(current + username);

    // Connect the send Message to the send Message function
    connect(ui->sendMessageBtn,&QPushButton::clicked,this,&MainWindow::sendMessage);

    // Connect the create chatroom button with the oncreatechatroombuttonclicked
    connect(ui->createChatroomBtn,&QPushButton::clicked,this,&MainWindow::showCreateChatroomDialog);

    // Instantiate Client
    client = new ByteCaveClient("127.0.0.1","8080",ui->chat,nullptr,username.toStdString());

    // After creating a new Service instance, the server will send the uuid of the new user
    // We need to store It in the uuid member

    // I know that the first message will be the uuid;
    boost::uuids::uuid userUUID = client->readUUID();

    setUUID(userUUID);

    // Starts reading messages
    client->readMessagesLoop();

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
        chatroomClients.push_back(boost::uuids::to_string(uuid));

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
