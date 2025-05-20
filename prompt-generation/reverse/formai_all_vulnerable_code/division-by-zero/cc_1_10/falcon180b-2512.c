//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"confused", 0}
};

int analyze_sentiment(char *sentence) {
    int total_value = 0;
    int num_sentiments = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(token, sentiments[i].name) == 0) {
                total_value += sentiments[i].value;
                num_sentiments++;
                break;
            }
        }

        if (i == NUM_SENTIMENTS) {
            total_value += analyze_sentiment_recursive(token);
        }

        token = strtok(NULL, " ");
    }

    if (num_sentiments == 0) {
        return total_value / strlen(sentence);
    } else {
        return total_value / num_sentiments;
    }
}

int analyze_sentiment_recursive(char *word) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, sentiments[i].name) == 0) {
            return sentiments[i].value;
        }
    }

    return 0;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

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