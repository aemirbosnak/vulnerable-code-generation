//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 5000

// Node structure for the linked list
typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordNode* next;
} WordNode;

// Hash table for counting word frequencies
typedef struct {
    WordNode* table[HASH_TABLE_SIZE];
} HashTable;

// Function prototypes
unsigned long hash(const char* word);
HashTable* createHashTable();
void destroyHashTable(HashTable* ht);
void insertWord(HashTable* ht, const char* word);
void printFrequencies(HashTable* ht);
void toLowerCase(char* str);
void processFile(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    processFile(argv[1]);
    return EXIT_SUCCESS;
}

// Hash function to generate a hash value for a word
unsigned long hash(const char* word) {
    unsigned long hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + tolower(*word++);
    }
    return hashValue % HASH_TABLE_SIZE;
}

// Create a new hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Destroy the hash table and free memory
void destroyHashTable(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordNode* node = ht->table[i];
        while (node != NULL) {
            WordNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(ht);
}

// Insert a word into the hash table
void insertWord(HashTable* ht, const char* word) {
    unsigned long hashIndex = hash(word);
    WordNode* node = ht->table[hashIndex];
    
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }

    // Word not found, create a new node
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->count = 1;
    newNode->next = ht->table[hashIndex];
    ht->table[hashIndex] = newNode;
}

// Print the word frequencies from the hash table
void printFrequencies(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        WordNode* node = ht->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }
}

// Convert a string to lower case
void toLowerCase(char* str) {
    for (char* p = str; *p; p++) {
        *p = tolower(*p);
    }
}

// Process the file and count word frequencies
void processFile(const char* filename) {
    HashTable* ht = createHashTable();
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        destroyHashTable(ht);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) == 1) {
        toLowerCase(word);
        insertWord(ht, word);
    }

    fclose(file);
    printFrequencies(ht);
    destroyHashTable(ht);
}