//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define SENTIMENT_THRESHOLD 0.5

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount positive;
    WordCount negative;
    int neutral;
} Sentiment;

Sentiment analyze_sentiment(char *sentence) {
    Sentiment result = {0};
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            word = strtok(NULL, " ");
            continue;
        }
        word = tolower(word);
        WordCount *wc = NULL;
        if (result.positive.count > 0 && result.negative.count > 0) {
            if (result.positive.count >= result.negative.count) {
                wc = &result.positive;
            } else {
                wc = &result.negative;
            }
        } else if (result.positive.count > 0) {
            wc = &result.positive;
        } else if (result.negative.count > 0) {
            wc = &result.negative;
        } else {
            wc = &result.neutral;
        }
        if (strcmp(word, "happy") == 0) {
            wc->count++;
        } else if (strcmp(word, "sad") == 0) {
            wc->count--;
        }
    }
    return result;
}

void print_sentiment(Sentiment sentiment) {
    if (sentiment.positive.count > 0) {
        printf("Positive sentiment detected.\n");
    } else if (sentiment.negative.count > 0) {
        printf("Negative sentiment detected.\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to analyze sentiment:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    Sentiment sentiment = analyze_sentiment(sentence);
    print_sentiment(sentiment);
    return 0;
}