//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char *key;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry **createIndex(char *key) {
    IndexEntry **head = (IndexEntry **)malloc(sizeof(IndexEntry *) * MAX_INDEX_ENTRIES);
    IndexEntry *newEntry = (IndexEntry *)malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;
    *head = newEntry;
    return head;
}

void addIndexEntry(IndexEntry **head, char *key) {
    IndexEntry *newEntry = (IndexEntry *)malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        IndexEntry *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }
}

int searchIndex(IndexEntry **head, char *key) {
    IndexEntry *current = *head;
    while (current) {
        if (strcmp(key, current->key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    IndexEntry **index = createIndex("John");
    addIndexEntry(index, "Mary");
    addIndexEntry(index, "Bob");

    if (searchIndex(index, "Mary") == 1) {
        printf("Mary is in the index.\n");
    }

    return 0;
}