//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int value;
} IndexEntry;

typedef struct {
    int numEntries;
    IndexEntry *entries;
} Index;

Index *createIndex(int numEntries) {
    Index *index = (Index *)malloc(sizeof(Index));
    index->numEntries = numEntries;
    index->entries = (IndexEntry *)malloc(sizeof(IndexEntry) * numEntries);
    for (int i = 0; i < numEntries; i++) {
        index->entries[i].key = 0;
        index->entries[i].value = 0;
    }
    return index;
}

void addEntry(Index *index, int key, int value) {
    for (int i = 0; i < index->numEntries; i++) {
        if (index->entries[i].key == key) {
            index->entries[i].value = value;
            return;
        }
    }
    index->entries[index->numEntries - 1].key = key;
    index->entries[index->numEntries - 1].value = value;
    index->numEntries++;
}

int searchIndex(Index *index, int key) {
    for (int i = 0; i < index->numEntries; i++) {
        if (index->entries[i].key == key) {
            return index->entries[i].value;
        }
    }
    return -1;
}

void destroyIndex(Index *index) {
    free(index->entries);
    free(index);
}

int main() {
    Index *index = createIndex(10);
    addEntry(index, 1, 10);
    addEntry(index, 2, 20);
    addEntry(index, 3, 30);
    addEntry(index, 4, 40);
    addEntry(index, 5, 50);
    int value = searchIndex(index, 2);
    printf("%d\n", value);
    destroyIndex(index);
    return 0;
}