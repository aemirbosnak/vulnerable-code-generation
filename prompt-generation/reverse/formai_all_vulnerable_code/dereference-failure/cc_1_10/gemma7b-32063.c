//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char *key;
    struct IndexEntry *next;
} IndexEntry;

IndexEntry *head = NULL;

void insertIndexEntry(char *key) {
    IndexEntry *newEntry = malloc(sizeof(IndexEntry));
    newEntry->key = strdup(key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry *currentEntry = head;
        while (currentEntry->next) {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

void searchIndexEntry(char *key) {
    IndexEntry *currentEntry = head;
    while (currentEntry) {
        if (strcmp(key, currentEntry->key) == 0) {
            printf("Key: %s\n", currentEntry->key);
            break;
        }
        currentEntry = currentEntry->next;
    }
    if (currentEntry == NULL) {
        printf("Key not found.\n");
    }
}

int main() {
    insertIndexEntry("John Doe");
    insertIndexEntry("Jane Doe");
    insertIndexEntry("Peter Pan");
    insertIndexEntry("Captain Hook");

    searchIndexEntry("Jane Doe");
    searchIndexEntry("Peter Pan");
    searchIndexEntry("Nonsense");

    return 0;
}