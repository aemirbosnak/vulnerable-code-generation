//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a node for the hash table
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Create a hash table
typedef struct hash_table {
    node_t **table;
    int size;
} hash_table_t;

// Create a new hash table
hash_table_t *create_hash_table(int size) {
    hash_table_t *hash_table = malloc(sizeof(hash_table_t));
    hash_table->table = malloc(sizeof(node_t *) * size);
    hash_table->size = size;
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Free the hash table
void free_hash_table(hash_table_t *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        node_t *node = hash_table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->word);
            free(node);
            node = next;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

// Hash a string
unsigned int hash(char *string) {
    unsigned int hash = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        hash = hash * 31 + string[i];
    }
    return hash;
}

// Insert a word into the hash table
void insert_word(hash_table_t *hash_table, char *word) {
    // Hash the word
    unsigned int hash_value = hash(word) % hash_table->size;

    // Create a new node
    node_t *node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;

    // Insert the node into the hash table
    if (hash_table->table[hash_value] == NULL) {
        hash_table->table[hash_value] = node;
    } else {
        node->next = hash_table->table[hash_value];
        hash_table->table[hash_value] = node;
    }
}

// Get the count of a word in the hash table
int get_word_count(hash_table_t *hash_table, char *word) {
    // Hash the word
    unsigned int hash_value = hash(word) % hash_table->size;

    // Find the node for the word
    node_t *node = hash_table->table[hash_value];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return node->count;
        }
        node = node->next;
    }

    // The word was not found in the hash table
    return 0;
}

// Print the words in the hash table
void print_words(hash_table_t *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        node_t *node = hash_table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

// Read a file and count the words
void count_words_in_file(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a hash table
    hash_table_t *hash_table = create_hash_table(1000);

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Tokenize the line
        char *token = strtok(line, " ,.-!?");
        while (token != NULL) {
            // Convert the token to lowercase
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }

            // Insert the token into the hash table
            insert_word(hash_table, token);

            // Get the next token
            token = strtok(NULL, " ,.-!?");
        }
    }

    // Close the file
    fclose(file);

    // Print the words in the hash table
    print_words(hash_table);

    // Free the hash table
    free_hash_table(hash_table);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    count_words_in_file(argv[1]);

    return 0;
}