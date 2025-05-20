//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    int data_offset;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
} Index;

int compare_keys(const void *a, const void *b) {
    const IndexEntry *entry_a = a;
    const IndexEntry *entry_b = b;

    return strcmp(entry_a->key, entry_b->key);
}

void index_insert(Index *index, const char *key, int data_offset) {
    IndexEntry entry = {.key = strdup(key),.data_offset = data_offset };

    qsort(index->entries, index->num_entries, sizeof(IndexEntry), compare_keys);
    index->entries[index->num_entries++] = entry;
}

int index_search(Index *index, const char *key) {
    IndexEntry *entry = bsearch(key, index->entries, index->num_entries, sizeof(IndexEntry), compare_keys);

    if (entry == NULL) {
        return -1;
    } else {
        return entry->data_offset;
    }
}

void index_destroy(Index *index) {
    for (int i = 0; i < index->num_entries; i++) {
        free(index->entries[i].key);
    }
    free(index->entries);
}

int main() {
    Index index = {.entries = NULL,.num_entries = 0 };

    index_insert(&index, "John", 1);
    index_insert(&index, "Jane", 2);
    index_insert(&index, "Bob", 3);
    index_insert(&index, "Alice", 4);

    int offset = index_search(&index, "Jane");
    printf("Offset for 'Jane': %d\n", offset);

    index_destroy(&index);

    return 0;
}