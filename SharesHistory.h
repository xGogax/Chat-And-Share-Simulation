#ifndef SHARESHISTORY_H
#define SHARESHISTORY_H

class User;

class SharesHistoryNode {
public:
    User* user;
    SharesHistoryNode* next;

    SharesHistoryNode(User* u) : user(u), next(nullptr) {}
};

class SharesHistory {
public:
    SharesHistory();
    ~SharesHistory();

    void addUser(User* user);
    void printHistory() const;
    void printShares() const;

private:
    SharesHistoryNode* head;
};

#endif // SHARESHISTORY_H
