//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;
    return strcmp(wordA->word, wordB->word);
}

void readSentence(char sentence[]) {
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
}

void tokenizeSentence(char sentence[], char words[]) {
    char *token = strtok(sentence, ",.?!;:\"'");
    int wordCount = 0;
    while (token!= NULL && wordCount < MAX_WORDS) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void countWordFrequencies(char words[], int wordCount, WordFrequency frequencies[]) {
    for (int i = 0; i < wordCount; i++) {
        frequencies[i].count = 0;
        strcpy(frequencies[i].word, words[i]);
    }
}

void printWordFrequencies(WordFrequency frequencies[], int wordCount) {
    qsort(frequencies, wordCount, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency frequencies[MAX_WORDS];

    readSentence(sentence);
    tokenizeSentence(sentence, words);
    countWordFrequencies(words, strlen(sentence), frequencies);
    printWordFrequencies(frequencies, strlen(sentence));

    return 0;
}