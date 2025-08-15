#ifndef CHATROOM_H
#define CHATROOM_H
#include <string>
#include <vector>

using namespace std;

// Define a struct that takes the data of a chatroom
struct Chatroom{
    // The name of the chatroom
    string name;

    // The description of the chatroom
    string description;

    // The list of users that are connected to the chatroom
    // It will be a vector of UUID that identify each user
    vector<string> connectedClients;
};

#endif // CHATROOM_H

