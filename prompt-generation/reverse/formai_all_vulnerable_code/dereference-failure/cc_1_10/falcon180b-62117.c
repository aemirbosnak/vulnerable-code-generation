//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 6

typedef struct {
    char* word;
    int sentiment;
} WordSentiment;

void loadSentimentWords(WordSentiment sentiments[], int numSentiments) {
    FILE* fp = fopen("sentiment_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open sentiment_words.txt\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_SENTENCE_LENGTH];
    while (fgets(line, MAX_SENTENCE_LENGTH, fp)!= NULL && i < numSentiments) {
        char* word = strtok(line, " ");
        sentiments[i].word = strdup(word);
        sentiments[i].sentiment = i;
        i++;
    }

    fclose(fp);
}

int analyzeSentiment(char* sentence, WordSentiment sentiments[], int numSentiments, int* totalSentiment) {
    int sentiment = 0;
    int numWords = 0;

    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        int j;
        for (j = 0; j < numSentiments; j++) {
            if (strcmp(word, sentiments[j].word) == 0) {
                sentiment += sentiments[j].sentiment;
                break;
            }
        }

        if (j == numSentiments) {
            sentiment += 0;
        }

        numWords++;
        word = strtok(NULL, " ");
    }

    *totalSentiment = sentiment / numWords;
    return sentiment;
}

int main() {
    WordSentiment sentiments[NUM_SENTIMENTS];
    loadSentimentWords(sentiments, NUM_SENTIMENTS);

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int totalSentiment;
    int sentiment = analyzeSentiment(sentence, sentiments, NUM_SENTIMENTS, &totalSentiment);

    printf("Sentiment analysis: %d (%.2f)\n", sentiment, totalSentiment);

    return 0;
}