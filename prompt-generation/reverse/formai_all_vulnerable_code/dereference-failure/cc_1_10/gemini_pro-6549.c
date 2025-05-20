//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Custom hash function for integers
unsigned int hash(int key) {
    return key % 100;
}

// Custom linked list node
struct node {
    int key;
    struct node *next;
};

// Custom hash table structure
struct hash_table {
    struct node **buckets;
    unsigned int size;
};

// Initialize a hash table
struct hash_table *init_hash_table(unsigned int size) {
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->buckets = malloc(sizeof(struct node *) * size);
    table->size = size;
    for (unsigned int i = 0; i < table->size; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Insert a key into the hash table
void insert(struct hash_table *table, int key) {
    unsigned int index = hash(key);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

// Search for a key in the hash table
struct node *search(struct hash_table *table, int key) {
    unsigned int index = hash(key);
    struct node *current = table->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print the hash table
void print_hash_table(struct hash_table *table) {
    for (unsigned int i = 0; i < table->size; i++) {
        struct node *current = table->buckets[i];
        printf("Bucket %u: ", i);
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

// Destroy the hash table
void destroy_hash_table(struct hash_table *table) {
    for (unsigned int i = 0; i < table->size; i++) {
        struct node *current = table->buckets[i];
        while (current != NULL) {
            struct node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    // Initialize a hash table with 100 buckets
    struct hash_table *table = init_hash_table(100);

    // Insert some keys into the hash table
    insert(table, 1);
    insert(table, 10);
    insert(table, 100);
    insert(table, 1000);

    // Search for a key in the hash table
    struct node *found = search(table, 100);
    if (found != NULL) {
        printf("Found key: %d\n", found->key);
    } else {
        printf("Key not found\n");
    }

    // Print the hash table
    print_hash_table(table);

    // Destroy the hash table
    destroy_hash_table(table);

    return 0;
}