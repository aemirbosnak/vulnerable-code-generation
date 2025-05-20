//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int size;
    int capacity;
} Index;

Index *create_index(int capacity) {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(sizeof(Entry) * capacity);
    index->size = 0;
    index->capacity = capacity;
    return index;
}

void destroy_index(Index *index) {
    free(index->entries);
    free(index);
}

int find_index(Index *index, char *key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

void insert_index(Index *index, char *key, int value) {
    if (index->size == index->capacity) {
        index->entries = realloc(index->entries, sizeof(Entry) * index->capacity * 2);
        index->capacity *= 2;
    }
    index->entries[index->size].key = malloc(strlen(key) + 1);
    strcpy(index->entries[index->size].key, key);
    index->entries[index->size].value = value;
    index->size++;
}

int main() {
    Index *index = create_index(10);
    insert_index(index, "key1", 1);
    insert_index(index, "key2", 2);
    insert_index(index, "key3", 3);
    int value = find_index(index, "key2");
    printf("Value for key2: %d\n", value);
    destroy_index(index);
    return 0;
}