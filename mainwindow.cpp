#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <qtimer.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the send Message to the send Message function
    connect(ui->sendMessageBtn,&QPushButton::clicked,this,&MainWindow::OnSendButtonClicked);

    // Instantiate Client
    client = new ByteCaveClient("127.0.0.1","8080",ui->chat);

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
