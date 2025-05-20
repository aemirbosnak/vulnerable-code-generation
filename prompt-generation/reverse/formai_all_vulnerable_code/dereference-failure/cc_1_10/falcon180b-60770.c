//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
    int size;
} Index;

void init_index(Index *index) {
    index->entries = NULL;
    index->num_entries = 0;
    index->size = 0;
}

void add_entry(Index *index, char *key, int value) {
    IndexEntry *entry = malloc(sizeof(IndexEntry));
    entry->key = strdup(key);
    entry->value = value;

    if (index->num_entries == index->size) {
        index->size *= 2;
        index->entries = realloc(index->entries, index->size * sizeof(IndexEntry));
    }

    index->entries[index->num_entries++] = *entry;
}

int search_index(Index *index, char *key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }

    return -1;
}

void print_index(Index *index) {
    for (int i = 0; i < index->num_entries; i++) {
        printf("%s: %d\n", index->entries[i].key, index->entries[i].value);
    }
}

int main() {
    Index index;
    init_index(&index);

    add_entry(&index, "apple", 1);
    add_entry(&index, "banana", 2);
    add_entry(&index, "cherry", 3);

    print_index(&index);

    int value = search_index(&index, "banana");
    printf("Value for 'banana': %d\n", value);

    return 0;
}