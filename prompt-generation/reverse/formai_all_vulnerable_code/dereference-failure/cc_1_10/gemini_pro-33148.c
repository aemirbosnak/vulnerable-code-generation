//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} index_entry_t;

typedef struct {
    index_entry_t *entries;
    int size;
    int capacity;
} index_t;

index_t *index_create() {
    index_t *index = malloc(sizeof(index_t));
    index->entries = malloc(sizeof(index_entry_t) * 10);
    index->size = 0;
    index->capacity = 10;
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
        index->entries = realloc(index->entries, sizeof(index_entry_t) * index->capacity);
    }
    index->entries[index->size].key = strdup(key);
    index->entries[index->size].value = value;
    index->size++;
}

int main() {
    index_t *index = index_create();
    index_put(index, "foo", 1);
    index_put(index, "bar", 2);
    index_put(index, "baz", 3);
    printf("%d\n", index_get(index, "foo"));  // 1
    printf("%d\n", index_get(index, "bar"));  // 2
    printf("%d\n", index_get(index, "baz"));  // 3
    printf("%d\n", index_get(index, "qux"));  // -1
    index_destroy(index);
    return 0;
}