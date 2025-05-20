//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int score;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"confused", 0}
};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(char *sentence) {
    int length = strlen(sentence);
    int i, j;
    int total_score = 0;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        char *word = strtok(sentence, " ");
        while (word!= NULL) {
            int index = get_sentiment_index(word);
            if (index!= -1) {
                total_score += sentiments[index].score;
            }
            word = strtok(NULL, " ");
        }
    }

    return total_score;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, argv[1]);

    int score = analyze_sentiment(sentence);

    printf("Sentiment score: %d\n", score);

    return 0;
}