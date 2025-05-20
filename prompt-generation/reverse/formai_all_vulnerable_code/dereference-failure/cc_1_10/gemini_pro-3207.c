//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the index structure
typedef struct index {
    char *key;
    int value;
} index_t;

// Create a new index
index_t *index_new(char *key, int value) {
    index_t *index = malloc(sizeof(index_t));
    index->key = strdup(key);
    index->value = value;
    return index;
}

// Free an index
void index_free(index_t *index) {
    free(index->key);
    free(index);
}

// Insert an index into a sorted array
void index_insert(index_t **indexes, int *count, index_t *index) {
    int i;

    // Find the insertion point
    for (i = 0; i < *count; i++) {
        if (strcmp(index->key, indexes[i]->key) < 0) {
            break;
        }
    }

    // Shift the indexes to make room for the new index
    for (int j = *count; j > i; j--) {
        indexes[j] = indexes[j - 1];
    }

    // Insert the new index
    indexes[i] = index;

    // Increment the count of indexes
    (*count)++;
}

// Search for an index in a sorted array
index_t *index_search(index_t **indexes, int count, char *key) {
    int i;

    // Binary search for the key
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(key, indexes[mid]->key);
        if (cmp == 0) {
            return indexes[mid];
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Key not found
    return NULL;
}

// Print the indexes
void index_print(index_t **indexes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s -> %d\n", indexes[i]->key, indexes[i]->value);
    }
}

// Free the indexes
void index_free_all(index_t **indexes, int count) {
    for (int i = 0; i < count; i++) {
        index_free(indexes[i]);
    }
    free(indexes);
}

// Main function
int main() {
    // Create an array of indexes
    index_t **indexes = malloc(sizeof(index_t *) * 100);
    int count = 0;

    // Insert some indexes into the array
    index_insert(indexes, &count, index_new("a", 1));
    index_insert(indexes, &count, index_new("b", 2));
    index_insert(indexes, &count, index_new("c", 3));
    index_insert(indexes, &count, index_new("d", 4));
    index_insert(indexes, &count, index_new("e", 5));

    // Print the indexes
    printf("Indexes:\n");
    index_print(indexes, count);

    // Search for an index
    index_t *index = index_search(indexes, count, "c");
    if (index) {
        printf("Found index: %s -> %d\n", index->key, index->value);
    } else {
        printf("Index not found\n");
    }

    // Free the indexes
    index_free_all(indexes, count);

    return 0;
}