#ifndef IBYTECAVECLIENT_H
#define IBYTECAVECLIENT_H

#include <string>
#include <boost/uuid.hpp>
#include "ui_mainwindow.h"

using namespace std;
// The interface of the ByteCave Client

class IByteCaveClient {

public :
    // Method to send message into the server
    virtual void sendMessage(const string &command,const string &data) = 0;

    // Method to keep reading messages coming from the server
    virtual void readMessagesLoop(Ui::MainWindow ui) = 0;

};

#endif // IBYTECAVECLIENT_H
