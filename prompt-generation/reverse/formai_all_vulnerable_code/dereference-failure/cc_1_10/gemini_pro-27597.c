//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int size;
    int capacity;
} Index;

Index *createIndex() {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(sizeof(IndexEntry) * 10);
    index->size = 0;
    index->capacity = 10;
    return index;
}

void insertIndex(Index *index, char *key, int value) {
    if (index->size == index->capacity) {
        index->entries = realloc(index->entries, sizeof(IndexEntry) * index->capacity * 2);
        index->capacity *= 2;
    }

    index->entries[index->size].key = malloc(strlen(key) + 1);
    strcpy(index->entries[index->size].key, key);
    index->entries[index->size].value = value;
    index->size++;
}

int findIndex(Index *index, char *key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }

    return -1;
}

void printIndex(Index *index) {
    for (int i = 0; i < index->size; i++) {
        printf("%s: %d\n", index->entries[i].key, index->entries[i].value);
    }
}

void freeIndex(Index *index) {
    for (int i = 0; i < index->size; i++) {
        free(index->entries[i].key);
    }

    free(index->entries);
    free(index);
}

int main() {
    Index *index = createIndex();

    insertIndex(index, "foo", 1);
    insertIndex(index, "bar", 2);
    insertIndex(index, "baz", 3);

    printIndex(index);

    int value = findIndex(index, "bar");
    printf("The value of 'bar' is: %d\n", value);

    freeIndex(index);

    return 0;
}