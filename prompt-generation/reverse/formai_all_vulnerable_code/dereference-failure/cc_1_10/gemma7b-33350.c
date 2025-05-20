//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SENT_MAX 512
#define LEX_MAX 1024

typedef struct SentimentNode {
    struct SentimentNode* next;
    char sentiment[SENT_MAX];
    char text[LEX_MAX];
} SentimentNode;

SentimentNode* sentiment_new(char* text) {
    SentimentNode* node = (SentimentNode*)malloc(sizeof(SentimentNode));
    node->next = NULL;
    strcpy(node->sentiment, text);
    return node;
}

void sentiment_analyze(SentimentNode* node) {
    int positive = 0;
    int negative = 0;
    int neutral = 0;

    for (char* word = node->text; *word; word++) {
        if (isupper(*word)) {
            *word = tolower(*word);
        }

        if (strcmp(word, "good") == 0) {
            positive++;
        } else if (strcmp(word, "bad") == 0) {
            negative++;
        } else if (strcmp(word, "neutral") == 0) {
            neutral++;
        }
    }

    int sentiment = (positive - negative) * 100 / (positive + negative + neutral);

    printf("Sentiment score: %d%%", sentiment);
}

int main() {
    SentimentNode* node = sentiment_new("I love this movie!");

    sentiment_analyze(node);

    return 0;
}