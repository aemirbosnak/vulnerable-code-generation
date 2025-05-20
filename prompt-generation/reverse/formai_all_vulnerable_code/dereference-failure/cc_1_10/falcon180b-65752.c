//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define SENTIMENT_FILE "sentiment.txt"
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int sentiment;
} SentimentWord;

typedef struct {
    SentimentWord *words;
    int numWords;
} SentimentDictionary;

SentimentDictionary *createDictionary() {
    SentimentDictionary *dict = (SentimentDictionary *) malloc(sizeof(SentimentDictionary));
    dict->words = (SentimentWord *) malloc(sizeof(SentimentWord));
    dict->numWords = 0;
    return dict;
}

void loadDictionary(SentimentDictionary *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open sentiment file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        int sentiment = atoi(strtok(NULL, " "));
        dict->words = (SentimentWord *) realloc(dict->words, sizeof(SentimentWord) * (dict->numWords + 1));
        dict->words[dict->numWords].word = strdup(word);
        dict->words[dict->numWords].sentiment = sentiment;
        dict->numWords++;
    }

    fclose(file);
}

int getSentiment(SentimentDictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->numWords; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return dict->words[i].sentiment;
        }
    }
    return 0;
}

void analyzeSentiment(SentimentDictionary *dict, char *text) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int sentiment = getSentiment(dict, token);
        if (sentiment > 0) {
            printf("Positive: %s\n", token);
        } else if (sentiment < 0) {
            printf("Negative: %s\n", token);
        } else {
            printf("Neutral: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    SentimentDictionary *dict = createDictionary();
    loadDictionary(dict, SENTIMENT_FILE);

    char text[] = "I love programming in C. It is a great language for beginners.";
    analyzeSentiment(dict, text);

    free(dict->words);
    free(dict);
    return 0;
}