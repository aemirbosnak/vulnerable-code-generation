//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <string.h>

// Define the maximum number of entries
#define MAX_ENTRIES 10

// Define the structure of an entry
typedef struct Entry {
    char name[20];
    char phone[20];
    struct Entry* next;
} Entry;

// Create a linked list of entries
Entry* head = NULL;

// Function to add an entry to the linked list
void addEntry(char* name, char* phone) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));

    strcpy(newEntry->name, name);
    strcpy(newEntry->phone, phone);

    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }
}

// Function to search for an entry
Entry* searchEntry(char* name) {
    Entry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }

    return NULL;
}

// Function to print all entries
void printEntries() {
    Entry* currentEntry = head;

    while (currentEntry) {
        printf("%s: %s\n", currentEntry->name, currentEntry->phone);
        currentEntry = currentEntry->next;
    }
}

int main() {
    // Add some entries
    addEntry("John Doe", "123-456-7890");
    addEntry("Jane Doe", "456-789-0123");
    addEntry("Bill Smith", "321-456-7890");

    // Search for an entry
    Entry* entry = searchEntry("John Doe");

    // Print the entry
    if (entry) {
        printf("%s: %s\n", entry->name, entry->phone);
    } else {
        printf("Entry not found.\n");
    }

    // Print all entries
    printEntries();

    return 0;
}