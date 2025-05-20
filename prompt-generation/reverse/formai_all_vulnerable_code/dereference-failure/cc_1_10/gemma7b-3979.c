//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
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

int searchIndexEntry(IndexEntry *head, char *key) {
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
    index = insertIndexEntry(index, "Peter Pan");

    if (searchIndexEntry(index, "Jane Doe")) {
        printf("Jane Doe is in the index.\n");
    }

    if (searchIndexEntry(index, "Bob Smith")) {
        printf("Bob Smith is not in the index.\n");
    }

    return 0;
}