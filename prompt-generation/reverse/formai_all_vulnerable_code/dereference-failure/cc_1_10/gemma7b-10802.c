//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 255

typedef struct Entry {
    char name[MAX_NAME_LENGTH];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (head == NULL) {
        return newEntry;
    }

    head->next = insertEntry(head->next, name);
    return head;
}

Entry* searchEntry(Entry* head, char* name) {
    Entry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    Entry* head = NULL;

    // Insert some entries
    insertEntry(head, "John Doe");
    insertEntry(head, "Jane Doe");
    insertEntry(head, "Peter Pan");

    // Search for an entry
    Entry* entry = searchEntry(head, "Jane Doe");

    // Print the entry
    if (entry) {
        printf("Name: %s\n", entry->name);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}