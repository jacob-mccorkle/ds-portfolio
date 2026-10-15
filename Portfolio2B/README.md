# Portfolio 2B - Contact Directory

## Description

This project implements a contact directory in C++ using a templated Binary Search Tree (BST). Contacts are organized alphabetically by last name and then first name.

The program provides a menu-driven interface for managing contacts.

## Features

- Add contacts with a first name, last name, and phone number.
- Search for contacts by last name.
- Search for contacts using a last-name prefix.
- Display all contacts in alphabetical order.
- Delete a contact.
- Display the total number of contacts and the height of the BST.
- Manage dynamically allocated tree nodes using the Rule of Three.

## Files

- `BST.h` - Templated Binary Search Tree implementation.
- `Contact.h` - Contact structure and comparison operators.
- `ContactDirectory.h` - Contact directory operations.
- `main.cpp` - Menu and user interaction.
- `Makefile` - Compilation instructions.

## Compiling on Ludwig

Connect to `ludwig.mcs.uvawise.edu` and navigate to the `Portfolio2B` directory.

Compile the program using:

```bash
make clean
make
```

The program uses `g++` with C++17 compiler settings and warning flags.

## Running the Program

Run the compiled executable:

```bash
./contact_directory
```

Follow the numbered menu options to manage contacts.

## Known Limitations

- Contacts are stored in memory and are not saved when the program exits.
- The tree is an ordinary Binary Search Tree and does not automatically balance itself, so performance can decrease if contacts are inserted in an unfavorable order.
- Contact deletion requires entering the matching contact information.
- Contact names and phone numbers are stored as text; the program does not validate phone number formats.
