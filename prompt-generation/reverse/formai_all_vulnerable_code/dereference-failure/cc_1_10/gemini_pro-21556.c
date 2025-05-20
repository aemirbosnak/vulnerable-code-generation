//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: satisfied
// Index Database
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Index node
struct IndexNode {
    int key;
    int value;
    struct IndexNode *next;
};

// Hash table
struct HashTable {
    int size;
    struct IndexNode **table;
};

// Create a new hash table
struct HashTable *create_hash_table(int size) {
    struct HashTable *hash_table = (struct HashTable *)malloc(sizeof(struct HashTable));
    hash_table->size = size;
    hash_table->table = (struct IndexNode **)calloc(size, sizeof(struct IndexNode *));
    return hash_table;
}

// Hash function
int hash_function(int key, int size) {
    return key % size;
}

// Insert a key-value pair into the hash table
void insert(struct HashTable *hash_table, int key, int value) {
    int hash_value = hash_function(key, hash_table->size);
    struct IndexNode *node = (struct IndexNode *)malloc(sizeof(struct IndexNode));
    node->key = key;
    node->value = value;
    node->next = hash_table->table[hash_value];
    hash_table->table[hash_value] = node;
}

// Search for a key in the hash table
int search(struct HashTable *hash_table, int key) {
    int hash_value = hash_function(key, hash_table->size);
    struct IndexNode *node = hash_table->table[hash_value];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

// Print the hash table
void print_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct IndexNode *node = hash_table->table[i];
        while (node != NULL) {
            printf("%d:%d ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    struct HashTable *hash_table = create_hash_table(10);
    insert(hash_table, 1, 10);
    insert(hash_table, 2, 20);
    insert(hash_table, 3, 30);
    insert(hash_table, 4, 40);
    insert(hash_table, 5, 50);
    print_hash_table(hash_table);
    printf("\n");
    printf("Value of key 2: %d\n", search(hash_table, 2));
    return 0;
}