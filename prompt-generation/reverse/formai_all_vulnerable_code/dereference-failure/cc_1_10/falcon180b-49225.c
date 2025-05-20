//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 80

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

void freeWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(wordFrequencies[i].word);
    }

    free(wordFrequencies);
}

int main() {
    char inputText[MAX_WORD_LENGTH];

    printf("Enter the text to summarize: ");
    fgets(inputText, MAX_WORD_LENGTH, stdin);

    char *words[MAX_WORD_LENGTH];
    int numWords = 0;

    char *token = strtok(inputText, ",.?!;:\"'");
    while (token!= NULL) {
        words[numWords++] = token;
        token = strtok(NULL, ",.?!;:\"'");
    }

    WordFrequency *wordFrequencies = malloc(numWords * sizeof(WordFrequency));

    for (int i = 0; i < numWords; i++) {
        wordFrequencies[i].word = strdup(words[i]);
        wordFrequencies[i].frequency = 1;
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    int topWords = 10;
    int totalFrequency = 0;

    for (int i = 0; i < numWords && totalFrequency < 80; i++) {
        totalFrequency += wordFrequencies[i].frequency;
        wordFrequencies[i].frequency = totalFrequency;
    }

    printWordFrequencies(wordFrequencies, topWords);

    freeWordFrequencies(wordFrequencies, numWords);

    return 0;
}