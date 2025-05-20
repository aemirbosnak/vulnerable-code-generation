//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the hash table structure
typedef struct node {
    char *word;
    struct node *next;
} node;

// Create a new hash table
node *create_hash_table(int size) {
    node *table = malloc(sizeof(node) * size);
    for (int i = 0; i < size; i++) {
        table[i].word = NULL;
        table[i].next = NULL;
    }
    return table;
}

// Insert a word into the hash table
void insert_word(node *table, char *word, int size) {
    // Calculate the hash value
    int index = hash(word, size);

    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->next = NULL;

    // Insert the new node into the hash table
    if (table[index].word == NULL) {
        table[index].word = new_node->word;
    } else {
        node *current = &table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Check if a word is in the hash table
int check_word(node *table, char *word, int size) {
    // Calculate the hash value
    int index = hash(word, size);

    // Search for the word in the hash table
    node *current = &table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    // The word was not found in the hash table
    return 0;
}

// Hash function
int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }
    return hash_value % size;
}

// Main function
int main() {
    // Create a hash table
    node *table = create_hash_table(100);

    // Insert some words into the hash table
    insert_word(table, "hello", 100);
    insert_word(table, "world", 100);
    insert_word(table, "computer", 100);

    // Check if some words are in the hash table
    printf("hello: %d\n", check_word(table, "hello", 100));
    printf("world: %d\n", check_word(table, "world", 100));
    printf("computer: %d\n", check_word(table, "computer", 100));
    printf("not_a_word: %d\n", check_word(table, "not_a_word", 100));

    return 0;
}