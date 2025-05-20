//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10000
#define MAX_KEY_SIZE 100

typedef struct {
    char *key;
    int index;
} Index;

typedef struct {
    Index *index;
    int size;
} IndexTable;

IndexTable *create_index_table() {
    IndexTable *table = malloc(sizeof(IndexTable));
    table->index = malloc(MAX_INDEX_SIZE * sizeof(Index));
    table->size = 0;
    return table;
}

void destroy_index_table(IndexTable *table) {
    free(table->index);
    free(table);
}

int add_index(IndexTable *table, char *key) {
    if (table->size >= MAX_INDEX_SIZE) {
        printf("Error: Index table is full.\n");
        return -1;
    }

    Index *index = &table->index[table->size];
    strncpy(index->key, key, MAX_KEY_SIZE);
    index->key[MAX_KEY_SIZE-1] = '\0';
    index->index = table->size;

    table->size++;

    return index->index;
}

int search_index(IndexTable *table, char *key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->index[i].key, key) == 0) {
            return table->index[i].index;
        }
    }

    return -1;
}

int main() {
    IndexTable *table = create_index_table();

    add_index(table, "John");
    add_index(table, "Jane");
    add_index(table, "Mike");

    int index = search_index(table, "John");
    if (index!= -1) {
        printf("Found index: %d\n", index);
    } else {
        printf("Not found.\n");
    }

    destroy_index_table(table);

    return 0;
}