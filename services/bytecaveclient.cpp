#include "bytecaveclient.h"

using namespace std;
// The constructor
ByteCaveClient::ByteCaveClient(const string &host, const string &port,QTextBrowser *chatTB,QObject *parent,const string username):
    QObject(parent),resolver(io_context),socket(io_context),chatTB(chatTB)
{

    // Connect to the server
    asio::connect(socket,resolver.resolve(host,port));

    // Send the username as a first message
    asio::write(socket,asio::buffer(username));

}

// Send message
void ByteCaveClient::sendMessage(const string &command,const string &data){

    // Build message with length
    std::ostringstream oss;
    oss << "CREATE_CHATROOM\n" << data.size() << "\n" << data;

    asio::write(socket,asio::buffer(oss.str()));
}

// Poll the context
void ByteCaveClient::pollContext(){
    io_context.poll();
}

// Method to read the UUID from the server
boost::uuids::uuid ByteCaveClient::readUUID() {
    std::array<char, 36> buffer;
    size_t length = socket.read_some(asio::buffer(buffer));

    string data = buffer.data();
    std::string uuid_str(buffer.data(), length);

    boost::uuids::string_generator gen;
    return gen(uuid_str);
}


// Loop to keep reading incoming messages
void ByteCaveClient::readMessagesLoop(){

    // Create the buffer that we will fill with our messages
    // It is shared so the lambda function can use It
    auto buffer = make_shared<array<char,1024>>();

    socket.async_read_some(
        // The buffer to read to
        asio::buffer(*buffer),
        // The callback to perform when receiving a message
        [this,buffer](error_code ec,size_t length){
            if(!ec){

                // If the
                string msg(buffer->data(),length);

                cout << msg;

                // Append the new message to the textBrowser
                chatTB.append(QString::fromStdString(msg));

                // Redo the loop
                readMessagesLoop();
            }
            else {
                // Return that there was an error
            }
        });
}
