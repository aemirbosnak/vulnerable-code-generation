//Falcon-180B DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 1000
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readSentence(char sentence[]) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LEN, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
}

void tokenizeSentence(char sentence[], char words[]) {
    char *token = strtok(sentence, " \t\n\r\f\v,.?!;:");
    int wordCount = 0;

    while (token!= NULL) {
        strcpy(words[wordCount], token);
        wordCount++;

        if (wordCount >= MAX_WORDS) {
            printf("Error: Too many words in the sentence.\n");
            exit(1);
        }

        token = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
}

void countWordFrequencies(char words[], int numWords, WordFrequency frequencies[]) {
    for (int i = 0; i < numWords; i++) {
        frequencies[i].word[0] = '\0';
    }

    for (int i = 0; i < numWords; i++) {
        strcpy(frequencies[i].word, words[i]);
        frequencies[i].count = 1;
    }

    qsort(frequencies, numWords, sizeof(WordFrequency), compareWords);
}

void printWordFrequencies(WordFrequency frequencies[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    WordFrequency frequencies[MAX_WORDS];

    readSentence(sentence);
    tokenizeSentence(sentence, words);
    countWordFrequencies(words, strlen(sentence), frequencies);
    printWordFrequencies(frequencies, strlen(sentence));

    return 0;
}