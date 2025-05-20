//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a linked list
struct node {
    char* word;
    int count;
    struct node* next;
};

// Hash table
struct hash_table {
    struct node** table;
    int size;
};

// Create a new hash table
struct hash_table* create_hash_table(int size) {
    struct hash_table* ht = malloc(sizeof(struct hash_table));
    ht->table = malloc(sizeof(struct node*) * size);
    ht->size = size;

    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }

    return ht;
}

// Insert a word into the hash table
void insert_word(struct hash_table* ht, char* word) {
    // Get the hash value
    int hash = hash_function(word, ht->size);

    // Create a new node
    struct node* new_node = malloc(sizeof(struct node));
    new_node->word = word;
    new_node->count = 1;
    new_node->next = NULL;

    // Insert the node into the hash table
    if (ht->table[hash] == NULL) {
        ht->table[hash] = new_node;
    } else {
        struct node* current = ht->table[hash];

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }
}

// Find a word in the hash table
struct node* find_word(struct hash_table* ht, char* word) {
    // Get the hash value
    int hash = hash_function(word, ht->size);

    // Find the word in the hash table
    struct node* current = ht->table[hash];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

// Print the hash table
void print_hash_table(struct hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node* current = ht->table[i];

        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Free the hash table
void free_hash_table(struct hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node* current = ht->table[i];

        while (current != NULL) {
            struct node* next = current->next;
            free(current->word);
            free(current);
            current = next;
        }
    }

    free(ht->table);
    free(ht);
}

// Hash function
int hash_function(char* word, int size) {
    int hash = 0;

    for (int i = 0; i < strlen(word); i++) {
        hash += word[i];
    }

    return hash % size;
}

int main() {
    // Create a hash table
    struct hash_table* ht = create_hash_table(100);

    // Insert some words into the hash table
    insert_word(ht, "hello");
    insert_word(ht, "world");
    insert_word(ht, "this");
    insert_word(ht, "is");
    insert_word(ht, "a");
    insert_word(ht, "test");

    // Print the hash table
    print_hash_table(ht);

    // Free the hash table
    free_hash_table(ht);

    return 0;
}