//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
    char key[20];
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char* key) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

int searchIndexEntry(IndexEntry* head, char* key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    IndexEntry* indexHead = NULL;
    indexHead = insertIndexEntry(indexHead, "John Doe");
    indexHead = insertIndexEntry(indexHead, "Jane Doe");
    indexHead = insertIndexEntry(indexHead, "Bill Smith");

    if (searchIndexEntry(indexHead, "John Doe")) {
        printf("John Doe is in the index.\n");
    }

    if (searchIndexEntry(indexHead, "Jane Doe")) {
        printf("Jane Doe is in the index.\n");
    }

    return 0;
}