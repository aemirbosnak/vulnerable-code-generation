//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Contact {
    char *name;
    char *number;
};

struct PhoneBook {
    struct Contact *contacts;
    int numContacts;
};

struct PhoneBook *createPhoneBook() {
    struct PhoneBook *phoneBook = malloc(sizeof(struct PhoneBook));
    phoneBook->contacts = NULL;
    phoneBook->numContacts = 0;
    return phoneBook;
}

void addContact(struct PhoneBook *phoneBook, char *name, char *number) {
    phoneBook->contacts = realloc(phoneBook->contacts, (phoneBook->numContacts + 1) * sizeof(struct Contact));
    phoneBook->contacts[phoneBook->numContacts].name = strdup(name);
    phoneBook->contacts[phoneBook->numContacts].number = strdup(number);
    phoneBook->numContacts++;
}

void printContact(struct Contact contact) {
    printf("%s: %s\n", contact.name, contact.number);
}

void printPhoneBook(struct PhoneBook *phoneBook) {
    for (int i = 0; i < phoneBook->numContacts; i++) {
        printContact(phoneBook->contacts[i]);
    }
}

void freePhoneBook(struct PhoneBook *phoneBook) {
    for (int i = 0; i < phoneBook->numContacts; i++) {
        free(phoneBook->contacts[i].name);
        free(phoneBook->contacts[i].number);
    }
    free(phoneBook->contacts);
    free(phoneBook);
}

int main() {
    struct PhoneBook *phoneBook = createPhoneBook();
    addContact(phoneBook, "John Doe", "555-1212");
    addContact(phoneBook, "Jane Doe", "555-1213");
    addContact(phoneBook, "John Smith", "555-1214");
    addContact(phoneBook, "Jane Smith", "555-1215");
    printPhoneBook(phoneBook);
    freePhoneBook(phoneBook);
    return 0;
}