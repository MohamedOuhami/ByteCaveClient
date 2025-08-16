#include "bytecaveclient.h"
#include <iostream>

using namespace std;
// The constructor
ByteCaveClient::ByteCaveClient(const string &host, const string &port,QTextBrowser *chatTB,QObject *parent):
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
    oss << command << "\n" << data.size() << "\n" << data;

    asio::write(socket,asio::buffer(oss.str()));
}

void ByteCaveClient::sendMessage(const string &data){

    // Build message with length
    asio::write(socket,asio::buffer(data));
}


// Poll the context
void ByteCaveClient::pollContext(){
    io_context.poll();
}


// Loop to keep reading incoming messages
void ByteCaveClient::readMessagesLoop(Ui::MainWindow ui){

    // Create the buffer that we will fill with our messages
    // It is shared so the lambda function can use It
    auto buffer = make_shared<array<char,1024>>();

    socket.async_read_some(
        // The buffer to read to
        asio::buffer(*buffer),
        // The callback to perform when receiving a message
        [this,buffer,ui](error_code ec,size_t length){
            if(!ec){

                // If the
                string msg(buffer->data(),length);

                auto commandEnd = msg.find("\n");
                if(commandEnd != string::npos){
                    // Stripe the command name from the message
                    string command = msg.substr(0,commandEnd);
                    // Find the size line
                    auto sizeEnd = msg.find("\n",commandEnd+1);
                    if(sizeEnd != string::npos){
                        size_t jsonSize = stoul(msg.substr(commandEnd+1,sizeEnd-commandEnd+1));

                        // Get the paylaod
                        string jsonPayload = msg.substr(sizeEnd+1);

                        // Make sure that we have no missing or incomplete data
                        if (jsonPayload.size() >= jsonSize){

                            // When getting a message
                            if(command == "MESSAGE_SENT"){
                                // Append the new message to the textBrowser


                                chatTB.append(QString::fromStdString(jsonPayload));
                            }

                            // When fetching the chatrooms
                            else if (command == "LIST_CHATROOMS"){


                                // Parse the json
                                json j = json::parse(jsonPayload);
                                ui.chatroomsList->clear();
                                for (auto &chatroom : j["chatrooms"]){
                                    // Add the name to the list of chatrooms in the UI
                                    ui.chatroomsList->addItem(QString::fromStdString(chatroom.get<string>()));
                                }
                            }


                            // When listing the users of a chatrooms
                            else if (command == "LIST_USERS"){
                                // Parse the json

                                json j = json::parse(jsonPayload);
                                ui.chatroomsList->clear();
                                for (auto &user : j["users"]){
                                    // Add the name to the list of chatrooms in the UI
                                    ui.usersList->addItem(QString::fromStdString(user.get<string>()));
                                }
                            }

                            // WHen setting a username
                            else if (command == "USER_CREATED"){
                                // Parse the json
                                json j = json::parse(jsonPayload);

                                // Set the username
                                username = QString::fromStdString(j["username"].get<string>());

                                // Set the uuid
                                boost::uuids::string_generator gen;
                                uuid = gen(j["uuid"].get<string>());

                            }
                        }
                    }
                }

                // Redo the loop
                readMessagesLoop(ui);
            }
            else {
                // Return that there was an error
            }
        });
}
