//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 3

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *word;
    float sentiment_score;
} SentimentWord;

SentimentWord sentiments[NUM_SENTIMENTS] = {{"happy", 1.0}, {"sad", -1.0}, {"angry", -1.0}};

void tokenize_sentence(char *sentence, char **tokens) {
    int num_tokens = 0;
    char *token;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

void analyze_sentiment(char *sentence, WordCount *word_counts, SentimentWord *sentiments) {
    int i, j;
    char *token;
    float total_sentiment_score = 0.0;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < NUM_SENTIMENTS; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                total_sentiment_score += sentiments[i].sentiment_score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        sentiments[i].sentiment_score = total_sentiment_score / NUM_SENTIMENTS;
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    char *sentence;
    WordCount word_counts[MAX_WORD_LENGTH];
    int num_words = 0;
    int i;

    printf("Enter a block of text:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    sentence = strtok(input_text, ".");
    while (sentence!= NULL) {
        tokenize_sentence(sentence, word_counts[num_words].word);
        num_words++;
        sentence = strtok(NULL, ".");
    }

    for (i = 0; i < num_words; i++) {
        analyze_sentiment(word_counts[i].word, &word_counts[i], sentiments);
    }

    printf("Word Counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    printf("\nSentiment Analysis:\n");
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %.2f\n", sentiments[i].word, sentiments[i].sentiment_score);
    }

    return 0;
}