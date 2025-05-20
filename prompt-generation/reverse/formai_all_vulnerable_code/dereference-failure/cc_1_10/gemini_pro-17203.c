//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 256

// A linked list node to store a word and its count
typedef struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node *next;
} node_t;

// A hash table to store the words and their counts
typedef struct hash_table {
    node_t *table[MAX_WORDS];
} hash_table_t;

// Create a new hash table
hash_table_t *create_hash_table() {
    hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
    for (int i = 0; i < MAX_WORDS; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Free the memory allocated for the hash table
void free_hash_table(hash_table_t *table) {
    for (int i = 0; i < MAX_WORDS; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node);
            node = next;
        }
    }
    free(table);
}

// Hash a word to an index in the hash table
int hash_word(const char *word) {
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash += word[i];
    }
    return hash % MAX_WORDS;
}

// Insert a word into the hash table
void insert_word(hash_table_t *table, const char *word) {
    int index = hash_word(word);
    node_t *node = table->table[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    node = (node_t *)malloc(sizeof(node_t));
    strcpy(node->word, word);
    node->count = 1;
    node->next = table->table[index];
    table->table[index] = node;
}

// Print the words and their counts in the hash table
void print_hash_table(hash_table_t *table) {
    for (int i = 0; i < MAX_WORDS; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

int main() {
    // Create a hash table
    hash_table_t *table = create_hash_table();

    // Insert some words into the hash table
    insert_word(table, "the");
    insert_word(table, "quick");
    insert_word(table, "brown");
    insert_word(table, "fox");
    insert_word(table, "jumps");
    insert_word(table, "over");
    insert_word(table, "the");
    insert_word(table, "lazy");
    insert_word(table, "dog");

    // Print the words and their counts in the hash table
    print_hash_table(table);

    // Free the memory allocated for the hash table
    free_hash_table(table);

    return 0;
}