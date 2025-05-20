//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct PhoneBookEntry {
    char name[50];
    char number[20];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

// Create a linked list of phone book entries
PhoneBookEntry* createPhoneBook() {
    PhoneBookEntry* head = NULL;
    head = malloc(sizeof(PhoneBookEntry));
    head->next = NULL;
    return head;
}

// Insert a phone book entry into the linked list
void insertPhoneBookEntry(PhoneBookEntry* head, char* name, char* number) {
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        PhoneBookEntry* currentEntry = head;
        while (currentEntry->next != NULL) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

// Search for a phone book entry by name
PhoneBookEntry* searchPhoneBookEntryByName(PhoneBookEntry* head, char* name) {
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
    PhoneBookEntry* phoneBook = createPhoneBook();

    // Insert phone book entries
    insertPhoneBookEntry(phoneBook, "John Doe", "123-456-7890");
    insertPhoneBookEntry(phoneBook, "Jane Doe", "456-789-0123");
    insertPhoneBookEntry(phoneBook, "Bill Smith", "987-654-3214");

    // Search for a phone book entry by name
    PhoneBookEntry* entry = searchPhoneBookEntryByName(phoneBook, "John Doe");

    // Print the phone number of the entry
    if (entry) {
        printf("Phone number: %s\n", entry->number);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}