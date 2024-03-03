#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

void addContact(map<string, Contact>& contacts) {
    Contact newContact;
    cout << "Enter contact name: ";
    cin >> newContact.name;
    cout << "Enter phone number: ";
    cin >> newContact.phoneNumber;
    cout << "Enter email address: ";
    cin >> newContact.email;

    contacts[newContact.name] = newContact;
    cout << "Contact added successfully.\n";
}

void displayContact(const map<string, Contact>& contacts, const string& name) {
    auto it = contacts.find(name);
    if (it != contacts.end()) {
        cout << "Name: " << it->second.name << endl;
        cout << "Phone number: " << it->second.phoneNumber << endl;
        cout << "Email address: " << it->second.email << endl;
    }
    else {
        cout << "Contact not found.\n";
    }
}

int main() {
    map<string, Contact> contacts;

    char option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a contact\n";
        cout << "2. Search for a contact\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case '1':
            addContact(contacts);
            break;
        case '2': {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            displayContact(contacts, name);
            break;
        }
        case '3':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (option != '3');

    return 0;
}
