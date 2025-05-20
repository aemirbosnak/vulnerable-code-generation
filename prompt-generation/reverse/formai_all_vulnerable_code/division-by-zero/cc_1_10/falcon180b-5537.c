//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50

// Function to split a sentence into words
void split_sentence(char* sentence, char words[][MAX_WORD_LENGTH]) {
    int i = 0;
    char* word = strtok(sentence, ",.!?;:");

    while (word!= NULL) {
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, ",.!?;:");
    }
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char words[][MAX_WORD_LENGTH], int num_words) {
    int positive_words = 0;
    int negative_words = 0;
    int neutral_words = 0;

    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        if (strcasecmp(word, "happy") == 0 || strcasecmp(word, "joy") == 0) {
            positive_words++;
        } else if (strcasecmp(word, "sad") == 0 || strcasecmp(word, "angry") == 0) {
            negative_words++;
        } else {
            neutral_words++;
        }
    }

    int sentiment_score = (positive_words - negative_words) / (positive_words + negative_words);

    return sentiment_score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    split_sentence(sentence, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (words[i][0] == '\0') {
            break;
        }
        num_words++;
    }

    int sentiment_score = calculate_sentiment_score(words, num_words);

    if (sentiment_score > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}