#include "SharesHistory.h"
#include "User.h"
#include <iostream>

SharesHistory::SharesHistory() : head(nullptr) {}

SharesHistory::~SharesHistory() {
    SharesHistoryNode* current = head;
    while (current) {
        SharesHistoryNode* next = current->next;
        delete current;
        current = next;
    }
}

void SharesHistory::addUser(User* user, int x) {
    SharesHistoryNode* newNode = new SharesHistoryNode(user);

    if (head == nullptr) {
        head = newNode;
    } else {
        SharesHistoryNode* current = head;
        SharesHistoryNode* previous = nullptr;

        while (current) {
            if (current->user->getNumber() == user->getNumber()) {
                if (previous) {
                    if(current->numb == x-1){
                        previous->next = current->next;
                        current->next = head;
                        head = current;
                    } else {
                        User* temp = current->user;
                        current->user = previous->user;
                        previous->user = temp;
                        previous->numb++;
                    }
                }
                return;
            }
            previous = current;
            current = current->next;
        }

        newNode->next = head;
        head = newNode;
    }
}

void SharesHistory::printHistory() const {
    SharesHistoryNode* current = head;
    std::cout << "Shares history:\n";
    while (current) {
        current->user->printUser();
        current = current->next;
    }
}

void SharesHistory::printShares() const {
    SharesHistoryNode* current = head;
    if (current == nullptr) {
        std::cout << "No shares history.\n";
        return;
    }

    while (current) {
        current->user->printUser();
        current = current->next;
        if (current) {
            std::cout << "               |" << endl;
        }
    }
    std::cout << std::endl;
}