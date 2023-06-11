#include <iostream>
#include "PhoneBook.h"
using namespace std;

void menu() {
    PhoneBook phoneBook;
    phoneBook.read();
    /// menu function to display the menu and call the functions according to the user's choice after reading the file
    while (true) {
        cout << "\n\t\t\t\t\t  MENU\n\n";
        cout << "\t1. Add New Contact   \t2. Contact List   \t3. Search Contact\n"
             << "\t4. Delete Contact   \t5. Modify Contact   \t6. Exit\n";
        cout << "\n\tEnter 1 to 6: ";

        int choice;
        cin >> choice;

        switch (choice) { /// switch case to call the functions according to the user's choice
            case 1:
                phoneBook.addContact();
                break;
            case 2:
                phoneBook.displayContactList();
                break;
            case 3:
                phoneBook.searchContact();
                break;
            case 4:
                phoneBook.deleteContact();
                break;
            case 5:
                phoneBook.modifyContact();
                break;
            case 6:
                cout << "\n\n\t\t\t\t Are you sure you want to exit? (Y/N): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    cout << "\n\n\t\t\t\t Closing phonebook. Have a nice day!" << endl;
                    return;
                }
                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option." << endl;
        }
    }
}

int main() { /// main function setting the color of the console and calling the menu function starting execution
    system("color 09");
    cout << "\n\n\t\t\t Welcome to the Phonebook Management System!" << endl;
    menu();
    return 0;
}
