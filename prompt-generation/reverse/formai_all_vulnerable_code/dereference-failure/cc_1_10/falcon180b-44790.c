//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_SENTENCE_LENGTH];
    int count;
} WordFrequency;

void calculateSentiment(char* sentence, int* positive, int* negative, int* neutral) {
    *positive = 0;
    *negative = 0;
    *neutral = 0;

    int i = 0;
    while (i < strlen(sentence)) {
        char word[MAX_SENTENCE_LENGTH];
        int wordLength = 0;

        while (isalnum(sentence[i])) {
            word[wordLength++] = tolower(sentence[i]);
            i++;
        }
        word[wordLength] = '\0';

        if (strstr(word, "happy")!= NULL || strstr(word, "joy")!= NULL) {
            (*positive)++;
        } else if (strstr(word, "sad")!= NULL || strstr(word, "anger")!= NULL) {
            (*negative)++;
        } else {
            (*neutral)++;
        }
    }
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    int numWords = 0;
    int i = 0;

    printf("Enter a sentence: ");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);

    WordFrequency* words = (WordFrequency*) malloc(MAX_WORDS * sizeof(WordFrequency));

    char* token = strtok(input, ",.?!");
    while (token!= NULL) {
        strcpy(words[numWords].word, token);
        words[numWords].count++;
        numWords++;

        if (numWords >= MAX_WORDS) {
            break;
        }

        token = strtok(NULL, ",.?!");
    }

    int positive = 0, negative = 0, neutral = 0;
    calculateSentiment(input, &positive, &negative, &neutral);

    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);
    printf("Neutral: %d\n", neutral);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}