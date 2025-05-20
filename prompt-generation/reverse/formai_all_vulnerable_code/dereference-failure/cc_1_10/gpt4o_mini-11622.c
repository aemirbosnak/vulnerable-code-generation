//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define HASH_SIZE 2003

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount *next;
} WordCount;

WordCount *hashTable[HASH_SIZE];

// Hash function to determine the index for a word
unsigned long hash(const char *word) {
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;
}

// Function to convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to add a word to the hash table
void addWord(const char *word) {
    unsigned long index = hash(word);
    WordCount *entry = hashTable[index];

    while (entry != NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    // If word is not found, create a new entry
    WordCount *newEntry = malloc(sizeof(WordCount));
    strncpy(newEntry->word, word, MAX_WORD_LENGTH);
    newEntry->count = 1;
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
}

// Function to clean a word off non-alphabetical characters
void cleanWord(char *word) {
    char *src = word;
    char *dst = word;

    while (*src) {
        if (isalpha((unsigned char)*src) || *src == '\'') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

// Function to read words from standard input
void readWords() {
    char word[MAX_WORD_LENGTH];

    while (scanf("%99s", word) == 1) {
        toLowerCase(word);
        cleanWord(word);
        if (word[0] != '\0') {
            addWord(word);
        }
    }
}

// Function to print all words and their frequencies
void printWordCounts() {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *entry = hashTable[i];
        while (entry != NULL) {
            printf("%s: %d\n", entry->word, entry->count);
            entry = entry->next;
        }
    }
}

// Function to free the memory used by the hash table
void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *entry = hashTable[i];
        while (entry != NULL) {
            WordCount *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

int main() {
    printf("Word Frequency Counter\n");
    printf("======================\n");
    printf("Enter text (Ctrl+D to end input):\n");

    readWords();
    printf("\nWord frequencies:\n");
    printWordCounts();

    freeHashTable();
    return 0;
}