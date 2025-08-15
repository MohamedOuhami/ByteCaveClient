#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bytecaveclient.h>
#include <boost/uuid.hpp>
#include "./ui_mainwindow.h"
#include <string>
#include <qtimer.h>
#include "chatroomcreation.h"
#include <Chatroom.h>
#include <nlohmann/json.hpp>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString username,QWidget *parent = nullptr);
    ~MainWindow();

    // Method to set the UUID of the client
    void setUUID(boost::uuids::uuid newUuid){
        uuid = newUuid;
    }

    // Method to get the UUID of the client
    boost::uuids::uuid getUUID(){
        return uuid;
    }



private:
    Ui::MainWindow *ui;
    ByteCaveClient *client = nullptr;
    void sendMessage();
    void showCreateChatroomDialog();
    QString username;

    boost::uuids::uuid uuid;
};
#endif // MAINWINDOW_H
