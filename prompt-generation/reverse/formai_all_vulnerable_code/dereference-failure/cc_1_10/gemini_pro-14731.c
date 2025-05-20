//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Index entry structure
typedef struct index_entry {
    char *key;
    uint64_t offset;
} index_entry_t;

// Index structure
typedef struct index {
    index_entry_t *entries;
    uint64_t size;
} index_t;

// Create a new index
index_t *index_new() {
    index_t *index = malloc(sizeof(index_t));
    index->entries = NULL;
    index->size = 0;
    return index;
}

// Destroy an index
void index_destroy(index_t *index) {
    if (index->entries != NULL) {
        for (uint64_t i = 0; i < index->size; i++) {
            free(index->entries[i].key);
        }
        free(index->entries);
    }
    free(index);
}

// Insert a new entry into the index
void index_insert(index_t *index, char *key, uint64_t offset) {
    // Allocate memory for the new entry
    index->entries = realloc(index->entries, (index->size + 1) * sizeof(index_entry_t));

    // Initialize the new entry
    index->entries[index->size].key = strdup(key);
    index->entries[index->size].offset = offset;

    // Increment the size of the index
    index->size++;
}

// Search for an entry in the index
uint64_t index_search(index_t *index, char *key) {
    // Iterate over the entries in the index
    for (uint64_t i = 0; i < index->size; i++) {
        // Compare the key to the key in the entry
        if (strcmp(key, index->entries[i].key) == 0) {
            // Return the offset of the entry
            return index->entries[i].offset;
        }
    }

    // Return -1 if the key was not found
    return -1;
}

// Print the index
void index_print(index_t *index) {
    // Iterate over the entries in the index
    for (uint64_t i = 0; i < index->size; i++) {
        // Print the key and offset of the entry
        printf("%s: %llu\n", index->entries[i].key, index->entries[i].offset);
    }
}

// Main function
int main() {
    // Create a new index
    index_t *index = index_new();

    // Insert some entries into the index
    index_insert(index, "Alice", 10);
    index_insert(index, "Bob", 20);
    index_insert(index, "Carol", 30);

    // Print the index
    index_print(index);

    // Search for an entry in the index
    uint64_t offset = index_search(index, "Alice");
    if (offset != -1) {
        // Print the offset of the entry
        printf("Offset: %llu\n", offset);
    } else {
        // Print an error message
        printf("Entry not found\n");
    }

    // Destroy the index
    index_destroy(index);

    return 0;
}