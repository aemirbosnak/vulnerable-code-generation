//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    void *value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int size;
} Index;

Index *create_index() {
    Index *index = malloc(sizeof(Index));
    index->entries = NULL;
    index->size = 0;
    return index;
}

void destroy_index(Index *index) {
    for (int i = 0; i < index->size; i++) {
        free(index->entries[i].key);
        free(index->entries[i].value);
    }
    free(index->entries);
    free(index);
}

int add_to_index(Index *index, char *key, void *value) {
    index->entries = realloc(index->entries, (index->size + 1) * sizeof(IndexEntry));
    index->entries[index->size].key = strdup(key);
    index->entries[index->size].value = value;
    index->size++;
    return 0;
}

void *get_from_index(Index *index, char *key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return NULL;
}

int main() {
    Index *index = create_index();
    add_to_index(index, "foo", "bar");
    add_to_index(index, "baz", "qux");
    printf("%s\n", get_from_index(index, "foo"));  // prints "bar"
    printf("%s\n", get_from_index(index, "baz"));  // prints "qux"
    destroy_index(index);
    return 0;
}