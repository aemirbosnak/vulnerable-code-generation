//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure for representing an index entry
typedef struct IndexEntry {
    int key;
    int offset;
} IndexEntry;

// Custom data structure for representing an index
typedef struct Index {
    IndexEntry *entries;
    int capacity;
    int size;
} Index;

// Function to create a new index
Index *create_index() {
    Index *index = malloc(sizeof(Index));
    index->entries = malloc(sizeof(IndexEntry) * 100);
    index->capacity = 100;
    index->size = 0;
    return index;
}

// Function to add an entry to an index
void add_index_entry(Index *index, int key, int offset) {
    if (index->size == index->capacity) {
        index->capacity *= 2;
        index->entries = realloc(index->entries, sizeof(IndexEntry) * index->capacity);
    }
    index->entries[index->size].key = key;
    index->entries[index->size].offset = offset;
    index->size++;
}

// Function to search for a key in an index
int search_index(Index *index, int key) {
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            return index->entries[i].offset;
        }
    }
    return -1;
}

// Function to print the contents of an index
void print_index(Index *index) {
    for (int i = 0; i < index->size; i++) {
        printf("{%d, %d}\n", index->entries[i].key, index->entries[i].offset);
    }
}

// Function to test the indexing system
int main() {
    // Create a new index
    Index *index = create_index();

    // Add some entries to the index
    add_index_entry(index, 1, 10);
    add_index_entry(index, 2, 20);
    add_index_entry(index, 3, 30);

    // Print the contents of the index
    printf("Index:\n");
    print_index(index);

    // Search for a key in the index
    printf("Searching for key 2...\n");
    int offset = search_index(index, 2);
    if (offset == -1) {
        printf("Key not found.\n");
    } else {
        printf("Key found at offset %d.\n", offset);
    }

    // Free the memory used by the index
    free(index->entries);
    free(index);

    return 0;
}