//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_TABLES 10
#define MAX_INDEX_ENTRIES 100

typedef struct Table {
    char **entries;
    int num_entries;
    pthread_mutex_t mutex;
} Table;

Table tables[MAX_TABLES];

void initialize_table(int table_id) {
    tables[table_id].entries = (char **)malloc(MAX_INDEX_ENTRIES * sizeof(char *));
    tables[table_id].num_entries = 0;
    pthread_mutex_init(&tables[table_id].mutex, NULL);
}

void insert_index_entry(int table_id, char *entry) {
    pthread_mutex_lock(&tables[table_id].mutex);
    tables[table_id].entries[tables[table_id].num_entries++] = entry;
    pthread_mutex_unlock(&tables[table_id].mutex);
}

char *search_index_entry(int table_id, char *key) {
    for (int i = 0; i < tables[table_id].num_entries; i++) {
        if (strcmp(tables[table_id].entries[i], key) == 0) {
            return tables[table_id].entries[i];
        }
    }

    return NULL;
}

int main() {
    initialize_table(0);
    insert_index_entry(0, "John Doe");
    insert_index_entry(0, "Jane Doe");
    insert_index_entry(0, "Peter Pan");

    char *entry = search_index_entry(0, "Jane Doe");

    if (entry) {
        printf("%s\n", entry);
    } else {
        printf("Entry not found\n");
    }

    return 0;
}