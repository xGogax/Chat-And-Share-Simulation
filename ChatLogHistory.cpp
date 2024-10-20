#include "ChatLogHistory.h"
#include <iostream>

ChatLogHistory::ChatLogHistory(int capacity) : capacity(capacity), count(0) {
    history = new User*[capacity];
}

ChatLogHistory::~ChatLogHistory() {
    delete[] history;
}

void ChatLogHistory::addUser(User* user, const std::string& message) {
    user->addMessage(message); // Dodavanje poruke u korisnikov istorijat

    for (int i = 0; i < count; ++i) {
        if (history[i] == user) {
            for (int j = i; j < count - 1; ++j) {
                history[j] = history[j + 1];
            }
            history[count - 1] = user;
            return;
        }
    }

    if (count < capacity) {
        history[count++] = user;
    } else {
        for (int i = 1; i < capacity; ++i) {
            history[i - 1] = history[i];
        }
        history[capacity - 1] = user;
    }
}

void ChatLogHistory::printHistory() const {
    std::cout << "\033[101m\033[97m\033[1m         CHAT HISTORY         \033[0m" << endl;
    for (int i = 0; i < count; ++i) {
        history[i]->printUser();
        history[i]->printLastMessage();
        std::cout << std::endl;
    }
}
