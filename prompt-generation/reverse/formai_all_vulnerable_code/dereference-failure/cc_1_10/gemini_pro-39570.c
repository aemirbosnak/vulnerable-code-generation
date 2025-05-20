//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the index
typedef struct node {
    char *key;
    int value;
    struct node *next;
} node;

// Hash table structure
typedef struct hash_table {
    int size;
    node **table;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(int size) {
    hash_table *ht = (hash_table *)malloc(sizeof(hash_table));
    ht->size = size;
    ht->table = (node **)malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Hash function to convert a string to an integer
int hash_function(char *key, int size) {
    int hash = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash += key[i] * (i + 1);
    }
    return hash % size;
}

// Insert a key-value pair into the hash table
void insert(hash_table *ht, char *key, int value) {
    int index = hash_function(key, ht->size);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = new_node;
    } else {
        node *temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Search for a key in the hash table and return its value
int search(hash_table *ht, char *key) {
    int index = hash_function(key, ht->size);
    node *temp = ht->table[index];

    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}

// Print the hash table
void print_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *temp = ht->table[i];
        while (temp != NULL) {
            printf("%s: %d\n", temp->key, temp->value);
            temp = temp->next;
        }
    }
}

// Free the hash table
void free_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *temp = ht->table[i];
        while (temp != NULL) {
            node *next = temp->next;
            free(temp->key);
            free(temp);
            temp = next;
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    // Create a new hash table with a size of 10
    hash_table *ht = create_hash_table(10);

    // Insert some key-value pairs into the hash table
    insert(ht, "John", 20);
    insert(ht, "Mary", 25);
    insert(ht, "Bob", 30);
    insert(ht, "Alice", 35);
    insert(ht, "Tom", 40);

    // Print the hash table
    print_hash_table(ht);

    // Search for a key in the hash table
    int value = search(ht, "John");
    if (value == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found: %d\n", value);
    }

    // Free the hash table
    free_hash_table(ht);

    return 0;
}