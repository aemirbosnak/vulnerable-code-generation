//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1024
#define NUM_SENTIMENTS 3

typedef struct {
    char *name;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Positive", 0},
    {"Negative", 0},
    {"Neutral", 0}
};

void analyze_sentiment(char *sentence) {
    int i, j, k;
    char word[MAX_SENTENCE_LENGTH];
    int sentiment_index = -1;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[k] = '\0';
            for (j = 0; j < NUM_SENTIMENTS; j++) {
                if (strcmp(word, sentiments[j].name) == 0) {
                    sentiments[j].score++;
                    sentiment_index = j;
                    break;
                }
            }
            k = 0;
        } else {
            word[k++] = tolower(sentence[i]);
        }
    }

    if (sentiment_index == -1) {
        for (j = 0; j < NUM_SENTIMENTS; j++) {
            if (sentiments[j].score > 0) {
                sentiment_index = j;
                break;
            }
        }
    }

    printf("Sentiment: %s\n", sentiments[sentiment_index].name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    analyze_sentiment(argv[1]);

    return 0;
}