#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <iomanip>

class SharesHistory;

using namespace std;

class User {
public:
    User(const std::string& name, const std::string& surname, const std::string& number);
    ~User();

    void printUser() const;
    void addMessage(const std::string& msg);
    void printMessages() const;
    void printLastMessage() const;
    std::string getNumber() const;

    void shareContent(User* user, const std::string& content);
    SharesHistory* getSharesHistory() const;

    void addSharedContent(const std::string& content);
    void printSharedContents() const;

private:
    std::string name;
    std::string surname;
    std::string number;

    std::string* messages;
    int messageCount;
    int messageCapacity;

    SharesHistory* sharesHistory;

    string* sharedContent;
    int sharedContentCount;
    int sharedContentCapacity;

    void expandMessages();
    void expandSharedContent();
};

#endif // USER_H
