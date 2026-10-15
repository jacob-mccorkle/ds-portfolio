
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

struct Contact {
    std::string lastName;
    std::string firstName;
    std::string phone;

    Contact() = default;

    Contact(const std::string& last, const std::string& first,
            const std::string& number)
        : lastName(last), firstName(first), phone(number) {}

    bool operator<(const Contact& other) const {
        if (lastName != other.lastName) {
            return lastName < other.lastName;
        }

        return firstName < other.firstName;
    }

    bool operator==(const Contact& other) const {
        return lastName == other.lastName &&
               firstName == other.firstName;
    }
};

inline std::ostream& operator<<(std::ostream& out,
                                const Contact& contact) {
    out << contact.lastName << ", " << contact.firstName
        << " - " << contact.phone;
    return out;
}

#endif
