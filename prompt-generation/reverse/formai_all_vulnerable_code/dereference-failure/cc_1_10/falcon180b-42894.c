//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEXES 10
#define MAX_INDEX_SIZE 100

// Define the structure for the index
typedef struct {
    char *name;
    int size;
    int *index;
} index_t;

// Function to initialize the index
void init_index(index_t *index, char *name, int size) {
    index->name = name;
    index->size = size;
    index->index = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        index->index[i] = -1;
    }
}

// Function to add an entry to the index
void add_entry(index_t *index, char *key, int value) {
    int hash = strlen(key) % index->size;
    if (index->index[hash] == -1) {
        index->index[hash] = value;
    } else {
        printf("Collision detected for key '%s'\n", key);
    }
}

// Function to search the index for a key and return its value
int search_index(index_t *index, char *key) {
    int hash = strlen(key) % index->size;
    if (index->index[hash]!= -1) {
        return index->index[hash];
    } else {
        return -1;
    }
}

// Main function to demonstrate the indexing system
int main() {
    index_t index;
    init_index(&index, "Phone Number Index", 100);

    // Add some entries to the index
    add_entry(&index, "John Doe", 1234567890);
    add_entry(&index, "Jane Doe", 9876543210);

    // Search for an entry in the index
    int value = search_index(&index, "John Doe");
    if (value!= -1) {
        printf("Found entry for John Doe with value %d\n", value);
    } else {
        printf("Entry not found\n");
    }

    return 0;
}