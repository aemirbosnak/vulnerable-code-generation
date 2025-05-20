//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *sentiment;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Extremely Negative", -3},
                                        {"Negative", -2},
                                        {"Neutral", 0},
                                        {"Positive", 2},
                                        {"Extremely Positive", 3}};

int get_sentiment_index(char *sentiment) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiments[i].sentiment, sentiment) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentence(char *sentence) {
    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Sentence too long.\n");
        return -1;
    }

    int sentiment_index = get_sentiment_index(sentence);
    if (sentiment_index == -1) {
        printf("Invalid sentiment.\n");
        return -1;
    }

    return sentiments[sentiment_index].value;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char *sentence = argv[1];
    int result = analyze_sentence(sentence);

    if (result == -1) {
        return 1;
    }

    printf("Sentiment analysis result: %d\n", result);
    return 0;
}