
#ifndef CONTACT_DIRECTORY_H
#define CONTACT_DIRECTORY_H

#include "BST.h"
#include "Contact.h"
#include <iostream>
#include <string>

class ContactDirectory {
private:
    BST<Contact> contacts;

public:
    void add(const Contact& contact) {
        if (contacts.search(contact)) {
            std::cout << "\nThat contact already exists.\n";
            return;
        }

        contacts.insert(contact);
        std::cout << "\nContact added successfully!\n";
    }

    void list() const {
        if (contacts.size() == 0) {
            std::cout << "\nNo contacts in the directory.\n";
            return;
        }

        std::cout << "\nLast Name, First Name - Phone\n";
        std::cout << "----------------------------------------\n";
        contacts.inorder();
    }

    void lookup(const std::string& lastName) const {
        bool found = false;

        contacts.forEachInorder([&](const Contact& contact) {
            if (contact.lastName == lastName) {
                std::cout << contact << '\n';
                found = true;
            }
        });

        if (!found) {
            std::cout << "No contacts found with last name: "
                      << lastName << '\n';
        }
    }

    void prefix(const std::string& beginning) const {
        bool found = false;

        contacts.forEachInorder([&](const Contact& contact) {
            if (contact.lastName.compare(
                    0, beginning.size(), beginning) == 0) {
                std::cout << contact << '\n';
                found = true;
            }
        });

        if (!found) {
            std::cout << "No contacts found starting with: "
                      << beginning << '\n';
        }
    }

    bool remove(const Contact& contact) {
        if (!contacts.search(contact)) {
            return false;
        }

        contacts.remove(contact);
        return true;
    }

    int count() const {
        return contacts.size();
    }

    int height() const {
        return contacts.height();
    }
};

#endif
