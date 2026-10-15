
#include "ContactDirectory.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n========================================\n";
    cout << "           CONTACT DIRECTORY            \n";
    cout << "========================================\n";
    cout << "  1. Add Contact\n";
    cout << "  2. Search by Last Name\n";
    cout << "  3. View All Contacts\n";
    cout << "  4. Search by Prefix\n";
    cout << "  5. Directory Statistics\n";
    cout << "  6. Exit\n";
    cout << "========================================\n";
    cout << "  Enter choice: ";
}

int main() {
    ContactDirectory directory;
    int choice;

    cout << "\nWelcome to the Contact Directory!\n";

    while (true) {
        displayMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string firstName, lastName, phone;

                cout << "\n--- Add Contact ---\n";
                cout << "First name: ";
                getline(cin, firstName);

                cout << "Last name: ";
                getline(cin, lastName);

                cout << "Phone number: ";
                getline(cin, phone);

                if (firstName.empty() || lastName.empty() ||
                    phone.empty()) {
                    cout << "\nAll fields are required.\n";
                } else {
                    directory.add(Contact(lastName, firstName, phone));
                }
                break;
            }

            case 2: {
                string lastName;

                cout << "\n--- Search Contact ---\n";
                cout << "Last name: ";
                getline(cin, lastName);

                directory.lookup(lastName);
                break;
            }

            case 3:
                cout << "\n--- Contact List ---\n";
                directory.list();
                cout << "Total contacts: " << directory.count() << '\n';
                break;

            case 4: {
                string beginning;

                cout << "\n--- Prefix Search ---\n";
                cout << "Enter the beginning of a last name: ";
                getline(cin, beginning);

                directory.prefix(beginning);
                break;
            }

            case 5:
                cout << "\n--- Directory Statistics ---\n";
                cout << "Total contacts: " << directory.count() << '\n';
                cout << "Tree height: " << directory.height() << '\n';
                break;

            case 6:
                cout << "\nThank you for using the Contact Directory!\n";
                return 0;

            default:
                cout << "\nInvalid choice. Select an option from 1 to 6.\n";
        }
    }
}
