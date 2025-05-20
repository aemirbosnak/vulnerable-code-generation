//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    double weight;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1.0},
    {"sad", -1.0},
    {"angry", -1.0},
    {"excited", 1.0},
    {"bored", -1.0},
    {"neutral", 0.0}
};

char *process_sentence(char *sentence)
{
    int i, j;
    char *token;
    char *processed_sentence = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    strcpy(processed_sentence, "");

    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            for (j = 0; j < NUM_SENTIMENTS; j++) {
                if (strcasecmp(sentiments[j].name, &sentence[i]) == 0) {
                    strcat(processed_sentence, " ");
                    strcat(processed_sentence, sentiments[j].name);
                    break;
                }
            }
        } else {
            strcat(processed_sentence, " ");
            strcat(processed_sentence, &sentence[i]);
        }
    }

    return processed_sentence;
}

double calculate_sentiment_score(char *sentence)
{
    int i;
    double score = 0.0;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strstr(sentence, sentiments[i].name)!= NULL) {
            score += sentiments[i].weight;
        }
    }

    return score;
}

int main()
{
    char input_sentence[MAX_SENTENCE_LENGTH];
    char *processed_sentence;
    double sentiment_score;

    printf("Enter a sentence: ");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    processed_sentence = process_sentence(input_sentence);
    sentiment_score = calculate_sentiment_score(processed_sentence);

    printf("Processed sentence: %s\n", processed_sentence);
    printf("Sentiment score: %.2f\n", sentiment_score);

    free(processed_sentence);
    return 0;
}