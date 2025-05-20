//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom hashing function
unsigned int hash(const char *str) {
    unsigned int h = 0;
    while (*str) {
        h = h * 31 + *str++;
    }
    return h;
}

// Custom linked list node
struct node {
    char *key;
    char *value;
    struct node *next;
};

// Custom hash table
struct hash_table {
    struct node **table;
    unsigned int size;
};

// Create a new hash table
struct hash_table *create_hash_table(unsigned int size) {
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    ht->size = size;
    ht->table = malloc(sizeof(struct node *) * size);
    for (unsigned int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert a key-value pair into the hash table
void insert(struct hash_table *ht, const char *key, const char *value) {
    unsigned int h = hash(key) % ht->size;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->table[h];
    ht->table[h] = new_node;
}

// Get the value associated with a key from the hash table
char *get(struct hash_table *ht, const char *key) {
    unsigned int h = hash(key) % ht->size;
    struct node *node = ht->table[h];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

// Print the contents of the hash table
void print_hash_table(struct hash_table *ht) {
    for (unsigned int i = 0; i < ht->size; i++) {
        struct node *node = ht->table[i];
        while (node != NULL) {
            printf("%s: %s\n", node->key, node->value);
            node = node->next;
        }
    }
}

// Free the memory allocated for the hash table
void free_hash_table(struct hash_table *ht) {
    for (unsigned int i = 0; i < ht->size; i++) {
        struct node *node = ht->table[i];
        while (node != NULL) {
            struct node *next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    free(ht->table);
    free(ht);
}

// Driver code
int main() {
    struct hash_table *ht = create_hash_table(10);
    insert(ht, "Alice", "alice@example.com");
    insert(ht, "Bob", "bob@example.com");
    insert(ht, "Charlie", "charlie@example.com");
    insert(ht, "Dave", "dave@example.com");
    insert(ht, "Eve", "eve@example.com");

    printf("Contents of the hash table:\n");
    print_hash_table(ht);

    printf("Getting the value for the key \"Alice\": %s\n", get(ht, "Alice"));

    free_hash_table(ht);

    return 0;
}