//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Node structure for a decentralized database
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

// Hash table for storing nodes
typedef struct HashTable {
    Node **table;
    int size;
} HashTable;

// Create a new hash table with the given size
HashTable *create_hash_table(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->table = malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Insert a new node into the hash table
void insert_node(HashTable *table, char *key, char *value) {
    // Get the hash value for the key
    int hash = hash_function(key);

    // Create a new node
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;

    // Insert the node into the hash table
    if (table->table[hash] == NULL) {
        table->table[hash] = node;
    } else {
        node->next = table->table[hash];
        table->table[hash] = node;
    }
}

// Search for a node in the hash table
Node *search_node(HashTable *table, char *key) {
    // Get the hash value for the key
    int hash = hash_function(key);

    // Search for the node in the hash table
    Node *node = table->table[hash];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
        node = node->next;
    }

    // Return NULL if the node was not found
    return NULL;
}

// Delete a node from the hash table
void delete_node(HashTable *table, char *key) {
    // Get the hash value for the key
    int hash = hash_function(key);

    // Search for the node in the hash table
    Node *node = table->table[hash];
    Node *prev = NULL;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                table->table[hash] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node->key);
            free(node->value);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

// Print the hash table
void print_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *node = table->table[i];
        while (node != NULL) {
            printf("%s: %s\n", node->key, node->value);
            node = node->next;
        }
    }
}

// Free the hash table
void free_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *node = table->table[i];
        while (node != NULL) {
            Node *next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    free(table->table);
    free(table);
}

// Hash function for strings
int hash_function(char *key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % 100;
}

// Main function
int main() {
    // Create a new hash table
    HashTable *table = create_hash_table(100);

    // Insert some nodes into the hash table
    insert_node(table, "key1", "value1");
    insert_node(table, "key2", "value2");
    insert_node(table, "key3", "value3");

    // Search for a node in the hash table
    Node *node = search_node(table, "key2");
    if (node != NULL) {
        printf("Found node with key '%s' and value '%s'\n", node->key, node->value);
    } else {
        printf("Node not found\n");
    }

    // Delete a node from the hash table
    delete_node(table, "key3");

    // Print the hash table
    print_hash_table(table);

    // Free the hash table
    free_hash_table(table);

    return 0;
}