#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;

    Contact(string n, string p) : name(n), phoneNumber(p) {}
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact() {
        string name, phoneNumber;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNumber;

        contacts.emplace_back(name, phoneNumber);
        cout << "Contact added successfully!\n";
    }

    void viewContacts() {
        if (contacts.empty()) {
            cout << "No contacts to display.\n";
            return;
        }

        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". Name: " << contacts[i].name
                << ", Phone Number: " << contacts[i].phoneNumber << "\n";
        }
    }

    void deleteContact() {
        int index;
        cout << "Enter the contact number to delete: ";
        cin >> index;

        if (index <= 0 || index > contacts.size()) {
            cout << "Invalid contact number.\n";
            return;
        }

        contacts.erase(contacts.begin() + index - 1);
        std::cout << "Contact deleted successfully!\n";
    }

    void showMenu() {
        int choice;
        do {
            cout << "\nContact Management System\n";
            cout << "1. Add Contact\n";
            cout << "2. View Contacts\n";
            cout << "3. Delete Contact\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ContactManager manager;
    manager.showMenu();
    return 0;
}