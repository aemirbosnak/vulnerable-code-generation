//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INDEX_SIZE 1000000
#define MAX_INDEX_ENTRY_SIZE 10000

typedef struct {
    int key;
    int value;
} IndexEntry;

typedef struct {
    int size;
    int capacity;
    IndexEntry *entries;
} Index;

Index *newIndex() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->size = 0;
    index->capacity = MAX_INDEX_ENTRY_SIZE;
    index->entries = (IndexEntry *)malloc(index->capacity * sizeof(IndexEntry));
    return index;
}

void addIndexEntry(Index *index, int key, int value) {
    if (index->size >= index->capacity) {
        index->capacity *= 2;
        index->entries = (IndexEntry *)realloc(index->entries, index->capacity * sizeof(IndexEntry));
    }
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            index->entries[i].value = value;
            return;
        }
    }
    index->entries[index->size].key = key;
    index->entries[index->size].value = value;
    index->size++;
}

int getIndexValue(Index *index, int key) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            return index->entries[i].value;
        }
    }
    return -1;
}

int main() {
    Index *index = newIndex();
    addIndexEntry(index, 1, 10);
    addIndexEntry(index, 2, 20);
    addIndexEntry(index, 3, 30);
    int value = getIndexValue(index, 2);
    printf("%d\n", value);
    return 0;
}