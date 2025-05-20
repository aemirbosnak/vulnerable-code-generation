//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    int index;
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name) {
    Entry* newNode = malloc(sizeof(Entry));
    strcpy(newNode->name, name);
    newNode->index = head->index + 1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int findEntry(Entry* head, char* name) {
    Entry* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->index;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    Entry* head = NULL;

    insertEntry(head, "John Doe");
    insertEntry(head, "Jane Doe");
    insertEntry(head, "Bill Smith");

    int index = findEntry(head, "Jane Doe");

    if (index != -1) {
        printf("Index of Jane Doe: %d\n", index);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}