//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"Joy", 1}, {"Sadness", -1}, {"Anger", -1}, {"Fear", -1}, {"Disgust", -1}, {"Surprise", 1}};

int get_sentiment_index(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiments[i].name, sentiment_name) == 0) {
            return i;
        }
    }
    return -1;
}

int analyze_sentence(char *sentence) {
    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        return -1;
    }

    int sentiment_index = get_sentiment_index("Joy");
    int score = 0;

    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        int word_length = strlen(word);
        if (word_length > 0 && isalpha(word[0])) {
            word = tolower(word);
            int word_index = get_sentiment_index(word);
            if (word_index!= -1) {
                score += sentiments[word_index].value;
            }
        }
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int score = analyze_sentence(sentence);
    if (score == -1) {
        printf("Invalid sentence.\n");
    } else {
        printf("Sentiment score: %d\n", score);
    }

    return 0;
}