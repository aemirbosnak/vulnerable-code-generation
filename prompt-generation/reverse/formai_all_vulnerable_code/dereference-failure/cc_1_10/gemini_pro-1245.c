//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a database index
typedef struct index_node {
    char *key;
    int value;
    struct index_node *next;
} index_node;

// Create a new index node
index_node *create_index_node(char *key, int value) {
    index_node *new_node = malloc(sizeof(index_node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Insert a new index node into the index
void insert_index_node(index_node **index, char *key, int value) {
    index_node *new_node = create_index_node(key, value);

    // Insert the new node at the beginning of the index
    new_node->next = *index;
    *index = new_node;
}

// Search for a key in the index
int search_index(index_node *index, char *key) {
    index_node *current_node = index;

    // Iterate over the index until the key is found
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node->value;
        }
        current_node = current_node->next;
    }

    // The key was not found in the index
    return -1;
}

// Print the index
void print_index(index_node *index) {
    index_node *current_node = index;

    // Iterate over the index and print each node
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->key, current_node->value);
        current_node = current_node->next;
    }
}

// Free the memory allocated for the index
void free_index(index_node *index) {
    index_node *current_node = index;

    // Iterate over the index and free each node
    while (current_node != NULL) {
        index_node *next_node = current_node->next;
        free(current_node->key);
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main() {
    // Create a new index
    index_node *index = NULL;

    // Insert some data into the index
    insert_index_node(&index, "John", 10);
    insert_index_node(&index, "Jane", 20);
    insert_index_node(&index, "Bob", 30);

    // Print the index
    print_index(index);

    // Search for a key in the index
    int value = search_index(index, "John");

    // Print the value
    printf("The value for the key 'John' is: %d\n", value);

    // Free the memory allocated for the index
    free_index(index);

    return 0;
}