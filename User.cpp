#include "User.h"
#include "SharesHistory.h"

User::User(const std::string& name, const std::string& surname, const std::string& number)
    : name(name), surname(surname), number(number), messageCount(0), messageCapacity(0),
      messages(nullptr), sharesHistory(new SharesHistory()), sharedContent(nullptr),
      sharedContentCount(0), sharedContentCapacity(0) {}

User::~User() {
    delete[] messages;
    delete[] sharedContent;
    delete sharesHistory;
}

void User::printUser() const {
    cout << "\033[102m\033[1m\033[97m             USER             \033[0m" << endl;
    cout << "\033[107m\033[90m\033[1m" << this->name << " " << this->surname << setw(33 - this->name.length() - this->surname.length()) << "\033[0m" << endl;
    cout << "\033[107m\033[90m\033[1m" << this->number << setw(34 - this->number.length()) << "\033[0m" << endl;
}

void User::addMessage(const std::string& msg) {
    if (messageCount == messageCapacity) {
        expandMessages();
    }
    messages[messageCount++] = msg;
}

void User::expandMessages() {
    int newCapacity = messageCapacity == 0 ? 1 : messageCapacity * 2;
    std::string* newMessages = new std::string[newCapacity];

    for (int i = 0; i < messageCount; ++i) {
        newMessages[i] = messages[i];
    }

    delete[] messages;
    messages = newMessages;
    messageCapacity = newCapacity;
}

void User::printLastMessage() const {
    std::cout << "\033[101m\033[97m\033[1m           MESSAGES           \033[0m" << std::endl;
    for (int i = 0; i < messageCount; ++i) {
        if (i == messageCount - 1) {
            std::cout << "\033[107m \033[104m\033[97m " << messages[i]  << " \033[0m\033[107m" << setw(31 - messages[i].length()) << "\033[0m" << std::endl;
        }
    }
}

void User::printMessages() const {
    std::cout << "\033[101m\033[97m\033[1m           MESSAGES           \033[0m" << std::endl;
    for (int i = 0; i < messageCount; ++i) {
        std::cout << "\033[107m \033[104m\033[97m " << messages[i]  << " \033[0m\033[107m" << setw(31 - messages[i].length()) << "\033[0m" << std::endl;
    }
}

std::string User::getNumber() const {
    return number;
}

void User::shareContent(User* user, const std::string& content) {
    addSharedContent(content);
    sharesHistory->addUser(user);
}

void User::addSharedContent(const std::string& content) {
    if (sharedContentCount == sharedContentCapacity) {
        expandSharedContent();
    }
    sharedContent[sharedContentCount++] = content;
}

void User::expandSharedContent() {
    int newCapacity = sharedContentCapacity == 0 ? 1 : sharedContentCapacity * 2;
    std::string* newContents = new std::string[newCapacity];

    for (int i = 0; i < sharedContentCount; ++i) {
        newContents[i] = sharedContent[i];
    }

    delete[] sharedContent;
    sharedContent = newContents;
    sharedContentCapacity = newCapacity;
}

SharesHistory* User::getSharesHistory() const {
    return sharesHistory;
}

void User::printSharedContents() const {
    if (sharedContentCount == 0) {
        std::cout << "No shared contents.\n";
        return;
    }

    std::cout << "\033[101m\033[97m\033[1m            SHARES            \033[0m" << std::endl;
    for (int i = 0; i < sharedContentCount; ++i) {
        std::cout << "\033[107m\033[90m\033[1m" << sharedContent[i] << setw(34 - sharedContent[i].length()) << "\033[0m" << std::endl;
    }
}
