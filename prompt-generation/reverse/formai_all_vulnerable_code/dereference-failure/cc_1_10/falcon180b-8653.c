//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define NUM_SENTIMENTS 6
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} WordScore;

typedef struct {
    int numWords;
    WordScore words[MAX_SENTENCE_LENGTH];
} Sentiment;

Sentiment* loadSentiments(void) {
    FILE* fp = fopen(SENTIMENT_FILE, "r");
    if (fp == NULL) {
        printf("Error loading sentiment file.\n");
        exit(1);
    }

    Sentiment* sentiments = malloc(sizeof(Sentiment) * NUM_SENTIMENTS);
    for (int i = 0; i < NUM_SENTIMENTS; i++) {
        char line[MAX_SENTENCE_LENGTH];
        if (fgets(line, MAX_SENTENCE_LENGTH, fp) == NULL) {
            printf("Error reading sentiment file.\n");
            exit(1);
        }

        int numWords = 0;
        char* word = strtok(line, " ");
        while (word!= NULL) {
            if (numWords >= MAX_SENTENCE_LENGTH) {
                break;
            }

            strcpy(sentiments[i].words[numWords].word, word);
            sentiments[i].words[numWords].score = 0;

            numWords++;
            word = strtok(NULL, " ");
        }

        sentiments[i].numWords = numWords;
    }

    fclose(fp);
    return sentiments;
}

void analyzeSentiment(char* sentence, Sentiment* sentiments) {
    int totalScore = 0;

    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        bool found = false;
        for (int i = 0; i < NUM_SENTIMENTS; i++) {
            for (int j = 0; j < sentiments[i].numWords; j++) {
                if (strcmp(word, sentiments[i].words[j].word) == 0) {
                    totalScore += sentiments[i].words[j].score;
                    found = true;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        word = strtok(NULL, " ");
    }

    printf("Total score: %d\n", totalScore);
}

int main(void) {
    Sentiment* sentiments = loadSentiments();

    char sentence[MAX_SENTENCE_LENGTH];
    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        analyzeSentiment(sentence, sentiments);
    }

    return 0;
}