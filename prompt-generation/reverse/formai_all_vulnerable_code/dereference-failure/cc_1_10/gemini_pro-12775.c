//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000

// Function to remove punctuation from a string
void remove_punctuation(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (ispunct(str[i])) {
            str[i] = ' ';
        }
        i++;
    }
}

// Function to tokenize a string into an array of words
char **tokenize(char *str) {
    char **tokens = malloc(MAX_SENTENCE_LENGTH * sizeof(char *));
    int i = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

// Function to calculate the sentiment of a sentence
int calculate_sentiment(char **tokens) {
    int sentiment = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        if (strcmp(tokens[i], "good") == 0) {
            sentiment++;
        } else if (strcmp(tokens[i], "bad") == 0) {
            sentiment--;
        }
    }
    return sentiment;
}

int main() {
    // Get the sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove punctuation from the sentence
    remove_punctuation(sentence);

    // Tokenize the sentence into an array of words
    char **tokens = tokenize(sentence);

    // Calculate the sentiment of the sentence
    int sentiment = calculate_sentiment(tokens);

    // Print the sentiment of the sentence
    if (sentiment > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    // Free the memory allocated for the tokens
    free(tokens);

    return 0;
}