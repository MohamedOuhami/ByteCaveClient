#ifndef IBYTECAVECLIENT_H
#define IBYTECAVECLIENT_H

#include <string>

using namespace std;
// The interface of the ByteCave Client

class IByteCaveClient {

public :
    // Method to send message into the server
    virtual void sendMessage(string &message) = 0;

    // Method to keep reading messages coming from the server
    virtual void readMessagesLoop() = 0;
};

#endif // IBYTECAVECLIENT_H
