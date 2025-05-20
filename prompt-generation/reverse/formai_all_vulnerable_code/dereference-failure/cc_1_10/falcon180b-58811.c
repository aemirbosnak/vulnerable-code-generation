//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Joy", 1},
    {"Sadness", -1},
    {"Anger", -2},
    {"Fear", -3},
    {"Surprise", -2},
    {"Disgust", -4}
};

void tokenize(char *sentence, char **tokens, int *num_tokens) {
    char *token = strtok(sentence, " ");
    int i = 0;

    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    *num_tokens = i;
}

int analyze_sentiment(char *sentence) {
    int sentiment_score = 0;
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        int word_count = 0;

        char *token;
        int num_tokens;
        tokenize(sentence, &token, &num_tokens);

        while (token!= NULL) {
            if (strcmp(token, sentiments[i].name) == 0) {
                word_count++;
            }

            token = strtok(NULL, " ");
        }

        if (word_count > 0) {
            sentiment_score += sentiments[i].value * word_count;
        }
    }

    return sentiment_score;
}

int main() {
    char input_sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence to analyze its sentiment:\n");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_score = analyze_sentiment(input_sentence);

    if (sentiment_score > 0) {
        printf("The sentence expresses positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The sentence expresses negative sentiment.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}