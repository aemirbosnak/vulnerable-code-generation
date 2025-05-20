//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type to represent a word and its frequency
typedef struct {
    char *word;
    int frequency;
} WordFrequency;

// Define a linked list node to store a word and its frequency
typedef struct Node {
    WordFrequency data;
    struct Node *next;
} Node;

// Define a hash table to store the word frequencies
#define HASHTABLE_SIZE 1000
typedef struct {
    Node *table[HASHTABLE_SIZE];
} HashTable;

// Create a new hash table
HashTable *createHashTable() {
    HashTable *table = malloc(sizeof(HashTable));
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        table->table[i] = NULL;
    }
    return table;
}

// Get the hash value for a word
int getHashValue(char *word) {
    int hashValue = 0;
    for (int i = 0; i < strlen(word); i++) {
        hashValue += word[i];
    }
    return hashValue % HASHTABLE_SIZE;
}

// Insert a word and its frequency into the hash table
void insertIntoHashTable(HashTable *table, char *word, int frequency) {
    int hashValue = getHashValue(word);
    Node *node = malloc(sizeof(Node));
    node->data.word = word;
    node->data.frequency = frequency;
    node->next = table->table[hashValue];
    table->table[hashValue] = node;
}

// Search for a word in the hash table and return its frequency
int searchInHashTable(HashTable *table, char *word) {
    int hashValue = getHashValue(word);
    Node *node = table->table[hashValue];
    while (node != NULL) {
        if (strcmp(node->data.word, word) == 0) {
            return node->data.frequency;
        }
        node = node->next;
    }
    return 0;
}

// Print the contents of the hash table
void printHashTable(HashTable *table) {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        Node *node = table->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->data.word, node->data.frequency);
            node = node->next;
        }
    }
}

// Free the memory allocated for the hash table
void freeHashTable(HashTable *table) {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        Node *node = table->table[i];
        while (node != NULL) {
            Node *next = node->next;
            free(node->data.word);
            free(node);
            node = next;
        }
    }
    free(table);
}

// Main function
int main() {
    // Create a hash table to store the word frequencies
    HashTable *table = createHashTable();

    // Open the text file
    FILE *file = fopen("text.txt", "r");

    // Read each word from the file and insert it into the hash table
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        int frequency = searchInHashTable(table, word);
        insertIntoHashTable(table, word, frequency + 1);
    }

    // Close the text file
    fclose(file);

    // Print the contents of the hash table
    printHashTable(table);

    // Free the memory allocated for the hash table
    freeHashTable(table);

    return 0;
}