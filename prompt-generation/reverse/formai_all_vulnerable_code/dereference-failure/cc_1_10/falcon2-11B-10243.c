//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a mailing list entry
struct MailingListEntry {
    char email[100];
    struct MailingListEntry* next;
};

// Define a global list head to keep track of the list
struct MailingListEntry* listHead = NULL;

// Function to add an entry to the mailing list
void addEntry(char* email) {
    struct MailingListEntry* newEntry = malloc(sizeof(struct MailingListEntry));
    strcpy(newEntry->email, email);
    newEntry->next = listHead;
    listHead = newEntry;
}

// Function to remove an entry from the mailing list
void removeEntry(char* email) {
    struct MailingListEntry* current = listHead;
    struct MailingListEntry* prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->email, email) == 0) {
            // If the entry to be removed is found, remove it
            if (prev == NULL) {
                listHead = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print all entries in the mailing list
void printEntries() {
    struct MailingListEntry* current = listHead;

    while (current!= NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// Main function
int main() {
    // Add some entries to the mailing list
    addEntry("user1@example.com");
    addEntry("user2@example.com");
    addEntry("user3@example.com");

    // Print all entries in the mailing list
    printEntries();

    // Remove an entry from the mailing list
    removeEntry("user2@example.com");

    // Print all entries in the mailing list again
    printEntries();

    return 0;
}