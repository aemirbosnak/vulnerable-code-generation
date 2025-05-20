//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Joy", 0},
    {"Sadness", 0},
    {"Anger", 0},
    {"Fear", 0},
    {"Surprise", 0},
    {"Disgust", 0}
};

char *tokenize(char *sentence) {
    char *token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        token = strtok(NULL, ",.!?;:");
    }
    return sentence;
}

void analyze_sentiment(char *sentence) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        sentiments[i].score = 0;
    }

    char *token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        int j;
        for (j = 0; j < NUM_SENTIMENTS; j++) {
            if (strcmp(token, sentiments[j].name) == 0) {
                sentiments[j].score++;
                break;
            }
        }
        token = strtok(NULL, ",.!?;:");
    }
}

void print_sentiments(void) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].name, sentiments[i].score);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    analyze_sentiment(sentence);
    print_sentiments();

    return 0;
}