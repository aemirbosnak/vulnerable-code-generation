//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for storing a word and its count
struct Node {
    char *word;
    int count;
    struct Node *next;
};

// Hash table for storing words and their counts
struct HashTable {
    struct Node **table;
    int size;
};

// Initialize a hash table
struct HashTable *init_hash_table(int size) {
    struct HashTable *hash_table = malloc(sizeof(struct HashTable));
    hash_table->table = malloc(sizeof(struct Node *) * size);
    hash_table->size = size;
    for (int i = 0; i < size; i++) {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Insert a word into the hash table
void insert_word(struct HashTable *hash_table, char *word) {
    // Convert the word to lowercase
    char *lowered_word = malloc(strlen(word) + 1);
    for (int i = 0; i < strlen(word); i++) {
        lowered_word[i] = tolower(word[i]);
    }
    lowered_word[strlen(word)] = '\0';

    // Calculate the hash value of the word
    int hash_value = 0;
    for (int i = 0; i < strlen(lowered_word); i++) {
        hash_value += lowered_word[i];
    }
    hash_value %= hash_table->size;

    // Insert the word into the hash table
    struct Node *node = malloc(sizeof(struct Node));
    node->word = lowered_word;
    node->count = 1;
    node->next = hash_table->table[hash_value];
    hash_table->table[hash_value] = node;
}

// Find a word in the hash table
struct Node *find_word(struct HashTable *hash_table, char *word) {
    // Convert the word to lowercase
    char *lowered_word = malloc(strlen(word) + 1);
    for (int i = 0; i < strlen(word); i++) {
        lowered_word[i] = tolower(word[i]);
    }
    lowered_word[strlen(word)] = '\0';

    // Calculate the hash value of the word
    int hash_value = 0;
    for (int i = 0; i < strlen(lowered_word); i++) {
        hash_value += lowered_word[i];
    }
    hash_value %= hash_table->size;

    // Find the word in the hash table
    struct Node *node = hash_table->table[hash_value];
    while (node != NULL) {
        if (strcmp(node->word, lowered_word) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// Count the number of occurrences of a word in a text file
int count_word(struct HashTable *hash_table, char *filename) {
    // Open the text file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    // Read the file line by line
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, file)) != -1) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Insert the word into the hash table
            insert_word(hash_table, token);
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Return the number of words in the hash table
    return hash_table->size;
}

// Print the words and their counts in the hash table
void print_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct Node *node = hash_table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

// Free the memory allocated for the hash table
void free_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < hash_table->size; i++) {
        struct Node *node = hash_table->table[i];
        while (node != NULL) {
            struct Node *next_node = node->next;
            free(node->word);
            free(node);
            node = next_node;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

int main() {
    // Create a hash table
    struct HashTable *hash_table = init_hash_table(1000);

    // Count the number of words in a text file
    int word_count = count_word(hash_table, "text.txt");

    // Print the words and their counts in the hash table
    print_hash_table(hash_table);

    // Free the memory allocated for the hash table
    free_hash_table(hash_table);

    return 0;
}