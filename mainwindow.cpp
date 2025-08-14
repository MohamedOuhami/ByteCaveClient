#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <qtimer.h>
#include "chatroomcreation.h"

using namespace std;
MainWindow::MainWindow(QString username,QWidget *parent)
    : QMainWindow(parent), username(username)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set the username sent from the hellowindow
    QString current = ui->usernameTag->text();
    ui->usernameTag->setText(current + username);

    // Connect the send Message to the send Message function
    connect(ui->sendMessageBtn,&QPushButton::clicked,this,&MainWindow::OnSendButtonClicked);

    // Connect the create chatroom button with the oncreatechatroombuttonclicked
    connect(ui->createChatroomBtn,&QPushButton::clicked,this,&MainWindow::OnCreateChatroomButtonClicked);

    // Instantiate Client
    client = new ByteCaveClient("127.0.0.1","8080",ui->chat,nullptr,username.toStdString());

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

void MainWindow::OnSendButtonClicked(){
    if(client){
        std::string message = ui->messageLE->text().toStdString();
        client->sendMessage(message);
    }
}

// A callback function for when pressing the create a chatroom
void MainWindow::OnCreateChatroomButtonClicked(){

    // Create a new instance of the Create Chatroom dialog
    chatroomCreation chatroomDialog(this);

    chatroomDialog.exec();

}
