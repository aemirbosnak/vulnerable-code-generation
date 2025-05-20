//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NUM_RULES 10

// Sentiment analysis rules
typedef struct {
    char *word;
    int sentiment;
} Rule;

Rule rules[NUM_RULES] = {
    {"good", 1}, {"great", 1}, {"happy", 1}, {"love", 1},
    {"joy", 1}, {"excited", 1}, {"marvelous", 1}, {"amazing", 1},
    {"wonderful", 1}, {"fantastic", 1},
    {"bad", -1}, {"terrible", -1}, {"sad", -1}, {"hate", -1},
    {"angry", -1}, {"frustrated", -1}, {"disgusting", -1}, {"awful", -1},
    {"miserable", -1}, {"unhappy", -1}, {"depressing", -1}, {"painful", -1}
};

int analyze_sentiment(char *text) {
    int sentiment = 0;
    char word[MAX_LINE_LENGTH];
    int len;
    char *token;

    // Tokenize input text
    strcpy(word, strtok(text, " .,\n"));
    while (word[0] != '\0') {
        for (int i = 0; i < NUM_RULES; i++) {
            len = strlen(rules[i].word);
            if (strncmp(word, rules[i].word, len) == 0) {
                sentiment += rules[i].sentiment;
                break;
            }
        }
        strcpy(text, strtok(NULL, " .,\n"));
        strcpy(word, strtok(NULL, " .,\n"));
    }

    // Calculate final sentiment score
    return sentiment / NUM_RULES;
}

int main() {
    char input[MAX_LINE_LENGTH];

    printf("Enter text to analyze sentiment: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    int sentiment = analyze_sentiment(input);

    if (sentiment > 0) {
        printf("Sentiment is positive.\n");
    } else if (sentiment < 0) {
        printf("Sentiment is negative.\n");
    } else {
        printf("Sentiment is neutral.\n");
    }

    return 0;
}