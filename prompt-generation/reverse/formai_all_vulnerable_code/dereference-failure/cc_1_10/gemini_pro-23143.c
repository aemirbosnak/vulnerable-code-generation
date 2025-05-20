//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} entry_t;

typedef struct {
    int size;
    int capacity;
    entry_t *entries;
} index_t;

index_t *index_create(int capacity) {
    index_t *index = malloc(sizeof(index_t));
    assert(index != NULL);

    index->size = 0;
    index->capacity = capacity;
    index->entries = malloc(sizeof(entry_t) * capacity);
    assert(index->entries != NULL);

    return index;
}

void index_destroy(index_t *index) {
    free(index->entries);
    free(index);
}

int index_get(index_t *index, char *key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }

    return -1;
}

void index_put(index_t *index, char *key, int value) {
    if (index->size == index->capacity) {
        index->capacity *= 2;
        index->entries = realloc(index->entries, sizeof(entry_t) * index->capacity);
        assert(index->entries != NULL);
    }

    index->entries[index->size].key = strdup(key);
    index->entries[index->size].value = value;
    index->size++;
}

void index_print(index_t *index) {
    for (int i = 0; i < index->size; i++) {
        printf("%s: %d\n", index->entries[i].key, index->entries[i].value);
    }
}

int main() {
    index_t *index = index_create(16);

    index_put(index, "foo", 1);
    index_put(index, "bar", 2);
    index_put(index, "baz", 3);

    assert(index_get(index, "foo") == 1);
    assert(index_get(index, "bar") == 2);
    assert(index_get(index, "baz") == 3);

    index_print(index);

    index_destroy(index);

    return 0;
}