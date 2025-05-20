//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *wordFrequencies;
    int numWords;
} WordFrequencyTable;

void initializeWordFrequencyTable(WordFrequencyTable *table) {
    table->wordFrequencies = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));
    table->numWords = 0;
}

void addWordFrequency(WordFrequencyTable *table, char *word) {
    if (table->numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }

    WordFrequency *wordFrequency = &table->wordFrequencies[table->numWords];
    strcpy(wordFrequency->word, word);
    wordFrequency->frequency = 1;

    table->numWords++;
}

void printWordFrequencyTable(WordFrequencyTable *table) {
    printf("Word\tFrequency\n");

    for (int i = 0; i < table->numWords; i++) {
        printf("%s\t%d\n", table->wordFrequencies[i].word, table->wordFrequencies[i].frequency);
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    WordFrequencyTable table;

    initializeWordFrequencyTable(&table);

    printf("Enter text:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    word = strtok(input, " \n\r\t,.!?;:");

    while (word!= NULL) {
        if (strlen(word) > 0) {
            addWordFrequency(&table, word);
        }

        word = strtok(NULL, " \n\r\t,.!?;:");
    }

    printWordFrequencyTable(&table);

    return 0;
}