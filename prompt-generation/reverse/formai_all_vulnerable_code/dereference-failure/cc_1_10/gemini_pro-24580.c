//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A node in a linked list
struct node {
    char *word;
    struct node *next;
};

// A hash table
struct hash_table {
    struct node **table;
    int size;
};

// Create a new hash table
struct hash_table *create_hash_table(int size) {
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->table = malloc(sizeof(struct node *) * size);
    table->size = size;
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Insert a word into the hash table
void insert_word(struct hash_table *table, char *word) {
    int index = hash(word, table->size);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

// Check if a word is in the hash table
int check_word(struct hash_table *table, char *word) {
    int index = hash(word, table->size);
    struct node *current_node = table->table[index];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Hash a word
int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += tolower(word[i]);
    }
    return hash_value % size;
}

// Free the hash table
void free_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        struct node *current_node = table->table[i];
        while (current_node != NULL) {
            struct node *next_node = current_node->next;
            free(current_node->word);
            free(current_node);
            current_node = next_node;
        }
    }
    free(table->table);
    free(table);
}

// Main function
int main() {

    // Create a hash table with size 1000
    struct hash_table *table = create_hash_table(1000);

    // Insert words into the hash table
    char *words[] = {"apple", "banana", "cherry", "dog", "elephant"};
    for (int i = 0; i < 5; i++) {
        insert_word(table, words[i]);
    }

    // Check if a word is in the hash table
    char *word = "apple";
    int is_in_table = check_word(table, word);
    if (is_in_table) {
        printf("%s is in the hash table\n", word);
    } else {
        printf("%s is not in the hash table\n", word);
    }

    // Free the hash table
    free_hash_table(table);

    return 0;
}