//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_ELEMENTS 100
#define MAX_ELEMENT_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char element[MAX_ELEMENT_LENGTH];
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int numEntries;
} Index;

Index *indexCreate() {
    Index *index = (Index *) malloc(sizeof(Index));
    index->entries = (IndexEntry *) malloc(MAX_ELEMENTS * sizeof(IndexEntry));
    index->numEntries = 0;
    return index;
}

void indexAddEntry(Index *index, char *key, char *element) {
    if (index->numEntries >= MAX_ELEMENTS) {
        printf("Error: Index is full.\n");
        return;
    }
    strncpy(index->entries[index->numEntries].key, key, MAX_KEY_LENGTH);
    strncpy(index->entries[index->numEntries].element, element, MAX_ELEMENT_LENGTH);
    index->numEntries++;
}

void indexPrint(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->numEntries; i++) {
        printf("Key: %s, Element: %s\n", index->entries[i].key, index->entries[i].element);
    }
}

void indexDelete(Index *index, char *key) {
    for (int i = 0; i < index->numEntries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            for (int j = i; j < index->numEntries - 1; j++) {
                strcpy(index->entries[j].key, index->entries[j + 1].key);
                strcpy(index->entries[j].element, index->entries[j + 1].element);
            }
            index->numEntries--;
            break;
        }
    }
}

int main() {
    Index *index = indexCreate();
    indexAddEntry(index, "apple", "red");
    indexAddEntry(index, "banana", "yellow");
    indexAddEntry(index, "cherry", "red");
    indexPrint(index);
    indexDelete(index, "banana");
    indexPrint(index);
    free(index->entries);
    free(index);
    return 0;
}