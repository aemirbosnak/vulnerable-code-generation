//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database index entry
typedef struct index_entry {
    char *key;
    int value;
} index_entry;

// Create a new database index
index_entry *create_index(int size) {
    index_entry *index = malloc(sizeof(index_entry) * size);
    return index;
}

// Insert a new entry into the database index
void insert_index(index_entry *index, int size, char *key, int value) {
    for (int i = 0; i < size; i++) {
        if (index[i].key == NULL) {
            index[i].key = strdup(key);
            index[i].value = value;
            break;
        }
    }
}

// Search for a key in the database index
int search_index(index_entry *index, int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (index[i].key != NULL && strcmp(index[i].key, key) == 0) {
            return index[i].value;
        }
    }
    return -1;
}

// Delete a key from the database index
void delete_index(index_entry *index, int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (index[i].key != NULL && strcmp(index[i].key, key) == 0) {
            free(index[i].key);
            index[i].key = NULL;
            index[i].value = -1;
            break;
        }
    }
}

// Print the database index
void print_index(index_entry *index, int size) {
    for (int i = 0; i < size; i++) {
        if (index[i].key != NULL) {
            printf("%s: %d\n", index[i].key, index[i].value);
        }
    }
}

// Free the memory allocated for the database index
void free_index(index_entry *index, int size) {
    for (int i = 0; i < size; i++) {
        if (index[i].key != NULL) {
            free(index[i].key);
        }
    }
    free(index);
}

// Test the database index system
int main() {
    // Create a new database index
    index_entry *index = create_index(10);

    // Insert some entries into the database index
    insert_index(index, 10, "name", 1);
    insert_index(index, 10, "age", 2);
    insert_index(index, 10, "city", 3);

    // Search for a key in the database index
    int value = search_index(index, 10, "name");
    printf("The value for the key 'name' is: %d\n", value);

    // Delete a key from the database index
    delete_index(index, 10, "age");

    // Print the database index
    print_index(index, 10);

    // Free the memory allocated for the database index
    free_index(index, 10);

    return 0;
}