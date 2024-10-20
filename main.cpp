#include <iostream>
#include "User.h"
#include "ChatLogHistory.h"
#include "SharesHistory.h"

using namespace std;

int main() {
    ChatLogHistory* history = new ChatLogHistory(3);
    SharesHistory sharesHistory;

    int numUsers = 0;
    int capacity = 2;
    User** users = new User*[capacity];

    int x;
    int x5;

    string name;
    string surname;
    string number;
    string message;

    while (true) {
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "+            MENU OPTIONS             +" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "| 1. Add Contact                      |" << endl;
        cout << "| 2. View chat log with user          |" << endl;
        cout << "| 3. View shares with user            |" << endl; // Dodata opcija
        cout << "| 4. Send message                     |" << endl;
        cout << "| 5. Share content                    |" << endl;
        cout << "| 6. Chat history                     |" << endl;
        cout << "| 7. Share history                    |" << endl;
        cout << "| 8. Print Users                      |" << endl;
        cout << "| 9. Settings                         |" << endl;
        cout << "| 10. Exit                            |" << endl;
        cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;

        cin >> x;
        switch (x) {
            case 1:
                if (numUsers >= capacity) {
                    capacity *= 2;
                    User** newUsers = new User*[capacity];
                    for (int i = 0; i < numUsers; ++i) {
                        newUsers[i] = users[i];
                    }
                    delete[] users;
                    users = newUsers;
                }

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter surname: ";
                cin >> surname;
                cout << "Enter number: ";
                cin >> number;

                for (int i = 0; i < numUsers; ++i) {
                    if (users[i]->getNumber() == number) {
                        break;
                    }
                    if (i == numUsers - 1) {
                        users[numUsers++] = new User(name, surname, number);
                    }
                }
                if (numUsers == 0) {
                    users[numUsers++] = new User(name, surname, number);
                }
                break;

            case 2:
                cout << "Enter number: ";
                cin >> number;
                for (int i = 0; i < numUsers; ++i) {
                    if (number == users[i]->getNumber()) {
                        users[i]->printUser();
                        users[i]->printMessages();
                        break;
                    }
                    if (i == numUsers - 1) {
                        cout << "There is no user with that number in your contacts" << endl;
                    }
                }
                break;

            case 3: {
                std::cout << "Unesite broj telefona korisnika: ";
                std::cin >> number;

                User* user = nullptr;
                for (int i = 0; i < numUsers; ++i) {
                    if (users[i]->getNumber() == number) {
                        user = users[i];
                        break;
                    }
                }

                if (user) {
                    std::cout << "Deljeni sadrzaji korisnika:\n";
                    user->printUser();
                    user->printSharedContents();
                } else {
                    std::cout << "Korisnik sa brojem telefona " << number << " nije pronadjen.\n";
                }
                break;
            }

            case 4:
                cout << "Enter number: ";
                cin >> number;
                for (int i = 0; i < numUsers; ++i) {
                    if (number == users[i]->getNumber()) {
                        cout << "Enter message: ";
                        cin.ignore();
                        getline(cin, message);
                        history->addUser(users[i], message);
                        cout << "Message sent to " << users[i]->getNumber() << "!" << endl;
                        break;
                    }
                    if (i == numUsers - 1) {
                        cout << "There is no user with that number in your contacts" << endl;
                    }
                }
            break;

            case 5:
                cout << "Enter number to share content with: ";
                cin >> number;
                for (int i = 0; i < numUsers; ++i) {
                    if (number == users[i]->getNumber()) {
                        string content;
                        cout << "Enter content to share: ";
                        cin.ignore();
                        getline(cin, content);
                        users[i]->shareContent(users[i], content);
                        cout << "Content shared with " << users[i]->getNumber() << "!" << endl;
                        break;
                    }
                    if (i == numUsers - 1) {
                        cout << "There is no user with that number in your contacts" << endl;
                    }
                }
                break;

            case 6:
                history->printHistory();
                break;

            case 7:
                cout << "Sekvenca deljenja:" << endl;
                sharesHistory.printShares();
            break;

            case 8:
                cout << "\033[47m\033[30m\033[1m      List of Contacts        \033[0m" << endl;
                for (int i = 0; i < numUsers; ++i) {
                    users[i]->printUser();
                }
                break;

            case 9:
                cout << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "+          SETTINGS OPTIONS           +" << endl;
                cout << "+-------------------------------------+" << endl;
                cout << "| 1. Set n (default value = 3)        |" << endl;
                cout << "| 2. Exit                             |" << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
                cout << endl;
                cin >> x5;
                if (x5 == 1) {
                    cout << "Enter n: ";
                    cin >> x5;
                    history = new ChatLogHistory(x5);
                    cout << endl;
                } else if (x5 == 2) {
                    break;
                }
                break;

            case 10:
                for (int i = 0; i < numUsers; ++i) {
                    delete users[i];
                }
                delete[] users;
                if (history != nullptr) {
                    delete history;
                }
                return 0;

            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
    return 0;
}
