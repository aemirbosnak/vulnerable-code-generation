//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
    char *key;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *insertIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry *current = head;
        IndexEntry *previous = NULL;
        while (current) {
            if (strcmp(current->key, key) == 0) {
                return NULL;
            } else if (previous) {
                previous = current;
                current = current->next;
            } else {
                previous = current;
                current = current->next;
            }
        }

        previous->next = newEntry;
    }

    return head;
}

void searchIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Key found: %s\n", current->key);
            return;
        }
        current = current->next;
    }

    printf("Key not found: %s\n", key);
}

int main() {
    IndexEntry *head = NULL;

    // Insert some index entries
    insertIndexEntry(head, "John Doe");
    insertIndexEntry(head, "Jane Doe");
    insertIndexEntry(head, "Bill Smith");

    // Search for a key
    searchIndexEntry(head, "Jane Doe");

    return 0;
}