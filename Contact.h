#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Contact {
private:
    string name;
    string address;
    string father_name;
    string mother_name;
    string number;
    string gender;
    string mail;

public:

    Contact(const string& name, const string& address, const string& father_name,
            const string& mother_name, const string& number, const string& gender, const string& mail)
            : name(name), address(address), father_name(father_name),
              mother_name(mother_name), number(number), gender(gender), mail(mail) {}

    friend ostream& operator<<(ostream& os, const Contact& contact);  /// operator overloading for outputting contact

    /// class definition for contact including getters and setters

    string getName() const { return name; }
    string getAddress() const { return address; }
    string getFatherName() const { return father_name; }
    string getMotherName() const { return mother_name; }
    string getNumber() const { return number; }
    string getGender() const { return gender; }
    string getMail() const { return mail; }
    void setName(const string& name) { this->name = name; }
    void setAddress(const string& address) { this->address = address; }
    void setFatherName(const string& father_name) { this->father_name = father_name; }
    void setMotherName(const string& mother_name) { this->mother_name = mother_name; }
    void setNumber(const string& number) { this->number = number; }
    void setGender(const string& gender) {this->gender = gender; }
    void setMail(const string& mail) { this->mail = mail; }
};

ostream& operator<<(ostream& os, const Contact& contact) { /// operator overloading for outputting contact implementation
    os << "Name: " << contact.name << endl;
    os << "Address: " << contact.address << endl;
    os << "Father's name: " << contact.father_name << endl;
    os << "Mother's name: " << contact.mother_name << endl;
    os << "Telephone number: " << contact.number << endl;
    os << "Gender: " << contact.gender << endl;
    os << "Email address: " << contact.mail << endl;
    return os;
}
