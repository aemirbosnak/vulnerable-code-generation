//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 10000

typedef struct {
    char* word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency* words;
    int numWords;
} WordFrequencyTable;

void initializeTable(WordFrequencyTable* table) {
    table->words = (WordFrequency*) malloc(MAX_STRING_LENGTH * sizeof(WordFrequency));
    table->numWords = 0;
}

void addWord(WordFrequencyTable* table, char* word) {
    int i;
    for (i = 0; i < table->numWords; i++) {
        if (strcmp(table->words[i].word, word) == 0) {
            table->words[i].frequency++;
            return;
        }
    }
    table->words[table->numWords].word = word;
    table->words[table->numWords].frequency = 1;
    table->numWords++;
}

void printTable(WordFrequencyTable* table) {
    int i;
    for (i = 0; i < table->numWords; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].frequency);
    }
}

bool isSpam(char* emailContent, WordFrequencyTable* table) {
    char* word = strtok(emailContent, " ");
    while (word!= NULL) {
        addWord(table, word);
        word = strtok(NULL, " ");
    }
    int totalWords = table->numWords;
    int spamWords = 0;
    for (int i = 0; i < totalWords; i++) {
        if (table->words[i].frequency >= 3) {
            spamWords++;
        }
    }
    return ((float) spamWords / totalWords) >= 0.3;
}

int main() {
    char* emailContent = "Viagra Cialis Levitra Spam Spam Spam";
    WordFrequencyTable table;
    initializeTable(&table);
    addWord(&table, "Viagra");
    addWord(&table, "Cialis");
    addWord(&table, "Levitra");
    addWord(&table, "Spam");
    if (isSpam(emailContent, &table)) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }
    printTable(&table);
    return 0;
}