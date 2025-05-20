//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_LEN 256

typedef struct SentimentAnalysis {
    char sentiment[MAX_SENTIMENT_LEN];
    int sentiment_score;
} SentimentAnalysis;

SentimentAnalysis* analyze_sentiment(char* text) {
    SentimentAnalysis* sa = malloc(sizeof(SentimentAnalysis));
    sa->sentiment_score = 0;

    // Extract sentiment from text
    char* sentiment = strpbrk(text, "anger,sadness,joy,fear,love");
    if (sentiment) {
        strcpy(sa->sentiment, sentiment);
        sa->sentiment_score = sentiment_score(sentiment);
    } else {
        strcpy(sa->sentiment, "Neutral");
    }

    return sa;
}

int sentiment_score(char* sentiment) {
    int score = 0;

    if (strcmp(sentiment, "anger") == 0) {
        score = -2;
    } else if (strcmp(sentiment, "sadness") == 0) {
        score = -1;
    } else if (strcmp(sentiment, "joy") == 0) {
        score = 1;
    } else if (strcmp(sentiment, "fear") == 0) {
        score = 0;
    } else if (strcmp(sentiment, "love") == 0) {
        score = 2;
    }

    return score;
}

int main() {
    char* text = "I am happy and excited about this new project.";
    SentimentAnalysis* sa = analyze_sentiment(text);

    printf("Sentiment: %s\n", sa->sentiment);
    printf("Sentiment Score: %d\n", sa->sentiment_score);

    free(sa);

    return 0;
}