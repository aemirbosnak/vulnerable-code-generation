//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} PhoneEntry;

typedef struct {
    PhoneEntry entries[MAX_NUM_ENTRIES];
    int numEntries;
} PhoneBook;

PhoneBook* createPhoneBook() {
    PhoneBook* phoneBook = (PhoneBook*)malloc(sizeof(PhoneBook));
    phoneBook->numEntries = 0;
    return phoneBook;
}

void destroyPhoneBook(PhoneBook* phoneBook) {
    free(phoneBook);
}

int addEntry(PhoneBook* phoneBook, const char* name, const char* number) {
    if (phoneBook->numEntries >= MAX_NUM_ENTRIES) {
        printf("Phone book is full, cannot add entry.\n");
        return -1;
    }

    PhoneEntry entry = {.name = name,.number = number };
    int index = phoneBook->numEntries++;
    phoneBook->entries[index] = entry;
    return index;
}

PhoneEntry* findEntry(PhoneBook* phoneBook, const char* name) {
    for (int i = 0; i < phoneBook->numEntries; i++) {
        if (strcmp(phoneBook->entries[i].name, name) == 0) {
            return &phoneBook->entries[i];
        }
    }
    return NULL;
}

void printPhoneBook(PhoneBook* phoneBook) {
    printf("Phone Book:\n");
    for (int i = 0; i < phoneBook->numEntries; i++) {
        printf("Name: %s, Number: %s\n", phoneBook->entries[i].name, phoneBook->entries[i].number);
    }
}

int main() {
    PhoneBook* phoneBook = createPhoneBook();

    addEntry(phoneBook, "John", "555-1234");
    addEntry(phoneBook, "Jane", "555-5678");
    addEntry(phoneBook, "Bob", "555-9012");

    PhoneEntry* entry = findEntry(phoneBook, "John");
    if (entry) {
        printf("Found entry for John: %s, %s\n", entry->name, entry->number);
    } else {
        printf("Entry not found for John\n");
    }

    printPhoneBook(phoneBook);

    destroyPhoneBook(phoneBook);

    return 0;
}