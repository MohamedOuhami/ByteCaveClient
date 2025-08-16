// This file is the header for our ByteCaveClient service
#ifndef BYTECAVECLIENT_H
#define BYTECAVECLIENT_H

#include <IByteCaveClient.h>
#include <string>
#include <asio.hpp>
#include <QTextBrowser>
#include <boost/uuid.hpp>
#include <asio.hpp>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using asio::ip::tcp;
using json = nlohmann::json;

// we need our Client to inherit from QObject which is the base for all the QT objects, and It gives us the opportunity to integrate with QT
class ByteCaveClient : public QObject, public IByteCaveClient
{
    // What you see here is a macro, and It is super important
    // It tells the pre-compiler that this class needs to be run through the MOC or the Meta-Object Compiler
    // It adds additional hidden members and functions, in addition to parsing signals and slots
    // It is only added to classes that works with slots/signals
    Q_OBJECT

    // The question is now ,does my client need slots and signals ??
    // What I would want is my client to receive messages from the server, and log the new message in the TextBrowser
    // So, what I need is a slot

public:
    // Constructor
    ByteCaveClient(const string &host,const string &port,QTextBrowser *chatTB,QObject *parent = nullptr);

    // Method to send message to server
    void sendMessage(const string &command,const string &data) override;

    void sendMessage(const string &data);

    // Method to read the messages in a loop
    void readMessagesLoop(Ui::MainWindow ui) override;

    void pollContext();

    QString username;

    boost::uuids::uuid uuid;

    QTextBrowser chatTB;

private:

    asio::io_context io_context;
    tcp::resolver resolver;
    tcp::socket socket;

};

#endif // BYTECAVECLIENT_H
