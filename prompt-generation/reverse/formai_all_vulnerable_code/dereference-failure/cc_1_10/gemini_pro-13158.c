//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the node structure for the linked list.
struct node {
    char *word;
    int count;
    struct node *next;
};

// Declare the hash table structure.
struct hash_table {
    struct node **table;
    int size;
};

// Create a new hash table.
struct hash_table *create_hash_table(int size) {
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->size = size;
    table->table = malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Insert a word into the hash table.
void insert_word(struct hash_table *table, char *word) {
    // Calculate the hash value for the word.
    int hash = hash_function(word, table->size);

    // Check if the word is already in the hash table.
    struct node *node = table->table[hash];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }

    // Create a new node for the word.
    node = malloc(sizeof(struct node));
    node->word = malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->count = 1;
    node->next = NULL;

    // Insert the node into the hash table.
    node->next = table->table[hash];
    table->table[hash] = node;
}

// Print the contents of the hash table.
void print_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *node = table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

// Free the memory allocated for the hash table.
void free_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *node = table->table[i];
        while (node != NULL) {
            struct node *next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }
    free(table->table);
    free(table);
}

// Hash function to convert a string to an integer.
int hash_function(char *string, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(string); i++) {
        hash += string[i];
    }
    return hash % size;
}

// Main function.
int main() {
    // Create a new hash table.
    struct hash_table *table = create_hash_table(100);

    // Insert some words into the hash table.
    insert_word(table, "hello");
    insert_word(table, "world");
    insert_word(table, "this");
    insert_word(table, "is");
    insert_word(table, "a");
    insert_word(table, "test");

    // Print the contents of the hash table.
    print_hash_table(table);

    // Free the memory allocated for the hash table.
    free_hash_table(table);

    return 0;
}