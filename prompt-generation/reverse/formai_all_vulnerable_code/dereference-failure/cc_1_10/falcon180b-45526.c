//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char* word;
    int count;
} WordFrequency;

typedef struct {
    WordFrequency* words;
    int num_words;
} SentimentAnalysisResult;

SentimentAnalysisResult analyze_sentiment(char* sentence) {
    SentimentAnalysisResult result = {NULL, 0};

    // Tokenize the sentence
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        WordFrequency* word = malloc(sizeof(WordFrequency));
        strcpy(word->word, token);
        word->count = 1;
        result.words = realloc(result.words, sizeof(WordFrequency) * ++result.num_words);
        result.words[result.num_words - 1] = *word;
        free(word);
        token = strtok(NULL, " ");
    }

    return result;
}

void print_sentiment_analysis(SentimentAnalysisResult result) {
    printf("Sentiment Analysis:\n");
    for (int i = 0; i < result.num_words; i++) {
        printf("%s: %d\n", result.words[i].word, result.words[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    char* trimmed = strtok(sentence, "\n");

    SentimentAnalysisResult analysis = analyze_sentiment(trimmed);
    print_sentiment_analysis(analysis);

    return 0;
}