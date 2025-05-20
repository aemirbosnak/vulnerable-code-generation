//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
// Ada Lovelace's C Database Indexing System

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define data structures
typedef struct {
    char* key;
    char* value;
} Entry;

typedef struct {
    int size;
    Entry* entries;
} Index;

// Initialize the index
Index initializeIndex(int size) {
    Index index;
    index.size = size;
    index.entries = malloc(index.size * sizeof(Entry));
    return index;
}

// Insert an entry into the index
void insertEntry(Index* index, char* key, char* value) {
    Entry entry;
    strcpy(entry.key, key);
    strcpy(entry.value, value);
    index->entries[index->size - 1] = entry;
    index->size++;
}

// Search for an entry in the index
Entry* searchEntry(Index* index, char* key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return &(index->entries[i]);
        }
    }
    return NULL;
}

// Free the memory allocated for the index
void freeIndex(Index* index) {
    free(index->entries);
    index->entries = NULL;
}

// Main function
int main() {
    Index index = initializeIndex(5);
    insertEntry(&index, "name", "John");
    insertEntry(&index, "age", "30");
    insertEntry(&index, "gender", "Male");
    insertEntry(&index, "email", "john@example.com");
    insertEntry(&index, "phone", "1234567890");

    Entry* entry = searchEntry(&index, "email");
    if (entry!= NULL) {
        printf("Email: %s\n", entry->value);
    } else {
        printf("Entry not found!\n");
    }

    freeIndex(&index);
    return 0;
}