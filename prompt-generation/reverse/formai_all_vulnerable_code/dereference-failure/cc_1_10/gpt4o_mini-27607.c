//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define HASH_SIZE 1000

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordNode* next;
} WordNode;

typedef struct HashTable {
    WordNode* table[HASH_SIZE];
} HashTable;

// Create a new hash table
HashTable* createHashTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// A simple hash function
unsigned int hash(const char* word) {
    unsigned int hashValue = 0;
    for (; *word; word++) {
        hashValue = (hashValue << 5) + *word; // Hashing algorithm
    }
    return hashValue % HASH_SIZE;
}

// Insert word into the hash table
void insertWord(HashTable* ht, const char* word) {
    unsigned int index = hash(word);
    WordNode* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    WordNode* newNode = malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Function to print the word count
void printWordCount(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordNode* current = ht->table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Clean up memory allocated for the hash table
void cleanUpHashTable(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordNode* current = ht->table[i];
        while (current != NULL) {
            WordNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

// Helper function to split words from a line
bool isWordChar(char c) {
    return (c >= 'A' && c <= 'Z') || 
           (c >= 'a' && c <= 'z') || 
           (c >= '0' && c <= '9') || 
           (c == '\'');
}

void processLine(HashTable* ht, const char* line) {
    char word[MAX_WORD_LENGTH];
    int wordLen = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isWordChar(line[i])) {
            if (wordLen < MAX_WORD_LENGTH - 1) {
                word[wordLen++] = line[i];
            }
        } else {
            if (wordLen > 0) {
                word[wordLen] = '\0';
                insertWord(ht, word);
                wordLen = 0;
            }
        }
    }
    // Check for a word at the end of the line
    if (wordLen > 0) {
        word[wordLen] = '\0';
        insertWord(ht, word);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    
    HashTable* ht = createHashTable();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        processLine(ht, line);
    }

    fclose(file);

    printf("Word Count:\n");
    printWordCount(ht);
    cleanUpHashTable(ht);

    return EXIT_SUCCESS;
}