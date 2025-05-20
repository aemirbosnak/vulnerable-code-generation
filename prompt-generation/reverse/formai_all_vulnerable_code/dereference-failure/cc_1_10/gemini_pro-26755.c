//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a linked list node to store a word and its count
typedef struct node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct node *next;
} node;

// Create a hash table to store the words and their counts
typedef struct hash_table {
    int size;
    node **table;
} hash_table;

// Create a new hash table
hash_table *create_hash_table(int size) {
    hash_table *table = (hash_table *)malloc(sizeof(hash_table));
    table->size = size;
    table->table = (node **)malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Destroy a hash table
void destroy_hash_table(hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        node *current = table->table[i];
        while (current != NULL) {
            node *next = current->next;
            free(current);
            current = next;
        }
    }
    free(table->table);
    free(table);
}

// Hash a word into a value between 0 and size-1
int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }
    return hash_value % size;
}

// Insert a word into the hash table
void insert(hash_table *table, char *word) {
    int index = hash(word, table->size);
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

// Increment the count of a word in the hash table
void increment_count(hash_table *table, char *word) {
    int index = hash(word, table->size);
    node *current = table->table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    insert(table, word);
}

// Print the contents of the hash table
void print_hash_table(hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        node *current = table->table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Read a file and count the words in it
void count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    hash_table *table = create_hash_table(100);

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        increment_count(table, word);
    }

    fclose(file);

    print_hash_table(table);

    destroy_hash_table(table);
}

int main() {
    count_words("input.txt");
    return 0;
}