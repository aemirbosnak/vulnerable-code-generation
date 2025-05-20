//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash function
unsigned int hash(const char *str) {
    unsigned int h = 0;
    while (*str) {
        h = (h << 5) - h + *str++;
    }
    return h;
}

// Define the node structure
typedef struct node {
    char *key;
    unsigned int value;
    struct node *next;
} node;

// Define the hash table structure
typedef struct hash_table {
    node **table;
    unsigned int size;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(unsigned int size) {
    hash_table *ht = malloc(sizeof(hash_table));
    ht->table = malloc(sizeof(node *) * size);
    ht->size = size;
    for (unsigned int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert a key-value pair into the hash table
void insert(hash_table *ht, const char *key, unsigned int value) {
    unsigned int index = hash(key) % ht->size;
    node *new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

// Get the value associated with a key from the hash table
unsigned int get(hash_table *ht, const char *key) {
    unsigned int index = hash(key) % ht->size;
    node *curr = ht->table[index];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return 0;
}

// Delete a key-value pair from the hash table
void delete(hash_table *ht, const char *key) {
    unsigned int index = hash(key) % ht->size;
    node *curr = ht->table[index];
    node *prev = NULL;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                ht->table[index] = curr->next;
            }
            free(curr->key);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Print the hash table
void print_hash_table(hash_table *ht) {
    for (unsigned int i = 0; i < ht->size; i++) {
        node *curr = ht->table[i];
        while (curr) {
            printf("%s: %u\n", curr->key, curr->value);
            curr = curr->next;
        }
    }
}

// Destroy the hash table
void destroy_hash_table(hash_table *ht) {
    for (unsigned int i = 0; i < ht->size; i++) {
        node *curr = ht->table[i];
        while (curr) {
            node *next = curr->next;
            free(curr->key);
            free(curr);
            curr = next;
        }
    }
    free(ht->table);
    free(ht);
}

// Main function
int main() {
    // Create a hash table
    hash_table *ht = create_hash_table(10);

    // Insert some key-value pairs into the hash table
    insert(ht, "Alice", 123);
    insert(ht, "Bob", 456);
    insert(ht, "Charlie", 789);

    // Get the value associated with a key from the hash table
    printf("Alice's value: %u\n", get(ht, "Alice"));

    // Delete a key-value pair from the hash table
    delete(ht, "Charlie");

    // Print the hash table
    print_hash_table(ht);

    // Destroy the hash table
    destroy_hash_table(ht);

    return 0;
}