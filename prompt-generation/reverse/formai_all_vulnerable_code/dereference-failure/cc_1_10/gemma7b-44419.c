//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Sentiment_WORDS 100

typedef struct SentimentWord {
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord sentiment_words[MAX_Sentiment_WORDS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -2},
    {"excited", 2},
    {"surprised", 3}
};

int analyze_sentiment(char *text) {
    int sentiment = 0;
    char *words = text;
    char *word;

    while ((word = strsep(words, " ")) != NULL) {
        for (int i = 0; i < MAX_Sentiment_WORDS; i++) {
            if (strcmp(word, sentiment_words[i].word) == 0) {
                sentiment += sentiment_words[i].sentiment;
            }
        }
        words = NULL;
    }

    return sentiment;
}

int main() {
    char *text = "I am shocked by the deliciousness of this food!";
    int sentiment = analyze_sentiment(text);

    if (sentiment > 0) {
        printf("The text is positive.\n");
    } else if (sentiment < 0) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }

    return 0;
}