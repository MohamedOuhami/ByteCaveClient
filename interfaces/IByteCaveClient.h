#ifndef IBYTECAVECLIENT_H
#define IBYTECAVECLIENT_H

#include <string>
#include <boost/uuid.hpp>
using namespace std;
// The interface of the ByteCave Client

class IByteCaveClient {

public :
    // Method to send message into the server
    virtual void sendMessage(const string &command,const string &data) = 0;

    // Method to keep reading messages coming from the server
    virtual void readMessagesLoop() = 0;

    // Method to read the UUID
    virtual boost::uuids::uuid readUUID() = 0;
};

#endif // IBYTECAVECLIENT_H
