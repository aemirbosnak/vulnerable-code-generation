//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 1000
#define HASH_TABLE_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word *words;
    int numWords;
} HashTable;

HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->numWords = 0;
    hashTable->words = malloc(HASH_TABLE_SIZE * sizeof(Word));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable->words[i].word[0] = '\0';
        hashTable->words[i].count = 0;
    }
    return hashTable;
}

int hash(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]) - 'a';
    }
    return sum % HASH_TABLE_SIZE;
}

void addWord(HashTable *hashTable, char *word) {
    int index = hash(word);
    Word *wordPtr = &hashTable->words[index];
    if (wordPtr->word[0] == '\0') {
        strcpy(wordPtr->word, word);
        wordPtr->count = 1;
        hashTable->numWords++;
    } else if (strcmp(wordPtr->word, word) == 0) {
        wordPtr->count++;
    }
}

void printHashTable(HashTable *hashTable) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Word *wordPtr = &hashTable->words[i];
        if (wordPtr->word[0]!= '\0') {
            printf("%s %d\n", wordPtr->word, wordPtr->count);
        }
    }
}

int main() {
    HashTable *hashTable = createHashTable();
    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(input, " ");
        while (word!= NULL) {
            addWord(hashTable, word);
            word = strtok(NULL, " ");
        }
    }
    printHashTable(hashTable);
    return 0;
}