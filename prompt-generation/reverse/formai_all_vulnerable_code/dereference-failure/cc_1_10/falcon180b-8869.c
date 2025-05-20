//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} IndexEntry;

typedef struct {
    int size;
    IndexEntry *entries;
} Index;

Index *createIndex() {
    Index *index = (Index *) malloc(sizeof(Index));
    index->size = 0;
    index->entries = (IndexEntry *) malloc(MAX_KEY_SIZE * sizeof(IndexEntry));
    return index;
}

void destroyIndex(Index *index) {
    free(index->entries);
    free(index);
}

int addEntry(Index *index, char *key, int value) {
    int i = index->size;
    while (i > 0 && strcmp(index->entries[i-1].key, key) > 0) {
        index->entries[i] = index->entries[i-1];
        i--;
    }
    strcpy(index->entries[i].key, key);
    index->entries[i].value = value;
    index->size++;
    return i;
}

int searchEntry(Index *index, char *key) {
    int i = 0;
    while (i < index->size && strcmp(index->entries[i].key, key) < 0) {
        i++;
    }
    if (i < index->size && strcmp(index->entries[i].key, key) == 0) {
        return i;
    }
    return -1;
}

int main() {
    Index *index = createIndex();
    addEntry(index, "apple", 1);
    addEntry(index, "banana", 2);
    addEntry(index, "cherry", 3);
    int index1 = searchEntry(index, "banana");
    int index2 = searchEntry(index, "grape");
    printf("Index of banana: %d\n", index1);
    printf("Index of grape: %d\n", index2);
    destroyIndex(index);
    return 0;
}