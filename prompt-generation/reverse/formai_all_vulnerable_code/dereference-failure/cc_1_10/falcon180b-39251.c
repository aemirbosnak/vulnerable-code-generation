//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *key;
    int value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int capacity;
    int size;
} Index;

Index *index_create(int capacity) {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(capacity * sizeof(IndexEntry));
    index->capacity = capacity;
    index->size = 0;
    return index;
}

void index_destroy(Index *index) {
    for (int i = 0; i < index->size; i++) {
        free(index->entries[i].key);
    }
    free(index->entries);
    free(index);
}

bool index_insert(Index *index, char *key, int value) {
    if (index->size >= index->capacity) {
        return false;
    }
    index->entries[index->size].key = strdup(key);
    index->entries[index->size].value = value;
    index->size++;
    return true;
}

int index_search(Index *index, char *key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return -1;
}

void index_print(Index *index) {
    for (int i = 0; i < index->size; i++) {
        printf("%s -> %d\n", index->entries[i].key, index->entries[i].value);
    }
}

int main() {
    Index *index = index_create(10);
    index_insert(index, "apple", 1);
    index_insert(index, "banana", 2);
    index_insert(index, "cherry", 3);
    index_print(index);
    int value = index_search(index, "apple");
    printf("Value of apple: %d\n", value);
    index_destroy(index);
    return 0;
}