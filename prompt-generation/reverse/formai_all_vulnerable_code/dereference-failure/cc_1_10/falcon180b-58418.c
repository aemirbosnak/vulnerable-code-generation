//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INDEX_SIZE 100000

typedef struct {
    char *word;
    int doc_id;
    int freq;
} IndexEntry;

typedef struct {
    IndexEntry *entries;
    int num_entries;
    int max_entries;
} Index;

Index *create_index() {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(MAX_INDEX_SIZE * sizeof(IndexEntry));
    index->num_entries = 0;
    index->max_entries = MAX_INDEX_SIZE;
    return index;
}

void add_entry(Index *index, char *word, int doc_id, int freq) {
    if (index->num_entries >= index->max_entries) {
        printf("Index is full!\n");
        return;
    }
    IndexEntry *entry = &index->entries[index->num_entries];
    entry->word = strdup(word);
    entry->doc_id = doc_id;
    entry->freq = freq;
    index->num_entries++;
}

void search_index(Index *index, char *query) {
    int i;
    for (i = 0; i < index->num_entries; i++) {
        IndexEntry *entry = &index->entries[i];
        if (strcmp(entry->word, query) == 0) {
            printf("Found %d documents with word '%s'\n", entry->freq, query);
        }
    }
}

void destroy_index(Index *index) {
    free(index->entries);
    free(index);
}

int main() {
    Index *index = create_index();
    add_entry(index, "apple", 1, 2);
    add_entry(index, "banana", 2, 1);
    add_entry(index, "cherry", 3, 1);
    search_index(index, "apple");
    destroy_index(index);
    return 0;
}