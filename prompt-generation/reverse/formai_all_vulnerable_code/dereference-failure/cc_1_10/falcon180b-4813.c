//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *sentiment;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"Positive", 1},
    {"Negative", -1},
    {"Neutral", 0},
    {"Joy", 1},
    {"Sadness", -1},
    {"Anger", -1}
};

int analyze_sentiment(char *sentence) {
    int i, j, k, num_words, sentiment_value = 0;
    char *word, **tokens;

    // Tokenize the sentence
    tokens = malloc(MAX_SENTENCE_LENGTH * sizeof(char*));
    num_words = 0;
    word = strtok(sentence, " ");
    while (word!= NULL) {
        tokens[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Analyze each word and its sentiment
    for (i = 0; i < num_words; i++) {
        for (j = 0; j < NUM_SENTIMENTS; j++) {
            k = strlen(tokens[i]);
            if (k > strlen(sentiments[j].sentiment))
                continue;
            if (strncasecmp(tokens[i], sentiments[j].sentiment, k) == 0) {
                if (j == 0 || j == 2 || j == 4)
                    sentiment_value += sentiments[j].value;
                else
                    sentiment_value -= sentiments[j].value;
                break;
            }
        }
    }

    // Return the overall sentiment value
    if (sentiment_value > 0)
        return 1;
    else if (sentiment_value < 0)
        return -1;
    else
        return 0;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    // Get input from user
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Analyze the sentiment and print the result
    int sentiment_value = analyze_sentiment(sentence);
    if (sentiment_value > 0)
        printf("Positive\n");
    else if (sentiment_value < 0)
        printf("Negative\n");
    else
        printf("Neutral\n");

    return 0;
}