#ifndef SHARESHISTORY_H
#define SHARESHISTORY_H

class User;

class SharesHistoryNode {
public:
    User* user;
    SharesHistoryNode* next;
    int numb = 1;

    SharesHistoryNode(User* u) : user(u), next(nullptr) {}
};

class SharesHistory {
public:
    SharesHistory();
    ~SharesHistory();

    void addUser(User* user, int x);
    void printHistory() const;
    void printShares() const;

private:
    SharesHistoryNode* head;
};

#endif // SHARESHISTORY_H
