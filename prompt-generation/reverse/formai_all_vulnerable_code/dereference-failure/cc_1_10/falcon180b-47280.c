//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 3

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Positive", 1},
    {"Negative", -1},
    {"Neutral", 0}
};

int analyze_sentiment(char *sentence) {
    int length = strlen(sentence);
    int i;
    int total_value = 0;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        int sentiment_value = sentiments[i].value;
        int num_occurrences = 0;

        while ((num_occurrences < length) &&
               (strcasecmp(sentence + num_occurrences, sentiments[i].name) == 0)) {
            num_occurrences += strlen(sentiments[i].name);
            total_value += sentiment_value;
        }
    }

    return total_value;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int sentiment_value = analyze_sentiment(sentence);

    if (sentiment_value > 0) {
        printf("The sentiment is positive.\n");
    } else if (sentiment_value < 0) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }

    return 0;
}