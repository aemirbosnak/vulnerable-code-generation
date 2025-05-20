//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define MAX_WORD_LENGTH 100

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount* next;
} WordCount;

WordCount* hashTable[TABLE_SIZE];

unsigned int hash(const char* word) {
    unsigned long hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + (*word++);
    }
    return hashValue % TABLE_SIZE;
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void insertWord(const char* word) {
    unsigned int index = hash(word);
    WordCount* entry = hashTable[index];
    
    while (entry != NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    WordCount* newEntry = (WordCount*)malloc(sizeof(WordCount));
    strcpy(newEntry->word, word);
    newEntry->count = 1;
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordCount* entry = hashTable[i];
        while (entry != NULL) {
            WordCount* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

void printWordCounts() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordCount* entry = hashTable[i];
        while (entry != NULL) {
            printf("%s: %d\n", entry->word, entry->count);
            entry = entry->next;
        }
    }
}

void countWordsInFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        insertWord(word);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordsInFile(argv[1]);
    printWordCounts();
    freeHashTable();

    return EXIT_SUCCESS;
}