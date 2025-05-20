//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        IndexEntry *prev = head;
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = newEntry;
    }

    return head;
}

void searchIndex(IndexEntry *head, char *key) {
    IndexEntry *curr = head;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            printf("Key found: %s\n", curr->key);
            return;
        }
        curr = curr->next;
    }

    printf("Key not found: %s\n", key);
}

int main() {
    IndexEntry *head = NULL;

    insertIndexEntry(head, "John Doe");
    insertIndexEntry(head, "Jane Doe");
    insertIndexEntry(head, "Peter Pan");

    searchIndex(head, "Jane Doe");

    return 0;
}