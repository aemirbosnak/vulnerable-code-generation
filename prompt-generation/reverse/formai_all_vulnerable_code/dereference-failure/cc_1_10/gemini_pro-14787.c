//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char *key;
    uint64_t value;
} entry_t;

typedef struct {
    entry_t *entries;
    size_t size;
    size_t capacity;
} index_t;

index_t *index_create() {
    index_t *index = malloc(sizeof(index_t));
    if (index == NULL) {
        return NULL;
    }
    index->entries = NULL;
    index->size = 0;
    index->capacity = 0;
    return index;
}

void index_destroy(index_t *index) {
    if (index == NULL) {
        return;
    }
    for (size_t i = 0; i < index->size; i++) {
        free(index->entries[i].key);
    }
    free(index->entries);
    free(index);
}

int index_insert(index_t *index, const char *key, uint64_t value) {
    if (index == NULL || key == NULL) {
        return -1;
    }
    if (index->size == index->capacity) {
        size_t new_capacity = index->capacity == 0 ? 16 : index->capacity * 2;
        entry_t *new_entries = realloc(index->entries, new_capacity * sizeof(entry_t));
        if (new_entries == NULL) {
            return -1;
        }
        index->entries = new_entries;
        index->capacity = new_capacity;
    }
    index->entries[index->size].key = strdup(key);
    if (index->entries[index->size].key == NULL) {
        return -1;
    }
    index->entries[index->size].value = value;
    index->size++;
    return 0;
}

int index_search(index_t *index, const char *key, uint64_t *value) {
    if (index == NULL || key == NULL || value == NULL) {
        return -1;
    }
    for (size_t i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            *value = index->entries[i].value;
            return 0;
        }
    }
    return -1;
}

int main() {
    index_t *index = index_create();
    if (index == NULL) {
        fprintf(stderr, "Could not create index\n");
        return EXIT_FAILURE;
    }
    if (index_insert(index, "foo", 1) != 0) {
        fprintf(stderr, "Could not insert into index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    if (index_insert(index, "bar", 2) != 0) {
        fprintf(stderr, "Could not insert into index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    if (index_insert(index, "baz", 3) != 0) {
        fprintf(stderr, "Could not insert into index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    uint64_t value;
    if (index_search(index, "foo", &value) != 0) {
        fprintf(stderr, "Could not search index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    printf("Found foo: %lu\n", value);
    if (index_search(index, "bar", &value) != 0) {
        fprintf(stderr, "Could not search index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    printf("Found bar: %lu\n", value);
    if (index_search(index, "baz", &value) != 0) {
        fprintf(stderr, "Could not search index\n");
        index_destroy(index);
        return EXIT_FAILURE;
    }
    printf("Found baz: %lu\n", value);
    index_destroy(index);
    return EXIT_SUCCESS;
}