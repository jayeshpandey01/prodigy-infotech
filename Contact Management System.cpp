#include <iostream>
#include <vector>
#include <string>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string emailAddress;

public:
    // Constructor
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress) 
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress) {}

    // Getters
    std::string getName() const {
        return name;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    std::string getEmailAddress() const {
        return emailAddress;
    }

    // Setters
    void setPhoneNumber(const std::string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }

    void setEmailAddress(const std::string& newEmailAddress) {
        emailAddress = newEmailAddress;
    }
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    // Add a new contact
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress) {
        contacts.emplace_back(name, phoneNumber, emailAddress);
    }

    // View all contacts
    void viewContacts() const {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
        } else {
            std::cout << "Contacts:\n";
            for (const auto& contact : contacts) {
                std::cout << "Name: " << contact.getName() << ", Phone: " << contact.getPhoneNumber() 
                          << ", Email: " << contact.getEmailAddress() << std::endl;
            }
        }
    }

    // Edit an existing contact
    void editContact(int index, const std::string& newPhoneNumber, const std::string& newEmailAddress) {
        if (index >= 0 && index < contacts.size()) {
            contacts[index].setPhoneNumber(newPhoneNumber);
            contacts[index].setEmailAddress(newEmailAddress);
            std::cout << "Contact edited successfully.\n";
        } else {
            std::cout << "Invalid contact index.\n";
        }
    }

    // Delete a contact
    void deleteContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            contacts.erase(contacts.begin() + index);
            std::cout << "Contact deleted successfully.\n";
        } else {
            std::cout << "Invalid contact index.\n";
        }
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    std::string name, phoneNumber, emailAddress;
    int index;

    do {
        std::cout << "\nContact Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. View Contacts\n";
        std::cout << "3. Edit Contact\n";
        std::cout << "4. Delete Contact\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter phone number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter email address: ";
                std::cin >> emailAddress;
                contactManager.addContact(name, phoneNumber, emailAddress);
                std::cout << "Contact added successfully.\n";
                break;
            case 2:
                contactManager.viewContacts();
                break;
            case 3:
                std::cout << "Enter index of contact to edit: ";
                std::cin >> index;
                std::cout << "Enter new phone number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter new email address: ";
                std::cin >> emailAddress;
                contactManager.editContact(index, phoneNumber, emailAddress);
                break;
            case 4:
                std::cout << "Enter index of contact to delete: ";
                std::cin >> index;
                contactManager.deleteContact(index);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
