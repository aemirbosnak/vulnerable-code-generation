//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *word;
    int score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {
    {"love", 4},
    {"hate", -4},
    {"happy", 3},
    {"sad", -3},
    {"excited", 2},
    {"bored", -2}
};

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int getSentimentScore(char *sentence) {
    int score = 0;
    char *word;
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        word = tolower(token);
        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(word, sentiments[i].word) == 0) {
                score += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return score;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int score = getSentimentScore(sentence);

    if (score > 0) {
        printf("Positive\n");
    } else if (score < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}