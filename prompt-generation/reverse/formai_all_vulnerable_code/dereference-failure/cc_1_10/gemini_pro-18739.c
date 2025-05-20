//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    ['a'] = 1,
    ['b'] = -1,
    ['c'] = 2,
    ['d'] = -2,
    ['e'] = 3,
    ['f'] = -3,
    ['g'] = 4,
    ['h'] = -4,
    ['i'] = 5,
    ['j'] = -5,
    ['k'] = 6,
    ['l'] = -6,
    ['m'] = 7,
    ['n'] = -7,
    ['o'] = 8,
    ['p'] = -8,
    ['q'] = 9,
    ['r'] = -9,
    ['s'] = 10,
    ['t'] = -10,
    ['u'] = 11,
    ['v'] = -11,
    ['w'] = 12,
    ['x'] = -12,
    ['y'] = 13,
    ['z'] = -13,
};

// Calculate the sentiment score of a sentence
int calculate_sentiment_score(const char *sentence) {
    // Initialize the sentiment score to 0
    int sentiment_score = 0;

    // Convert the sentence to lowercase
    char *lowercase_sentence = malloc(strlen(sentence) + 1);
    strcpy(lowercase_sentence, sentence);
    for (int i = 0; lowercase_sentence[i] != '\0'; i++) {
        lowercase_sentence[i] = tolower(lowercase_sentence[i]);
    }

    // Iterate over the characters in the sentence
    for (int i = 0; lowercase_sentence[i] != '\0'; i++) {
        // Get the sentiment score for the character
        int character_score = SENTIMENT_SCORES[lowercase_sentence[i]];

        // Add the sentiment score to the total sentiment score
        sentiment_score += character_score;
    }

    // Free the memory allocated for the lowercase sentence
    free(lowercase_sentence);

    // Return the sentiment score
    return sentiment_score;
}

// Print the sentiment analysis results
void print_sentiment_analysis_results(const char *sentence, int sentiment_score) {
    // Print the sentence
    printf("Sentence: %s\n", sentence);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Print the sentiment analysis result
    if (sentiment_score > 0) {
        printf("Sentiment analysis result: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment analysis result: Negative\n");
    } else {
        printf("Sentiment analysis result: Neutral\n");
    }
}

// Main function
int main() {
    // Get the sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Calculate the sentiment score of the sentence
    int sentiment_score = calculate_sentiment_score(sentence);

    // Print the sentiment analysis results
    print_sentiment_analysis_results(sentence, sentiment_score);

    return 0;
}