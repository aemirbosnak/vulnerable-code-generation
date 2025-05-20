//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Create a node for the hash table
typedef struct node {
    char *key;
    int count;
    struct node *next;
} node_t;

// Create a hash table
typedef struct hash_table {
    int size;
    node_t **table;
} hash_table_t;

// Initialize the hash table
hash_table_t *create_hash_table(int size) {
    hash_table_t *hash_table = malloc(sizeof(hash_table_t));
    hash_table->size = size;
    hash_table->table = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Insert a key into the hash table
void insert_key(hash_table_t *hash_table, char *key) {
    int index = hash(key, hash_table->size);
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->count = 1;
    node->next = hash_table->table[index];
    hash_table->table[index] = node;
}

// Check if a key exists in the hash table
int exists_key(hash_table_t *hash_table, char *key) {
    int index = hash(key, hash_table->size);
    node_t *node = hash_table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// Hash function
int hash(char *key, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % size;
}

// Free the hash table
void free_hash_table(hash_table_t *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        node_t *node = hash_table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

// Load a dictionary into the hash table
void load_dictionary(hash_table_t *hash_table, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, "\n");
        insert_key(hash_table, key);
    }
    fclose(file);
}

// Check if a word is spelled correctly
int is_correct(hash_table_t *hash_table, char *word) {
    return exists_key(hash_table, word);
}

int main() {
    // Create a hash table
    hash_table_t *hash_table = create_hash_table(10000);

    // Load the dictionary into the hash table
    load_dictionary(hash_table, "dictionary.txt");

    // Check if a word is spelled correctly
    char word[1024];
    printf("Enter a word: ");
    scanf("%s", word);

    if (is_correct(hash_table, word)) {
        printf("The word is spelled correctly!\n");
    } else {
        printf("The word is spelled incorrectly!\n");
    }

    // Free the hash table
    free_hash_table(hash_table);

    return 0;
}