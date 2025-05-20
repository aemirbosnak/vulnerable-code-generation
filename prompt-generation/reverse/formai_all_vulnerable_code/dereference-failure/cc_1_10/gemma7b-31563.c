//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 10

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
        IndexEntry *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newEntry;
    }

    return head;
}

int searchIndex(IndexEntry *head, char *key) {
    IndexEntry *traverse = head;
    while (traverse) {
        if (strcmp(traverse->key, key) == 0) {
            return 1;
        }
        traverse = traverse->next;
    }

    return 0;
}

int main() {
    IndexEntry *index = NULL;
    index = insertIndexEntry(index, "John Doe");
    index = insertIndexEntry(index, "Jane Doe");
    index = insertIndexEntry(index, "Jack Doe");

    if (searchIndex(index, "John Doe") == 1) {
        printf("John Doe is in the index.\n");
    }

    if (searchIndex(index, "Jane Doe") == 1) {
        printf("Jane Doe is in the index.\n");
    }

    if (searchIndex(index, "Jack Doe") == 1) {
        printf("Jack Doe is in the index.\n");
    }

    return 0;
}