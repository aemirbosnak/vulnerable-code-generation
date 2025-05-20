//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char name[255];
    int index;
    struct Entry* next;
} Entry;

Entry* head = NULL;

void insertEntry(char* name) {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->index = head ? head->index + 1 : 0;
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (head) {
        head->next = newEntry;
    } else {
        head = newEntry;
    }
}

int searchEntry(char* name) {
    Entry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->name, name) == 0) {
            return currentEntry->index;
        }
        currentEntry = currentEntry->next;
    }

    return -1;
}

int main() {
    insertEntry("John Doe");
    insertEntry("Jane Doe");
    insertEntry("Jack Doe");
    insertEntry("Jill Doe");

    int index = searchEntry("Jane Doe");

    if (index != -1) {
        printf("Index of Jane Doe: %d\n", index);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}