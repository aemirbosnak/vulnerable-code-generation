//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *word_counts;
    int num_words;
} SentimentAnalysis;

void initialize_word_counts(SentimentAnalysis *analysis) {
    analysis->word_counts = malloc(MAX_WORDS * sizeof(WordCount));
    analysis->num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        analysis->word_counts[i].word = malloc(MAX_WORD_LENGTH * sizeof(char));
        analysis->word_counts[i].count = 0;
    }
}

void add_word(SentimentAnalysis *analysis, char *word) {
    for (int i = 0; i < analysis->num_words; i++) {
        if (strcmp(analysis->word_counts[i].word, word) == 0) {
            analysis->word_counts[i].count++;
            return;
        }
    }
    if (analysis->num_words >= MAX_WORDS) {
        printf("Error: maximum number of words exceeded\n");
        exit(1);
    }
    analysis->word_counts[analysis->num_words].word = strdup(word);
    analysis->word_counts[analysis->num_words].count = 1;
    analysis->num_words++;
}

void print_word_counts(SentimentAnalysis *analysis) {
    for (int i = 0; i < analysis->num_words; i++) {
        printf("%s: %d\n", analysis->word_counts[i].word, analysis->word_counts[i].count);
    }
}

void free_word_counts(SentimentAnalysis *analysis) {
    for (int i = 0; i < analysis->num_words; i++) {
        free(analysis->word_counts[i].word);
    }
    free(analysis->word_counts);
}

int main() {
    SentimentAnalysis analysis;
    initialize_word_counts(&analysis);
    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *word = strtok(input, ",.?!;:");
        while (word!= NULL) {
            add_word(&analysis, word);
            word = strtok(NULL, ",.?!;:");
        }
    }
    print_word_counts(&analysis);
    free_word_counts(&analysis);
    return 0;
}