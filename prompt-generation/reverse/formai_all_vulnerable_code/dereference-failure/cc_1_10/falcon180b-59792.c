//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10000
#define MAX_ENTRY_SIZE 100
#define MAX_INDEX_SIZE 1000

typedef struct {
    char *key;
    int value;
} entry_t;

typedef struct {
    entry_t *entries;
    int num_entries;
} index_t;

void init_index(index_t *index) {
    index->entries = (entry_t *)malloc(MAX_ENTRIES * sizeof(entry_t));
    index->num_entries = 0;
}

void add_entry(index_t *index, char *key, int value) {
    if (index->num_entries >= MAX_ENTRIES) {
        printf("Error: index is full\n");
        return;
    }
    entry_t *entry = &index->entries[index->num_entries];
    strncpy(entry->key, key, MAX_ENTRY_SIZE);
    entry->value = value;
    index->num_entries++;
}

int search_index(index_t *index, char *key) {
    int i;
    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return -1; // key not found
}

void print_index(index_t *index) {
    int i;
    for (i = 0; i < index->num_entries; i++) {
        printf("%s -> %d\n", index->entries[i].key, index->entries[i].value);
    }
}

int main() {
    index_t index;
    init_index(&index);

    add_entry(&index, "apple", 1);
    add_entry(&index, "banana", 2);
    add_entry(&index, "cherry", 3);

    print_index(&index);

    int value = search_index(&index, "banana");
    printf("Value of banana: %d\n", value);

    return 0;
}