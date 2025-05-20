//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"joy", 1},
    {"sadness", -1},
    {"anger", -1},
    {"fear", -1},
    {"love", 1},
    {"hate", -1}
};

int getSentimentValue(char *sentimentName) {
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiments[i].name, sentimentName) == 0) {
            return sentiments[i].value;
        }
    }

    return 0;
}

int analyzeSentence(char *sentence) {
    int length = strlen(sentence);
    int i;
    int totalValue = 0;

    if (length > MAX_SENTENCE_LENGTH) {
        return 0;
    }

    for (i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            char word[MAX_SENTENCE_LENGTH];
            int j;

            for (j = i; isalpha(sentence[j]); j++) {
                word[j - i] = tolower(sentence[j]);
            }
            word[j - i] = '\0';

            int sentimentValue = getSentimentValue(word);

            if (sentimentValue!= 0) {
                totalValue += sentimentValue;
            }
        }
    }

    return totalValue;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char *sentence = argv[1];
    int value = analyzeSentence(sentence);

    if (value == 0) {
        printf("Invalid sentence.\n");
    } else {
        printf("Sentiment analysis: %d\n", value);
    }

    return 0;
}