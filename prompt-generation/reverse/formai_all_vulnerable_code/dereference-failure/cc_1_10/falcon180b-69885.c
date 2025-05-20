//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
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
    {"Very Negative", -3},
    {"Negative", -2},
    {"Neutral", 0},
    {"Positive", 2},
    {"Very Positive", 3}
};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentiment(char *sentence) {
    int length = strlen(sentence);
    int i;
    int sentiment_index = 0;
    int total_sentiment_value = 0;

    for (i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            char word[MAX_SENTENCE_LENGTH];
            int j;
            for (j = i; j < length && isalpha(sentence[j]); j++) {
                word[j - i] = tolower(sentence[j]);
            }
            word[j - i] = '\0';

            sentiment_index = get_sentiment_index(word);
            if (sentiment_index >= 0) {
                total_sentiment_value += sentiments[sentiment_index].value;
            }
        }
    }

    return total_sentiment_value;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int sentiment_value = analyze_sentiment(sentence);

    switch (sentiment_value) {
        case -6:
            printf("Very Negative\n");
            break;
        case -4:
            printf("Negative\n");
            break;
        case 0:
            printf("Neutral\n");
            break;
        case 2:
            printf("Positive\n");
            break;
        case 4:
            printf("Very Positive\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}