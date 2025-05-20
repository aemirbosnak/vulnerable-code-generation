//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a linked list to store a word and its count
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// A hash table to store the word counts
typedef struct hash_table {
    node **table;
    int size;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(int size) {
    hash_table *ht = malloc(sizeof(hash_table));
    if (ht == NULL) {
        return NULL;
    }

    ht->table = malloc(sizeof(node *) * size);
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }

    ht->size = size;

    return ht;
}

// Free the memory allocated for a hash table
void free_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *current = ht->table[i];
        while (current != NULL) {
            node *next = current->next;
            free(current->word);
            free(current);
            current = next;
        }
    }

    free(ht->table);
    free(ht);
}

// Hash a word to an index in the hash table
int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }

    return hash_value % size;
}

// Insert a word into the hash table
void insert(hash_table *ht, char *word) {
    int index = hash(word, ht->size);
    node *current = ht->table[index];

    // If the word is already in the hash table, increment its count
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // If the word is not in the hash table, create a new node and insert it
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return;
    }

    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = ht->table[index];

    ht->table[index] = new_node;
}

// Print the words and their counts in the hash table
void print_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *current = ht->table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Read a file and count the words in it
void count_words_in_file(char *filename, hash_table *ht) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        insert(ht, word);
    }

    fclose(file);
}

int main() {
    // Create a hash table with a size of 1000
    hash_table *ht = create_hash_table(1000);

    // Read the words from the file "words.txt" and count them
    count_words_in_file("words.txt", ht);

    // Print the words and their counts in the hash table
    print_hash_table(ht);

    // Free the memory allocated for the hash table
    free_hash_table(ht);

    return 0;
}