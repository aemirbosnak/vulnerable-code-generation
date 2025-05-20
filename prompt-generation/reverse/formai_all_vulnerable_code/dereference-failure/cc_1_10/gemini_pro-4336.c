//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash table size
#define HASHSIZE 10000

// Hash table node
struct node {
    char *key;
    int value;
    struct node *next;
};

// Hash table
struct hashtable {
    struct node **table;
    int size;
};

// Create a new hash table
struct hashtable *create_hashtable(int size) {
    struct hashtable *table = malloc(sizeof(struct hashtable));
    table->table = malloc(sizeof(struct node *) * size);
    table->size = size;
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Destroy a hash table
void destroy_hashtable(struct hashtable *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *node = table->table[i];
        while (node != NULL) {
            struct node *next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(table->table);
    free(table);
}

// Insert a key-value pair into a hash table
void insert_hashtable(struct hashtable *table, char *key, int value) {
    int index = hash(key, table->size);
    struct node *node = malloc(sizeof(struct node));
    node->key = strdup(key);
    node->value = value;
    node->next = table->table[index];
    table->table[index] = node;
}

// Get a value from a hash table
int get_hashtable(struct hashtable *table, char *key) {
    int index = hash(key, table->size);
    struct node *node = table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

// Hash function
int hash(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * 31 + key[i]) % size;
    }
    return hash;
}

// Main function
int main() {
    // Create a new hash table
    struct hashtable *table = create_hashtable(HASHSIZE);

    // Insert some key-value pairs into the hash table
    insert_hashtable(table, "spam", 1);
    insert_hashtable(table, "ham", 0);
    insert_hashtable(table, "viagra", 1);
    insert_hashtable(table, "cialis", 1);
    insert_hashtable(table, "levitra", 1);

    // Get some values from the hash table
    int spam = get_hashtable(table, "spam");
    int ham = get_hashtable(table, "ham");
    int viagra = get_hashtable(table, "viagra");
    int cialis = get_hashtable(table, "cialis");
    int levitra = get_hashtable(table, "levitra");

    // Print the values
    printf("spam: %d\n", spam);
    printf("ham: %d\n", ham);
    printf("viagra: %d\n", viagra);
    printf("cialis: %d\n", cialis);
    printf("levitra: %d\n", levitra);

    // Destroy the hash table
    destroy_hashtable(table);

    return 0;
}