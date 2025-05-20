//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"very negative", -3},
    {"negative", -2},
    {"neutral", 0},
    {"positive", 2},
    {"very positive", 3}
};

int getSentimentIndex(char *sentiment) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyzeSentence(char *sentence) {
    int length = strlen(sentence);
    int i;
    int sentimentIndex = 0;
    int totalSentiment = 0;

    for (i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            char word[MAX_SENTENCE_LENGTH];
            int j;
            for (j = i; j < length && isalpha(sentence[j]); j++) {
                word[j - i] = tolower(sentence[j]);
            }
            word[j - i] = '\0';

            sentimentIndex = getSentimentIndex(word);

            if (sentimentIndex >= 0) {
                totalSentiment += sentiments[sentimentIndex].value;
            }
        }
    }

    return totalSentiment / length;
}

int main() {
    FILE *inputFile;
    char sentence[MAX_SENTENCE_LENGTH];
    int length;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", sentence)!= EOF) {
        length = strlen(sentence);

        if (length > 0 && sentence[length - 1] == '.') {
            sentence[length - 1] = '\0';
            length--;
        }

        int sentiment = analyzeSentence(sentence);

        printf("Sentiment for sentence '%s': %d\n", sentence, sentiment);
    }

    fclose(inputFile);

    return 0;
}