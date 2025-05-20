//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int total_sentences;
    int total_words;
} SentimentAnalysis;

void initialize_sentiment_analysis(SentimentAnalysis *analysis) {
    analysis->words = NULL;
    analysis->num_words = 0;
    analysis->total_sentences = 0;
    analysis->total_words = 0;
}

void add_word(SentimentAnalysis *analysis, const char *word) {
    Word *new_word = malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->count = 1;
    analysis->words = realloc(analysis->words, sizeof(Word) * (analysis->num_words + 1));
    analysis->words[analysis->num_words++] = *new_word;
    free(new_word);
}

void increment_word_count(SentimentAnalysis *analysis, const char *word) {
    int i;
    for (i = 0; i < analysis->num_words; i++) {
        if (strcmp(analysis->words[i].word, word) == 0) {
            analysis->words[i].count++;
            return;
        }
    }
    add_word(analysis, word);
}

void print_word_counts(SentimentAnalysis *analysis) {
    int i;
    for (i = 0; i < analysis->num_words; i++) {
        printf("%s: %d\n", analysis->words[i].word, analysis->words[i].count);
    }
}

void analyze_sentiment(SentimentAnalysis *analysis, const char *sentence) {
    char *token;
    char *saveptr;
    int i;

    token = strtok_r(sentence, ",.!?;:\"'", &saveptr);
    while (token!= NULL) {
        increment_word_count(analysis, token);
        token = strtok_r(NULL, ",.!?;:\"'", &saveptr);
    }
    analysis->total_sentences++;
    analysis->total_words += strlen(sentence);
}

void destroy_sentiment_analysis(SentimentAnalysis *analysis) {
    int i;
    for (i = 0; i < analysis->num_words; i++) {
        free(analysis->words[i].word);
    }
    free(analysis->words);
}

int main() {
    SentimentAnalysis analysis;
    char sentence[MAX_SENTENCE_LENGTH];
    int num_sentences = 0;

    initialize_sentiment_analysis(&analysis);

    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (++num_sentences > MAX_SENTENCES) {
            printf("Error: Maximum number of sentences exceeded.\n");
            break;
        }
        analyze_sentiment(&analysis, sentence);
    }

    print_word_counts(&analysis);

    destroy_sentiment_analysis(&analysis);

    return 0;
}