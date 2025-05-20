//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 1,  // "great"
    [2] = 1,  // "excellent"
    [3] = 1,  // "awesome"
    [4] = 1,  // "fantastic"

    // Negative words
    [5] = -1, // "bad"
    [6] = -1, // "terrible"
    [7] = -1, // "awful"
    [8] = -1, // "horrible"
    [9] = -1, // "dreadful"
};

// Define the list of stop words
const char *STOP_WORDS[] = {
    "a", "an", "the", "and", "or", "but", "to", "of", "in", "on"
};

// Function to tokenize a sentence into words
char **tokenize(char *sentence) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int num_words = 0;

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = strdup(word);
        word = strtok(NULL, " ");
    }

    return words;
}

// Function to remove stop words from a list of words
char **remove_stop_words(char **words, int num_words) {
    char **new_words = malloc((num_words - 10) * sizeof(char *));
    int new_num_words = 0;

    for (int i = 0; i < num_words; i++) {
        int is_stop_word = 0;
        for (int j = 0; j < 10; j++) {
            if (strcmp(words[i], STOP_WORDS[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        if (!is_stop_word) {
            new_words[new_num_words++] = strdup(words[i]);
        }
    }

    return new_words;
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment_score(char **words, int num_words) {
    int sentiment_score = 0;

    for (int i = 0; i < num_words; i++) {
        // Find the sentiment score for the word
        int sentiment_score_word = -2;
        for (int j = 0; j < 10; j++) {
            if (strcmp(words[i], SENTIMENT_SCORES[j]) == 0) {
                sentiment_score_word = SENTIMENT_SCORES[j];
                break;
            }
        }

        // Add the sentiment score for the word to the total sentiment score
        sentiment_score += sentiment_score_word;
    }

    return sentiment_score;
}

int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Tokenize the sentence into words
    char **words = tokenize(sentence);

    // Remove stop words from the list of words
    int num_words = 0;
    words = remove_stop_words(words, num_words);

    // Calculate the sentiment score of the sentence
    int sentiment_score = calculate_sentiment_score(words, num_words);

    // Print the sentiment score of the sentence
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}