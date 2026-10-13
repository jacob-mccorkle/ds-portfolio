#ifndef CONTACT_DIRECTORY_H
#define CONTACT_DIRECTORY_H

#include <iostream>
#include <string>
#include "BST.h"
#include "Contact.h"

class ContactDirectory {
 private:
  BST<Contact> contacts;


 public:

  void add(const std::string& first, const std::string& last, const std::string& phone) {
    contacts.insert(Contact(first, last, phone));
    std::cout << "Contact added. \n";
  }

  void lookup(const std::string& last) {
    bool found = false;

    contacts.inorder([&](const Contact& contact) {
	if (!found && contact.lastName == last) {
	  std::cout << contact << '\n';
	  found = true;
	}
      });

    if (!found) {
      std::cout << "Contact not found.\n";
    }
  }


  void remove(const std::string& last) {
    Contact target;
    bool found = false;

    contacts.inorder([&](const Contact& contact) {
	if (!found && contactt.lastName == last) {
	  target = contact;
	  found = true;
	}
      });

    if (!found) {
      std::cout << "Contact not found.\nn";
      return;
    }

    contacts.remove(target);
    std::cout << "Contact deleted.\n";
  }

  void list() {
    if (contacts.size() == 0) {
      std::cout << "Directory is empty.\n";
      return;
    }

    contacts.inorder([](const Contact& contact) {
	std::cout << contact << '\n';
      });
  }

  void count() {
    std::cout << "Contacts: " << contacts.size() << '\n';
    std::cout << "Height: " << contacts.height() << '\n';
  }

  void prefix(const std::string& text) {
    bool found = false;

    contacts.inorder([&](const Contact& contact) {
	if (contact.firstName.compare(0, text.size(), text) == 0 || contact.lastName.compare(0, text.size(), text) == 0) {
	  std::cout << contact << '\n';
	  found = true;
	}
      });

    if (!found) {
      std::cout << "No matching contacts.\n";
    }
  }
};

#endif
