//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    struct PhoneBookEntry *next;
} PhoneBookEntry;

PhoneBookEntry *createPhoneBookEntry(char *name, char *phone) {
    PhoneBookEntry *entry = (PhoneBookEntry *) malloc(sizeof(PhoneBookEntry));
    strncpy(entry->name, name, MAX_NAME_LEN);
    strncpy(entry->phone, phone, MAX_PHONE_LEN);
    entry->next = NULL;
    return entry;
}

void addEntryToPhoneBook(PhoneBookEntry **head, PhoneBookEntry *newEntry) {
    if (*head == NULL) {
        *head = newEntry;
        return;
    }
    PhoneBookEntry *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newEntry;
}

PhoneBookEntry **getEntryByName(PhoneBookEntry **head, char *name) {
    PhoneBookEntry **current = head;
    while (*current != NULL) {
        if (strncmp((*current)->name, name, MAX_NAME_LEN) == 0) {
            return current;
        }
        current = &((*current)->next);
    }
    return NULL;
}

void removeEntryFromPhoneBook(PhoneBookEntry **head, PhoneBookEntry *entryToRemove) {
    PhoneBookEntry **current = head;
    while (*current != NULL) {
        if (*current == entryToRemove) {
            *current = entryToRemove->next;
            free(entryToRemove);
            return;
        }
        current = &((*current)->next);
    }
}

void printPhoneBook(PhoneBookEntry *head) {
    printf("Phone Book Entries:\n");
    printf("-------------------\n");
    PhoneBookEntry *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

int main() {
    PhoneBookEntry *phoneBook = NULL;

    // Create entries and add to phone book
    PhoneBookEntry *entry1 = createPhoneBookEntry("Alice", "555-1234");
    addEntryToPhoneBook(&phoneBook, entry1);

    PhoneBookEntry *entry2 = createPhoneBookEntry("Bob", "555-5678");
    addEntryToPhoneBook(&phoneBook, entry2);

    PhoneBookEntry *entry3 = createPhoneBookEntry("Charlie", "555-9012");
    addEntryToPhoneBook(&phoneBook, entry3);

    // Remove an entry from phone book
    PhoneBookEntry **entryToRemove = getEntryByName(&phoneBook, "Bob");
    if (entryToRemove != NULL) {
        removeEntryFromPhoneBook(&phoneBook, *entryToRemove);
    }

    printPhoneBook(phoneBook);

    return 0;
}