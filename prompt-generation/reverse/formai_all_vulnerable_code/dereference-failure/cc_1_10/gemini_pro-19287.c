//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct Contact *newContact = malloc(sizeof(struct Contact));
    newContact->name = malloc(strlen(name) + 1);
    strcpy(newContact->name, name);
    newContact->number = malloc(strlen(number) + 1);
    strcpy(newContact->number, number);
    phoneBook->contacts = realloc(phoneBook->contacts, (phoneBook->numContacts + 1) * sizeof(struct Contact));
    phoneBook->contacts[phoneBook->numContacts++] = *newContact;
}

void printPhoneBook(struct PhoneBook *phoneBook) {
    for (int i = 0; i < phoneBook->numContacts; i++) {
        printf("%s: %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].number);
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
    addContact(phoneBook, "John", "555-1212");
    addContact(phoneBook, "Jane", "555-1213");
    addContact(phoneBook, "Bob", "555-1214");
    printPhoneBook(phoneBook);
    freePhoneBook(phoneBook);
    return 0;
}