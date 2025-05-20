//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int key;
    char *value;
} IndexEntry;

typedef struct {
    int size;
    IndexEntry *entries;
} Index;

Index *create_index(int size) {
    Index *index = malloc(sizeof(Index));
    index->size = size;
    index->entries = malloc(sizeof(IndexEntry) * size);
    return index;
}

void destroy_index(Index *index) {
    free(index->entries);
    free(index);
}

void insert_into_index(Index *index, int key, char *value) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            free(index->entries[i].value);
            break;
        }
    }
    index->entries[i].key = key;
    index->entries[i].value = strdup(value);
}

char *get_from_index(Index *index, int key) {
    int i;
    for (i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            return index->entries[i].value;
        }
    }
    return NULL;
}

void print_index(Index *index) {
    int i;
    for (i = 0; i < index->size; i++) {
        printf("%d: %s\n", index->entries[i].key, index->entries[i].value);
    }
}

int main() {
    Index *index = create_index(10);
    insert_into_index(index, 1, "one");
    insert_into_index(index, 2, "two");
    insert_into_index(index, 3, "three");
    print_index(index);
    printf("%s\n", get_from_index(index, 2));
    destroy_index(index);
    return 0;
}