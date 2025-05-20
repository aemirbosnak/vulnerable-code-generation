//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char name[256];
    struct Entry* next;
} Entry;

typedef struct Index {
    int key;
    Entry* entries;
} Index;

Index* createIndex(int key) {
    Index* index = malloc(sizeof(Index));
    index->key = key;
    index->entries = NULL;
    return index;
}

void addEntry(Index* index, char* name) {
    Entry* entry = malloc(sizeof(Entry));
    strcpy(entry->name, name);
    entry->next = index->entries;
    index->entries = entry;
}

Entry* findEntry(Index* index, char* name) {
    for (Entry* entry = index->entries; entry; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
    }
    return NULL;
}

int main() {
    Index* index = createIndex(12);
    addEntry(index, "John Doe");
    addEntry(index, "Jane Doe");
    addEntry(index, "Peter Pan");

    Entry* entry = findEntry(index, "Jane Doe");
    if (entry) {
        printf("Found entry: %s\n", entry->name);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}