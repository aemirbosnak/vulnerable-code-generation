//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define NUM_SENTIMENTS 6

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *word;
    int value;
} SentimentWord;

SentimentWord sentimentWords[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"calm", 1}
};

int getSentimentValue(char *word) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, sentimentWords[i].word) == 0) {
            return sentimentWords[i].value;
        }
    }
    return 0;
}

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return wordA->count - wordB->count;
}

int main() {
    FILE *inputFile;
    char inputLine[MAX_WORD_LENGTH];
    char *token;
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(inputLine, MAX_WORD_LENGTH, inputFile)!= NULL) {
        token = strtok(inputLine, " ");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                int wordIndex = 0;
                while (wordIndex < numWords && strcmp(wordCounts[wordIndex].word, token)!= 0) {
                    wordIndex++;
                }
                if (wordIndex == numWords) {
                    if (numWords == MAX_WORD_LENGTH) {
                        printf("Error: Too many words.\n");
                        exit(1);
                    }
                    strcpy(wordCounts[numWords].word, token);
                    wordCounts[numWords].count = 1;
                    numWords++;
                } else {
                    wordCounts[wordIndex].count++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    int totalSentiment = 0;
    for (i = 0; i < numWords; i++) {
        totalSentiment += getSentimentValue(wordCounts[i].word) * wordCounts[i].count;
    }

    printf("Total sentiment: %d\n", totalSentiment);

    fclose(inputFile);
    return 0;
}