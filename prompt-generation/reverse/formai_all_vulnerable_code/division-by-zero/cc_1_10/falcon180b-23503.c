//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *word;
    int score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {{"love", 4}, {"hate", -4}, {"happy", 3}, {"sad", -3}, {"angry", -2}, {"calm", 2}};

double get_sentiment_score(char *sentence) {
    int i, j, word_length, total_score = 0;
    char *word, *token;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        word_length = strlen(token);
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (word_length == strlen(sentiments[i].word)) {
                if (!strcmp(token, sentiments[i].word)) {
                    total_score += sentiments[i].score;
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    return total_score / strlen(sentence);
}

int main() {
    FILE *fp;
    char ch;
    char sentence[MAX_SENTENCE_LENGTH];
    double sentiment_score;

    fp = fopen(SENTIMENT_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", SENTIMENT_FILE);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            sentiment_score = get_sentiment_score(sentence);
            printf("Sentiment score for sentence \"%s\": %.2f\n", sentence, sentiment_score);
            memset(sentence, 0, sizeof(sentence));
        } else {
            strncat(sentence, &ch, 1);
        }
    }

    fclose(fp);

    return 0;
}