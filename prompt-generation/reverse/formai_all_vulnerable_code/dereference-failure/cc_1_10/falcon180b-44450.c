//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Sentiment {
    char* text;
    int sentiment;
};

typedef struct Sentiment Sentiment;

Sentiment* createSentiment(char* text) {
    Sentiment* sentiment = malloc(sizeof(Sentiment));
    sentiment->text = strdup(text);
    sentiment->sentiment = 0;
    return sentiment;
}

void analyzeSentiment(Sentiment* sentiment) {
    char* words[1000];
    int count = 0;
    char* token = strtok(sentiment->text, " ");
    while (token!= NULL) {
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < count; i++) {
        char* word = words[i];
        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0) {
            positive++;
        } else if (strcmp(word, "sad") == 0 || strcmp(word, "angry") == 0) {
            negative++;
        }
    }

    if (positive > negative) {
        sentiment->sentiment = 1;
    } else if (negative > positive) {
        sentiment->sentiment = -1;
    } else {
        sentiment->sentiment = 0;
    }

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
}

void printSentiment(Sentiment* sentiment) {
    if (sentiment->sentiment == 1) {
        printf("The sentiment is positive.\n");
    } else if (sentiment->sentiment == -1) {
        printf("The sentiment is negative.\n");
    } else {
        printf("The sentiment is neutral.\n");
    }
}

int main() {
    char* text = "I am happy today, but yesterday I was sad.";
    Sentiment* sentiment = createSentiment(text);
    analyzeSentiment(sentiment);
    printSentiment(sentiment);

    free(sentiment->text);
    free(sentiment);
    return 0;
}