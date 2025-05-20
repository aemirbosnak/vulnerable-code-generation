//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 1000

struct IndexEntry {
    char* key;
    char* value;
};

typedef struct IndexEntry IndexEntry;

typedef struct IndexIndex {
    IndexEntry entries[MAX_INDEX_SIZE];
    int count;
} IndexIndex;

IndexIndex* createIndex() {
    IndexIndex* index = (IndexIndex*)malloc(sizeof(IndexIndex));
    index->count = 0;
    return index;
}

void addEntry(IndexIndex* index, char* key, char* value) {
    IndexEntry entry = { key, value };
    if (index->count >= MAX_INDEX_SIZE) {
        fprintf(stderr, "Index is full\n");
        return;
    }
    index->entries[index->count++] = entry;
}

void printIndex(IndexIndex* index) {
    for (int i = 0; i < index->count; i++) {
        IndexEntry entry = index->entries[i];
        printf("%s => %s\n", entry.key, entry.value);
    }
}

int main() {
    IndexIndex* index = createIndex();
    
    addEntry(index, "name", "John");
    addEntry(index, "age", "25");
    addEntry(index, "city", "New York");
    addEntry(index, "country", "USA");

    printIndex(index);
    
    free(index);
    
    return 0;
}