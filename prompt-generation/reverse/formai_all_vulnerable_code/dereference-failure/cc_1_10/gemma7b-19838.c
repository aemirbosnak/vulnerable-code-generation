//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 255

typedef struct Entry {
    char data[MAX_ENTRY_LEN];
    struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* data) {
    Entry* newEntry = malloc(sizeof(Entry));
    newEntry->next = NULL;
    strcpy(newEntry->data, data);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

Entry* findEntry(Entry* head, char* data) {
    Entry* currentEntry = head;

    while (currentEntry) {
        if (strcmp(currentEntry->data, data) == 0) {
            return currentEntry;
        }

        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    Entry* head = NULL;

    insertEntry(head, "Secret Message");
    insertEntry(head, "Another Secret");
    insertEntry(head, "This is a secret message too");

    Entry* foundEntry = findEntry(head, "Another Secret");

    if (foundEntry) {
        printf("Found entry: %s", foundEntry->data);
    } else {
        printf("Entry not found");
    }

    return 0;
}