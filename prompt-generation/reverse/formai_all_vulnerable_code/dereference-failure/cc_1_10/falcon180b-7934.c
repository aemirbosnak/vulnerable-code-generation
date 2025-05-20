//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 50
#define MAX_ENTRIES 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} entry_t;

typedef struct {
    entry_t *entries;
    int num_entries;
} index_t;

index_t *create_index() {
    index_t *index = (index_t *) malloc(sizeof(index_t));
    index->entries = (entry_t *) malloc(MAX_ENTRIES * sizeof(entry_t));
    index->num_entries = 0;
    return index;
}

void destroy_index(index_t *index) {
    free(index->entries);
    free(index);
}

void add_entry(index_t *index, char *key, int value) {
    if (index->num_entries >= MAX_ENTRIES) {
        printf("Index is full\n");
        return;
    }

    strcpy(index->entries[index->num_entries].key, key);
    index->entries[index->num_entries].value = value;
    index->num_entries++;
}

int search_index(index_t *index, char *key) {
    int i;

    for (i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }

    return -1;
}

int main() {
    index_t *index = create_index();

    add_entry(index, "apple", 10);
    add_entry(index, "banana", 20);
    add_entry(index, "orange", 30);

    int value = search_index(index, "banana");
    printf("Value for banana: %d\n", value);

    destroy_index(index);

    return 0;
}