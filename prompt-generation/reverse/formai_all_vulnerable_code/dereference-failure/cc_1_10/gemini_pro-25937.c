//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// A simple hash table to store word frequencies
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Initialize a hash table
node_t *init_hash_table(int size) {
    node_t *hash_table = malloc(sizeof(node_t) * size);
    for (int i = 0; i < size; i++) {
        hash_table[i].word = NULL;
        hash_table[i].count = 0;
        hash_table[i].next = NULL;
    }
    return hash_table;
}

// Hash a word into a hash table
int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash_value += tolower(word[i]);
    }
    return hash_value % size;
}

// Insert a word into a hash table
void insert_word(node_t *hash_table, int size, char *word) {
    int hash_value = hash(word, size);
    node_t *node = &hash_table[hash_value];
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = malloc(sizeof(node_t));
    node = node->next;
    node->word = strdup(word);
    node->count++;
}

// Print the words in a hash table
void print_hash_table(node_t *hash_table, int size) {
    for (int i = 0; i < size; i++) {
        node_t *node = &hash_table[i];
        while (node->next != NULL) {
            node = node->next;
            printf("%s: %d\n", node->word, node->count);
        }
    }
}

// Free the memory allocated for a hash table
void free_hash_table(node_t *hash_table, int size) {
    for (int i = 0; i < size; i++) {
        node_t *node = &hash_table[i];
        while (node->next != NULL) {
            node = node->next;
            free(node->word);
            free(node);
        }
    }
    free(hash_table);
}

int main() {
    // Create a hash table to store word frequencies
    int size = 100;
    node_t *hash_table = init_hash_table(size);

    // Read the input text from stdin
    char *input_text = NULL;
    size_t input_size = 0;
    getline(&input_text, &input_size, stdin);

    // Tokenize the input text and insert each word into the hash table
    char *token = strtok(input_text, " ");
    while (token != NULL) {
        insert_word(hash_table, size, token);
        token = strtok(NULL, " ");
    }

    // Print the word frequencies in the hash table
    print_hash_table(hash_table, size);

    // Free the memory allocated for the hash table
    free_hash_table(hash_table, size);

    // Free the memory allocated for the input text
    free(input_text);

    return 0;
}