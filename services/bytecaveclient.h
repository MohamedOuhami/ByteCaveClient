#ifndef BYTECAVECLIENT_H
#define BYTECAVECLIENT_H

#include <IByteCaveClient.h>
#include <string>
#include <asio.hpp>
#include <QTextBrowser>

using namespace std;
using asio::ip::tcp;

class ByteCaveClient : public QObject, public IByteCaveClient
{
    Q_OBJECT
public:

    // Constructor
    ByteCaveClient(const string &host,const string &port,QTextBrowser *chatTB,QObject *parent = nullptr);

    // Method to send message to server
    void sendMessage(string &message) override;

    // Method to read the messages in a loop
    void readMessagesLoop() override;

    void pollContext();

signals:
    void newMessageReceived(QString message);

private:
    asio::io_context io_context;
    tcp::resolver resolver;
    tcp::socket socket;
};

#endif // BYTECAVECLIENT_H
