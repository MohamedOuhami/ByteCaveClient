#include "hellowindow.h"
#include "ui_hellowindow.h"
#include <string>
#include "mainwindow.h"

using namespace std;

// This is the HelloWindow, which represents the first screen that the client sees to enter his username
HelloWindow::HelloWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HelloWindow)
{
    ui->setupUi(this);

    // When the connect button is clicked, go to the main window with the username as arguments
    // We can do this using signals and slots, with creating a slot that reacts to the button click signal
    // Listen for the click
    connect(
        ui->connectBtn, // The sender object
        &QPushButton::clicked, // The signal
        this, // The receiver
        [this]() { // The slots (
            QString usernameQString = ui->usernameTB->text();
            transitionToMain(usernameQString);
        }
        );


}

HelloWindow::~HelloWindow()
{
    delete ui;
}

// Define the transition to MainWindow
void HelloWindow::transitionToMain(QString &username){

    // Instantiate a new Main Window
    // We use the new keyword to put the object in the heap
    MainWindow *mainWin = new MainWindow(username);

    // Hide this window and show the main win
    this->hide();
    mainWin->show();
}
