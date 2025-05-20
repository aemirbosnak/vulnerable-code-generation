//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return wordA->frequency - wordB->frequency;
}

void printWordFrequency(WordFrequency *wordFrequency, int count) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

void searchWords(char *sentence, char *word) {
    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    int wordCount = 0;
    WordFrequency *wordFrequency = malloc(sizeof(WordFrequency) * MAX_WORD_LENGTH);

    char *token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        if (strcasecmp(token, word) == 0) {
            wordFrequency[wordCount].word = word;
            wordFrequency[wordCount].frequency++;
        }
        token = strtok(NULL, ",.!?;:");
        wordCount++;
    }

    qsort(wordFrequency, wordCount, sizeof(WordFrequency), compareWords);
    printWordFrequency(wordFrequency, wordCount);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to search for: ");
    fgets(word, MAX_WORD_LENGTH, stdin);

    searchWords(sentence, word);

    return 0;
}