//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
    char name[100];
    char phoneNumber[20];
    struct PhoneBookEntry* next;
};

struct PhoneBook {
    struct PhoneBookEntry* head;
    int numEntries;
};

struct PhoneBook* createPhoneBook() {
    struct PhoneBook* phoneBook = (struct PhoneBook*)malloc(sizeof(struct PhoneBook));
    phoneBook->head = NULL;
    phoneBook->numEntries = 0;
    return phoneBook;
}

void addEntryToPhoneBook(struct PhoneBook* phoneBook, const char* name, const char* phoneNumber) {
    struct PhoneBookEntry* newEntry = (struct PhoneBookEntry*)malloc(sizeof(struct PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->next = NULL;

    if (phoneBook->head == NULL) {
        phoneBook->head = newEntry;
    } else {
        struct PhoneBookEntry* currentEntry = phoneBook->head;
        while (currentEntry->next!= NULL) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }

    phoneBook->numEntries++;
}

void printPhoneBook(struct PhoneBook* phoneBook) {
    struct PhoneBookEntry* currentEntry = phoneBook->head;
    while (currentEntry!= NULL) {
        printf("%s: %s\n", currentEntry->name, currentEntry->phoneNumber);
        currentEntry = currentEntry->next;
    }
}

int main() {
    struct PhoneBook* phoneBook = createPhoneBook();
    addEntryToPhoneBook(phoneBook, "King Arthur", "555-555-5555");
    addEntryToPhoneBook(phoneBook, "Queen Guinevere", "555-555-5556");
    addEntryToPhoneBook(phoneBook, "Sir Lancelot", "555-555-5557");
    addEntryToPhoneBook(phoneBook, "Merlin the Wizard", "555-555-5558");
    printPhoneBook(phoneBook);
    return 0;
}