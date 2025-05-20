//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 1024

// Define the number of words to consider for sentiment analysis
#define NUM_WORDS_TO_CONSIDER 100

// Define the sentiment scores for each word
int sentiment_scores[] = {
    ['a'] = 1,
    ['b'] = -1,
    ['c'] = 2,
    ['d'] = -2,
    ['e'] = 1,
    ['f'] = -1,
    ['g'] = 2,
    ['h'] = -2,
    ['i'] = 1,
    ['j'] = -1,
    ['k'] = 2,
    ['l'] = -2,
    ['m'] = 1,
    ['n'] = -1,
    ['o'] = 2,
    ['p'] = -2,
    ['q'] = 1,
    ['r'] = -1,
    ['s'] = 2,
    ['t'] = -2,
    ['u'] = 1,
    ['v'] = -1,
    ['w'] = 2,
    ['x'] = -2,
    ['y'] = 1,
    ['z'] = -1
};

// Function to remove punctuation from a string
void remove_punctuation(char *string) {
    int i, j;
    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (!ispunct(string[i])) {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

// Function to tokenize a string into an array of words
char **tokenize(char *string) {
    char **words = (char **)malloc(NUM_WORDS_TO_CONSIDER * sizeof(char *));
    char *word;
    int i = 0;
    while ((word = strtok(string, " ")) != NULL) {
        words[i++] = strdup(word);
    }
    return words;
}

// Function to calculate the sentiment score of a string
int calculate_sentiment_score(char *string) {
    int score = 0;
    char **words = tokenize(string);
    for (int i = 0; i < NUM_WORDS_TO_CONSIDER; i++) {
        if (words[i] != NULL) {
            score += sentiment_scores[tolower(words[i][0])];
        }
    }
    return score;
}

int main() {
    // Get the input string from the user
    char string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    gets(string);

    // Remove punctuation from the input string
    remove_punctuation(string);

    // Calculate the sentiment score of the input string
    int sentiment_score = calculate_sentiment_score(string);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}