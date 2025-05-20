//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the hash table structure
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Declare the hash table
node_t *hash_table[1000];

// Hash function
unsigned int hash(char *str) {
    unsigned int h = 0;
    int c;
    while ((c = *str++)) {
        h = h * 31 + c;
    }
    return h % 1000;
}

// Insert a word into the hash table
void insert(char *word) {
    // Get the hash value
    unsigned int h = hash(word);

    // Create a new node
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    // Insert the new node into the hash table
    if (hash_table[h] == NULL) {
        hash_table[h] = new_node;
    } else {
        new_node->next = hash_table[h];
        hash_table[h] = new_node;
    }
}

// Find a word in the hash table
node_t *find(char *word) {
    // Get the hash value
    unsigned int h = hash(word);

    // Search the hash table for the word
    node_t *current_node = hash_table[h];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }

    // Return NULL if the word was not found
    return NULL;
}

// Print the hash table
void print_hash_table() {
    for (int i = 0; i < 1000; i++) {
        node_t *current_node = hash_table[i];
        while (current_node != NULL) {
            printf("%s: %d\n", current_node->word, current_node->count);
            current_node = current_node->next;
        }
    }
}

// Free the hash table
void free_hash_table() {
    for (int i = 0; i < 1000; i++) {
        node_t *current_node = hash_table[i];
        while (current_node != NULL) {
            node_t *next_node = current_node->next;
            free(current_node->word);
            free(current_node);
            current_node = next_node;
        }
    }
}

// Main function
int main() {
    // Get the input text
    char *text = "This is a sample text. This text contains some words that appear multiple times. We can use a hash table to count the frequency of each word in the text.";

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Insert the token into the hash table
        insert(token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the hash table
    print_hash_table();

    // Free the hash table
    free_hash_table();

    return 0;
}