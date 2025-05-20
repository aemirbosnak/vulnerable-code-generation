//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the hash table size
#define HASHTABLE_SIZE 100000

// Define the linked list node
typedef struct node {
    char *word;
    struct node *next;
} node_t;

// Define the hash table
node_t *hashtable[HASHTABLE_SIZE];

// Hash function
unsigned int hash(char *word) {
    unsigned int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }
    return hash_value % HASHTABLE_SIZE;
}

// Insert a word into the hash table
void insert(char *word) {
    // Get the hash value
    unsigned int hash_value = hash(word);

    // Create a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->word = word;
    new_node->next = NULL;

    // Insert the node into the hash table
    if (hashtable[hash_value] == NULL) {
        hashtable[hash_value] = new_node;
    } else {
        node_t *current_node = hashtable[hash_value];
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Check if a word is in the hash table
int find(char *word) {
    // Get the hash value
    unsigned int hash_value = hash(word);

    // Search for the word in the hash table
    node_t *current_node = hashtable[hash_value];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }

    // The word was not found
    return 0;
}

// Print the hash table
void print_hashtable() {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node_t *current_node = hashtable[i];
        while (current_node != NULL) {
            printf("%s\n", current_node->word);
            current_node = current_node->next;
        }
    }
}

// Main function
int main() {
    // Insert some words into the hash table
    insert("hello");
    insert("world");
    insert("computer");
    insert("science");

    // Print the hash table
    print_hashtable();

    // Check if a word is in the hash table
    if (find("hello")) {
        printf("The word 'hello' is in the hash table.\n");
    } else {
        printf("The word 'hello' is not in the hash table.\n");
    }

    return 0;
}