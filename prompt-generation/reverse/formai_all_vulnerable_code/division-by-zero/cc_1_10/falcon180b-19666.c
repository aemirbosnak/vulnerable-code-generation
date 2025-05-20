//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 5000
#define MIN_WORD_LENGTH 3

// Function to remove punctuations and convert to lowercase
void preprocess(char *text) {
    int i, j;
    for (i = 0, j = 0; text[i]!= '\0'; i++) {
        if (!isalnum(text[i])) {
            continue;
        }
        if (isalpha(text[i])) {
            text[j++] = tolower(text[i]);
        }
    }
    text[j] = '\0';
}

// Function to split text into words
void tokenize(char *text, char **words) {
    char *word = strtok(text, ",.!?;:\"'()[]{}<>");
    int num_words = 0;
    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            words[num_words++] = strdup(word);
        }
        word = strtok(NULL, ",.!?;:\"'()[]{}<>");
    }
}

// Function to calculate the sentiment score
int calculate_sentiment(char **words, int num_words) {
    int positive_words = 0, negative_words = 0, neutral_words = 0;
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "happy") == 0 || strcmp(words[i], "joy") == 0 || strcmp(words[i], "love") == 0) {
            positive_words++;
        } else if (strcmp(words[i], "sad") == 0 || strcmp(words[i], "hate") == 0 || strcmp(words[i], "angry") == 0) {
            negative_words++;
        } else {
            neutral_words++;
        }
    }
    int sentiment_score = (positive_words - negative_words) / (positive_words + negative_words + neutral_words);
    return sentiment_score;
}

int main() {
    char text[1000];
    printf("Enter the text to analyze: ");
    fgets(text, sizeof(text), stdin);
    preprocess(text);
    char *words[MAX_WORDS];
    tokenize(text, words);
    int num_words = 0;
    while (words[num_words]!= NULL) {
        num_words++;
    }
    int sentiment_score = calculate_sentiment(words, num_words);
    printf("Sentiment score: %d\n", sentiment_score);
    return 0;
}