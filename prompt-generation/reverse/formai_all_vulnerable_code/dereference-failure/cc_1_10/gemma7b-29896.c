//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

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
        IndexEntry *traversal = head;
        while (traversal->next) {
            traversal = traversal->next;
        }
        traversal->next = newEntry;
    }

    return head;
}

void searchIndexEntry(IndexEntry *head, char *key) {
    IndexEntry *traversal = head;
    while (traversal) {
        if (strcmp(traversal->key, key) == 0) {
            printf("Key: %s, Found!\n", traversal->key);
            return;
        }
        traversal = traversal->next;
    }

    printf("Key: %s, Not Found!\n", key);
}

int main() {
    IndexEntry *head = NULL;
    head = insertIndexEntry(head, "John");
    head = insertIndexEntry(head, "Mary");
    head = insertIndexEntry(head, "Bob");
    head = insertIndexEntry(head, "Alice");

    searchIndexEntry(head, "Mary");
    searchIndexEntry(head, "Bob");
    searchIndexEntry(head, "Tom");

    return 0;
}