//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple hash function to map a string to a number
unsigned int hash(const char *s) {
    unsigned int h = 0;
    while (*s) {
        h = (h << 5) - h + *s++;
    }
    return h;
}

// A linked list node to store a key-value pair
struct node {
    char *key;
    int value;
    struct node *next;
};

// A hash table to store the key-value pairs
struct hash_table {
    struct node **table;
    int size;
};

// Create a new hash table
struct hash_table *create_hash_table(int size) {
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    if (!ht) {
        return NULL;
    }
    ht->table = malloc(sizeof(struct node *) * size);
    if (!ht->table) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    ht->size = size;
    return ht;
}

// Insert a key-value pair into the hash table
void insert(struct hash_table *ht, const char *key, int value) {
    unsigned int h = hash(key) % ht->size;
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        return;
    }
    n->key = strdup(key);
    n->value = value;
    n->next = ht->table[h];
    ht->table[h] = n;
}

// Get a value from the hash table by its key
int get(struct hash_table *ht, const char *key) {
    unsigned int h = hash(key) % ht->size;
    struct node *n = ht->table[h];
    while (n) {
        if (strcmp(n->key, key) == 0) {
            return n->value;
        }
        n = n->next;
    }
    return -1;
}

// Delete a key-value pair from the hash table
void delete(struct hash_table *ht, const char *key) {
    unsigned int h = hash(key) % ht->size;
    struct node *n = ht->table[h];
    struct node *prev = NULL;
    while (n) {
        if (strcmp(n->key, key) == 0) {
            if (prev) {
                prev->next = n->next;
            } else {
                ht->table[h] = n->next;
            }
            free(n->key);
            free(n);
            return;
        }
        prev = n;
        n = n->next;
    }
}

// Print the contents of the hash table
void print_hash_table(struct hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node *n = ht->table[i];
        while (n) {
            printf("%s: %d\n", n->key, n->value);
            n = n->next;
        }
    }
}

// Free the hash table
void free_hash_table(struct hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node *n = ht->table[i];
        while (n) {
            struct node *next = n->next;
            free(n->key);
            free(n);
            n = next;
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    struct hash_table *ht = create_hash_table(10);
    insert(ht, "Alice", 25);
    insert(ht, "Bob", 30);
    insert(ht, "Charlie", 35);
    print_hash_table(ht);
    printf("The age of Alice is %d\n", get(ht, "Alice"));
    delete(ht, "Charlie");
    print_hash_table(ht);
    free_hash_table(ht);
    return 0;
}