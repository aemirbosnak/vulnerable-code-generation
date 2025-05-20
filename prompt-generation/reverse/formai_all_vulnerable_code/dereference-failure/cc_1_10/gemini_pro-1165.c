//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    void *value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
} Index;

Index *create_index() {
    Index *index = malloc(sizeof(Index));
    index->entries = NULL;
    index->num_entries = 0;
    return index;
}

void destroy_index(Index *index) {
    for (int i = 0; i < index->num_entries; i++) {
        free(index->entries[i].key);
        free(index->entries[i].value);
    }
    free(index->entries);
    free(index);
}

void add_to_index(Index *index, char *key, void *value) {
    index->entries = realloc(index->entries, sizeof(IndexEntry) * (index->num_entries + 1));
    index->entries[index->num_entries].key = strdup(key);
    index->entries[index->num_entries].value = value;
    index->num_entries++;
}

void *get_from_index(Index *index, char *key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return NULL;
}

int main() {
    Index *index = create_index();
    add_to_index(index, "name", "John Doe");
    add_to_index(index, "age", "30");
    add_to_index(index, "city", "New York");

    char *name = get_from_index(index, "name");
    printf("Name: %s\n", name);

    char *age = get_from_index(index, "age");
    printf("Age: %s\n", age);

    char *city = get_from_index(index, "city");
    printf("City: %s\n", city);

    destroy_index(index);
    return 0;
}