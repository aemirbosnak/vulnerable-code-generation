//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an index entry
typedef struct index_entry {
    int key;
    int value;
} index_entry;

// Define the structure of an index
typedef struct index {
    int size;
    index_entry *entries;
} index;

// Create a new index
index *create_index() {
    index *idx = malloc(sizeof(index));
    idx->size = 0;
    idx->entries = NULL;
    return idx;
}

// Insert a key-value pair into the index
void insert_index(index *idx, int key, int value) {
    // Create a new index entry
    index_entry *entry = malloc(sizeof(index_entry));
    entry->key = key;
    entry->value = value;

    // Insert the entry into the index
    if (idx->size == 0) {
        idx->entries = entry;
    } else {
        idx->entries = realloc(idx->entries, (idx->size + 1) * sizeof(index_entry));
        idx->entries[idx->size] = *entry;
    }

    idx->size++;
}

// Search for a key in the index
int search_index(index *idx, int key) {
    // Linear search for the key
    for (int i = 0; i < idx->size; i++) {
        if (idx->entries[i].key == key) {
            return idx->entries[i].value;
        }
    }

    // Key not found
    return -1;
}

// Free the memory allocated for the index
void free_index(index *idx) {
    free(idx->entries);
    free(idx);
}

// Main function
int main() {
    // Create a new index
    index *idx = create_index();

    // Insert some key-value pairs into the index
    insert_index(idx, 1, 10);
    insert_index(idx, 2, 20);
    insert_index(idx, 3, 30);

    // Search for a key in the index
    int value = search_index(idx, 2);

    // Print the value
    printf("The value for key 2 is: %d\n", value);

    // Free the memory allocated for the index
    free_index(idx);

    return 0;
}