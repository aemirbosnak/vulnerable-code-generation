//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
    char name[50];
    struct Entry* next;
} Entry;

Entry* head = NULL;

void insertEntry(char* name) {
    Entry* newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        Entry* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

void searchEntry(char* name) {
    Entry* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Entry found: %s\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Entry not found.\n");
}

int main() {
    insertEntry("Alice");
    insertEntry("Bob");
    insertEntry("Charlie");
    insertEntry("Dave");

    searchEntry("Bob");
    searchEntry("Fred");

    return 0;
}