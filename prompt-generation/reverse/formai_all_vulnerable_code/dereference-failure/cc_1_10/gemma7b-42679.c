//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of entries
#define MAX_ENTRIES 100

// Define the structure of an entry
typedef struct Entry {
    char title[20];
    char content[1000];
    struct Entry* next;
} Entry;

// Create a new entry
Entry* newEntry() {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->next = NULL;
    return newEntry;
}

// Insert an entry into the list
void insertEntry(Entry* head, Entry* newEntry) {
    if (head == NULL) {
        head = newEntry;
    } else {
        newEntry->next = head;
        head = newEntry;
    }
}

// Print all entries
void printEntries(Entry* head) {
    Entry* currentEntry = head;
    while (currentEntry) {
        printf("%s\n", currentEntry->title);
        printf("%s\n", currentEntry->content);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    // Create a new digital diary
    Entry* head = newEntry();

    // Insert some entries
    insertEntry(head, newEntry());
    insertEntry(head, newEntry());
    insertEntry(head, newEntry());

    // Print all entries
    printEntries(head);

    return 0;
}