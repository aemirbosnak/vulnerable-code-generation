//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTIMENT 10

typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

WordSentiment words[MAX_WORDS];
int numWords = 0;

void loadSentimentDictionary() {
    FILE *fp = fopen("sentiment.txt", "r");
    if (fp == NULL) {
        perror("Error opening sentiment dictionary");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, ",");
        int sentiment = atoi(strtok(NULL, ","));

        words[numWords].word = strdup(word);
        words[numWords].sentiment = sentiment;
        numWords++;
    }

    fclose(fp);
}

int analyzeSentiment(char *text) {
    int totalSentiment = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                totalSentiment += words[i].sentiment;
            }
        }
        word = strtok(NULL, " ");
    }

    return totalSentiment;
}

int main() {
    loadSentimentDictionary();

    char text[1024];
    printf("Enter text to analyze: ");
    fgets(text, sizeof(text), stdin);

    int sentiment = analyzeSentiment(text);

    if (sentiment > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}