//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 6

typedef struct {
    char *word;
    int sentimentValue;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"disappointed", -1},
    {"content", 1}
};

int getSentimentValue(char *word) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, sentiments[i].word) == 0) {
            return sentiments[i].sentimentValue;
        }
    }
    return 0;
}

int getAverageSentiment(char *sentence) {
    int i, j;
    int totalSentimentValue = 0;
    char *token;
    token = strtok(sentence, " ");
    while (token!= NULL) {
        totalSentimentValue += getSentimentValue(token);
        token = strtok(NULL, " ");
    }
    return totalSentimentValue / strlen(sentence);
}

int main() {
    FILE *file;
    char sentence[MAX_SENTENCE_LENGTH];
    int numPositive = 0, numNegative = 0, numNeutral = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, file)!= NULL) {
        int sentimentValue = getAverageSentiment(sentence);
        if (sentimentValue > 0) {
            numPositive++;
        } else if (sentimentValue < 0) {
            numNegative++;
        } else {
            numNeutral++;
        }
    }

    printf("Number of positive sentences: %d\n", numPositive);
    printf("Number of negative sentences: %d\n", numNegative);
    printf("Number of neutral sentences: %d\n", numNeutral);

    fclose(file);
    return 0;
}