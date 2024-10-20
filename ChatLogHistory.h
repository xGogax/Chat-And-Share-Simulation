#ifndef CHATLOGHISTORY_H
#define CHATLOGHISTORY_H

#include "User.h"

class ChatLogHistory {
public:
    ChatLogHistory(int capacity);
    ~ChatLogHistory();

    void addUser(User* user, const std::string& message);
    void printHistory() const;

private:
    User** history;
    int count;
    int capacity;
};

#endif // CHATLOGHISTORY_H
