//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"happy", 1}, {"sad", -1}, {"angry", -2}, {"excited", 2}, {"bored", -1}, {"confused", 0}};

int analyze_sentiment(char *sentence) {
    int total_value = 0;
    int i, j, k;
    char *token;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        for (j = 0; j < strlen(sentiments[i].name); j++) {
            sentiments[i].name[j] = tolower(sentiments[i].name[j]);
        }
    }

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strstr(token, sentiments[i].name)!= NULL) {
                total_value += sentiments[i].value;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return total_value;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_value = analyze_sentiment(sentence);

    if (sentiment_value > 0) {
        printf("The sentence expresses a positive sentiment.\n");
    } else if (sentiment_value < 0) {
        printf("The sentence expresses a negative sentiment.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}