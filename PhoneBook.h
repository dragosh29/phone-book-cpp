#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Contact.h"
using namespace std;

class PhoneBook {
private:
    vector<Contact> contacts; /// we use STL vector template to store contacts instead of an array

public:
    void read();
    void displayContactList();
    void deleteContact();
    void addContact();
    void searchContact();
    void modifyContact();
    void reset();
};

void PhoneBook::searchContact() {
    string searchString;
    system("cls");
    cout << "Enter the substring to search for in the phone number: ";
    cin >> searchString;

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getNumber().find(searchString) != string::npos) {
            cout << "Contact found:\n" << contact << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No contacts found matching the search criteria" << endl;
    }
    system("pause");
}

void PhoneBook::addContact() { /// add contact function to add a new contact to the vector and the file with push_back
    string name, address, father_name, mother_name, number, gender, mail;
    system("cls");
    cin.ignore();  /// ignore the newline character in the input stream left by cin

    cout << "Enter name: ";
    getline(cin, name); /// getline is used to read a line of text from the input stream

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter father's name: ";
    getline(cin, father_name);

    cout << "Enter mother's name: ";
    getline(cin, mother_name);

    cout << "Enter telephone number: ";
    getline(cin, number);

    cout << "Enter gender: ";
    getline(cin, gender);

    cout << "Enter email address: ";
    getline(cin, mail);

    Contact contact(name, address, father_name, mother_name, number, gender, mail);
    contacts.push_back(contact); /// add the contact to the vector

    ofstream outputFile("input.txt", ios::app);
    if (!outputFile) {
        cout << "Error opening file" << endl;
        return;
    }

    outputFile << contact.getName() << " " << contact.getAddress() << " " << contact.getFatherName() << " "
               << contact.getMotherName() << " " << contact.getNumber() << " " << contact.getGender() << " "
               << contact.getMail() << endl;

    outputFile.close();

    cout << "Contact added successfully" << endl;
    system("pause");
}

void PhoneBook::deleteContact() { /// delete contact function to delete a contact from the vector and the file with erase
    system("cls");
    string number;

    cout << "Enter the telephone number of the contact you want to delete: ";
    cin >> number;

    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getNumber() == number) {
            contacts.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        ofstream outputFile("input.txt");
        if (!outputFile) {
            cout << "Error opening file" << endl;
            return;
        }

        for (const auto& contact : contacts) {
            outputFile << contact.getName() << " " << contact.getAddress() << " " << contact.getFatherName() << " "
                       << contact.getMotherName() << " " << contact.getNumber() << " " << contact.getGender() << " "
                       << contact.getMail() << endl;
        }

        outputFile.close();

        cout << "Contact deleted successfully" << endl;
    } else {
        cout << "Contact not found" << endl;
    }
    system("pause");
}

void PhoneBook::displayContactList() { /// display contact list function to display all contacts in the vector
    system("cls");
    for (const auto& contact : contacts) cout << contact << endl; /// auto type is used to avoid long type names
    if(contacts.empty()) cout << "No contacts found" << endl; /// empty function is used to check if the vector is empty
    system("pause");
}

void PhoneBook::read(){ /// read function to read contacts from the file and store them in the vector

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Error opening file" << endl;
        return;
    }

    string name, address, father_name, mother_name, number, gender, mail;
    while (inputFile >> name >> address >> father_name >> mother_name >> number >> gender >> mail) {
        Contact contact(name, address, father_name, mother_name, number, gender, mail);
        contacts.push_back(contact); /// push_back function is used to add a new contact to the vector
    }

    inputFile.close();
    system("pause");
}

void PhoneBook::modifyContact() {
    system("cls");
    string number;
    ///search for the contact by number
    cout << "Enter the number of the contact you want to modify: ";
    cin >> number;

    bool found = false;
    for (auto& contact : contacts) {
        if (contact.getNumber() == number) {
            // Modify the contact information
            string newAddress, newNumber, newName, newFatherName, newMotherName, newGender, newMail;

            cin.ignore();  /// ignore the newline character in the input stream left by cin

            cout << "Enter the new name: ";
            getline(cin, newName); /// getline is used to read a line of text from the input stream
            contact.setName(newName);

            cout << "Enter the new address: ";
            getline(cin, newAddress);
            contact.setAddress(newAddress);

            cout << "Enter the new father's name: ";
            getline(cin, newFatherName);
            contact.setFatherName(newFatherName);

            cout << "Enter the new mother's name: ";
            getline(cin, newMotherName);
            contact.setMotherName(newMotherName);

            cout << "Enter the new telephone number: ";
            getline(cin, newNumber);
            contact.setNumber(newNumber);

            cout << "Enter the new gender: ";
            getline(cin, newGender);
            contact.setGender(newGender);

            cout<< "Enter the new email address: ";
            getline(cin, newMail);
            contact.setMail(newMail);

            cout << "Contact modified successfully" << endl;
            found = true;
            break;
        } /// finish modifying the contact information
    }

    if (!found) {
        cout << "Contact not found" << endl;
    }
    system("pause");
}

void PhoneBook::reset() {
    system("cls");
    contacts.clear(); // Clear all contacts from the vector
    ofstream outputFile("input.txt"); // Clear all contacts from the file
    if (!outputFile) {
        cout << "Error opening file" << endl;
        return;
    }
    outputFile.close();
    cout << "Phone book reset successfully" << endl;
    system("pause");
}
