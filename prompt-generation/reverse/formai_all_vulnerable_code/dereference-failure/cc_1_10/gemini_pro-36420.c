//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a hash table
struct node {
    char *key;
    int value;
    struct node *next;
};

// A hash table
struct hash_table {
    int size;
    struct node **table;
};

// Create a new hash table
struct hash_table *create_hash_table(int size) {
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->size = size;
    table->table = malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Insert a key-value pair into a hash table
void insert_into_hash_table(struct hash_table *table, char *key, int value) {
    // Calculate the hash value of the key
    int hash_value = hash(key, table->size);

    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    // Insert the new node into the hash table
    if (table->table[hash_value] == NULL) {
        table->table[hash_value] = new_node;
    } else {
        struct node *current_node = table->table[hash_value];
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Get the value associated with a key in a hash table
int get_from_hash_table(struct hash_table *table, char *key) {
    // Calculate the hash value of the key
    int hash_value = hash(key, table->size);

    // Search for the key in the hash table
    struct node *current_node = table->table[hash_value];
    while (current_node != NULL) {
        if (strcmp(current_node->key, key) == 0) {
            return current_node->value;
        }
        current_node = current_node->next;
    }

    // The key was not found in the hash table
    return -1;
}

// Print the contents of a hash table
void print_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *current_node = table->table[i];
        while (current_node != NULL) {
            printf("%s: %d\n", current_node->key, current_node->value);
            current_node = current_node->next;
        }
    }
}

// Hash a string
int hash(char *string, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(string); i++) {
        hash_value += string[i];
    }
    return hash_value % size;
}

// Free the memory allocated for a hash table
void free_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *current_node = table->table[i];
        while (current_node != NULL) {
            struct node *next_node = current_node->next;
            free(current_node->key);
            free(current_node);
            current_node = next_node;
        }
    }
    free(table->table);
    free(table);
}

int main() {
    // Create a hash table
    struct hash_table *table = create_hash_table(100);

    // Insert some key-value pairs into the hash table
    insert_into_hash_table(table, "apple", 1);
    insert_into_hash_table(table, "banana", 2);
    insert_into_hash_table(table, "cherry", 3);
    insert_into_hash_table(table, "dog", 4);
    insert_into_hash_table(table, "elephant", 5);

    // Get the value associated with a key in the hash table
    int value = get_from_hash_table(table, "apple");

    // Print the contents of the hash table
    print_hash_table(table);

    // Free the memory allocated for the hash table
    free_hash_table(table);

    return 0;
}