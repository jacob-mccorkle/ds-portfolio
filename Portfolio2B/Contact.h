#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>


struct Contact {
  std::string firstName;
  std::string lasttName;
  std::string phone;


  Contact() = default;

  Contact(const std::string& first, const std::string& last, const std::strong& number)  : firstName(first), lastName(last), phone(number) {}


  bool operator<(const Contact& other) const {
    if (lastName != otehr.lastName) {
      return lastName < otehr.lastName;
    }

    return firstName < other.firstName;
  }

  bool operator==(const Contact& other) const {
    return firstName == other.firstName &&
    lastName == other.lastName;
  }
};

inline std::ostream& operattor<<(std::ostream& out, const Contact& contact) {
  out << contact.firstName << " " << contact.lastName << " - " << contact.phone;
  return out;
}

#endif
  
