//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
    int sentiment;
} WordSentiment;

typedef struct {
    WordSentiment *words;
    int numWords;
} SentimentAnalysis;

void initializeSentimentAnalysis(SentimentAnalysis *analysis) {
    analysis->numWords = 0;
    analysis->words = NULL;
}

void addWord(SentimentAnalysis *analysis, char *word, int sentiment) {
    if (analysis->numWords == 0) {
        analysis->words = malloc(sizeof(WordSentiment));
        analysis->numWords = 1;
    } else {
        analysis->words = realloc(analysis->words, sizeof(WordSentiment) * (analysis->numWords + 1));
        analysis->numWords++;
    }

    WordSentiment *lastWord = &analysis->words[analysis->numWords - 1];
    lastWord->word = word;
    lastWord->sentiment = sentiment;
}

int main() {
    char input[1000];
    SentimentAnalysis analysis;
    initializeSentimentAnalysis(&analysis);

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int sentiment = 0;
            if (strstr(token, "happy")!= NULL) {
                sentiment = 1;
            } else if (strstr(token, "sad")!= NULL) {
                sentiment = -1;
            }

            addWord(&analysis, token, sentiment);

            token = strtok(NULL, " ");
        }
    }

    printf("Sentiment Analysis:\n");
    for (int i = 0; i < analysis.numWords; i++) {
        WordSentiment *word = &analysis.words[i];
        printf("%s: %d\n", word->word, word->sentiment);
    }

    return 0;
}