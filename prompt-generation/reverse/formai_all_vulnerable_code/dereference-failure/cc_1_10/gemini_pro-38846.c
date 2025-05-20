//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
// Galactic Word Frequency Counter v1.0
// By Dr. Xyzzy Nebula and the Intergalactic Programming Guild

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    int freq;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **buckets;
    int size;
} HashTable;

// Function to hash a string
unsigned int hash(char *str) {
    unsigned int hashValue = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hashValue += str[i];
    }
    return hashValue;
}

// Function to create a new hash table
HashTable *createHashTable(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (Node **)malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

// Function to insert a word into the hash table
void insert(HashTable *table, char *word) {
    unsigned int hashValue = hash(word);
    int index = hashValue % table->size;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->freq = 1;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

// Function to search for a word in the hash table
Node *search(HashTable *table, char *word) {
    unsigned int hashValue = hash(word);
    int index = hashValue % table->size;
    Node *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the hash table
void printHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *current = table->buckets[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->freq);
            current = current->next;
        }
    }
}

int main() {
    // Create a new hash table with a size of 10000
    HashTable *table = createHashTable(10000);

    // Insert some words into the hash table
    insert(table, "Hello");
    insert(table, "World");
    insert(table, "This");
    insert(table, "Is");
    insert(table, "A");
    insert(table, "Hash");
    insert(table, "Table");

    // Print the hash table
    printHashTable(table);

    return 0;
}