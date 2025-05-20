//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    int phone_number;
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, int phone_number) {
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    newEntry->phone_number = phone_number;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

PhoneBookEntry* searchEntry(PhoneBookEntry* head, char* name) {
    PhoneBookEntry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return currentEntry;
        }

        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    PhoneBookEntry* phoneBook = NULL;

    phoneBook = insertEntry(phoneBook, "John Doe", 12345);
    phoneBook = insertEntry(phoneBook, "Jane Doe", 67890);
    phoneBook = insertEntry(phoneBook, "Peter Pan", 32146);

    PhoneBookEntry* foundEntry = searchEntry(phoneBook, "Jane Doe");

    if (foundEntry) {
        printf("Phone number of Jane Doe: %d", foundEntry->phone_number);
    } else {
        printf("Entry not found");
    }

    return 0;
}