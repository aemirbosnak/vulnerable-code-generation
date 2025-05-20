//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the inverted index
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// A hash table to store the inverted index
typedef struct hashtable {
    int size;
    node **table;
} hashtable;

// Create a new hash table
hashtable *create_hashtable(int size) {
    hashtable *ht = malloc(sizeof(hashtable));
    ht->size = size;
    ht->table = malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Hash a string
unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

// Insert a word into the hash table
void insert(hashtable *ht, char *word) {
    // Get the hash value
    unsigned int hash_value = hash(word) % ht->size;

    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    // Insert the new node into the hash table
    if (ht->table[hash_value] == NULL) {
        ht->table[hash_value] = new_node;
    } else {
        node *current_node = ht->table[hash_value];
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Search for a word in the hash table
node *search(hashtable *ht, char *word) {
    // Get the hash value
    unsigned int hash_value = hash(word) % ht->size;

    // Search for the word in the hash table
    node *current_node = ht->table[hash_value];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }

    // The word was not found
    return NULL;
}

// Print the hash table
void print_hashtable(hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *current_node = ht->table[i];
        while (current_node != NULL) {
            printf("%s: %d\n", current_node->word, current_node->count);
            current_node = current_node->next;
        }
    }
}

// Free the hash table
void free_hashtable(hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        node *current_node = ht->table[i];
        while (current_node != NULL) {
            node *next_node = current_node->next;
            free(current_node->word);
            free(current_node);
            current_node = next_node;
        }
    }
    free(ht->table);
    free(ht);
}

// Parse a document and add it to the hash table
void parse_document(hashtable *ht, char *document) {
    // Tokenize the document
    char *token = strtok(document, " ");

    // Add each token to the hash table
    while (token != NULL) {
        insert(ht, token);
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    // Create a hash table
    hashtable *ht = create_hashtable(100);

    // Parse a document and add it to the hash table
    char *document = "This is a sample document with some words that appear multiple times.";
    parse_document(ht, document);

    // Print the hash table
    print_hashtable(ht);

    // Free the hash table
    free_hashtable(ht);

    return 0;
}