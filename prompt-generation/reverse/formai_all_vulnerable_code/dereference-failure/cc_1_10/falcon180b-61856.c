//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>

#define MAX_TOKENS 1000
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int numWords;
} SentimentAnalysis;

void initSentimentAnalysis(SentimentAnalysis *sa) {
    sa->numWords = 0;
    sa->words = (WordCount *)malloc(MAX_TOKENS * sizeof(WordCount));
}

void addWord(SentimentAnalysis *sa, char *word) {
    WordCount *wc = &sa->words[sa->numWords];
    wc->word = word;
    wc->count = 0;
    sa->numWords++;
}

void updateWordCount(SentimentAnalysis *sa, char *word) {
    int i;
    for (i = 0; i < sa->numWords; i++) {
        if (strcmp(sa->words[i].word, word) == 0) {
            sa->words[i].count++;
            return;
        }
    }
    addWord(sa, word);
}

void analyzeSentiment(SentimentAnalysis *sa, char *sentence) {
    char *token;
    char *delimiters = ",.?!;:";
    token = strtok(sentence, delimiters);
    while (token!= NULL) {
        updateWordCount(sa, token);
        token = strtok(NULL, delimiters);
    }
}

void printWordCounts(SentimentAnalysis *sa) {
    int i;
    for (i = 0; i < sa->numWords; i++) {
        printf("%s: %d\n", sa->words[i].word, sa->words[i].count);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    SentimentAnalysis sa;
    initSentimentAnalysis(&sa);

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    analyzeSentiment(&sa, sentence);
    printWordCounts(&sa);

    return 0;
}