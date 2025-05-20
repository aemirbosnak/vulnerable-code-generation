//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX_ENTRIES 1024
#define INDEX_ENTIRY_SIZE 512

struct IndexEntry {
    char data[INDEX_ENTIRY_SIZE];
    struct IndexEntry* next;
};

struct Index {
    struct IndexEntry* head;
    int size;
    int capacity;
};

struct Index* createIndex(int capacity) {
    struct Index* index = malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    index->capacity = capacity;

    return index;
}

void insertIndexEntry(struct Index* index, char* data) {
    struct IndexEntry* newEntry = malloc(sizeof(struct IndexEntry));
    strcpy(newEntry->data, data);

    if (index->head == NULL) {
        index->head = newEntry;
    } else {
        index->head->next = newEntry;
    }

    index->size++;
}

char* searchIndexEntry(struct Index* index, char* key) {
    struct IndexEntry* currentEntry = index->head;

    while (currentEntry) {
        if (strcmp(currentEntry->data, key) == 0) {
            return currentEntry->data;
        }

        currentEntry = currentEntry->next;
    }

    return NULL;
}

int main() {
    struct Index* index = createIndex(MAX_INDEX_ENTRIES);

    insertIndexEntry(index, "John Doe");
    insertIndexEntry(index, "Jane Doe");
    insertIndexEntry(index, "Bill Smith");

    char* result = searchIndexEntry(index, "Jane Doe");

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found.\n");
    }

    return 0;
}