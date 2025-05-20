//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = -1,  // "bad"
    [1] = 1,   // "good"
    [2] = -2,  // "terrible"
    [3] = 2,   // "excellent"
    [4] = -3,  // "horrible"
    [5] = 3,   // "amazing"
};

// Compute the sentiment score of a given string
int compute_sentiment_score(char *input) {
    int score = 0;
    char *word;

    // Tokenize the input string into words
    word = strtok(input, " ");
    while (word != NULL) {
        // Find the sentiment score for the current word
        int i;
        for (i = 0; i < sizeof(sentiment_scores) / sizeof(int); i++) {
            if (strcmp(word, sentiment_scores[i]) == 0) {
                score += sentiment_scores[i];
                break;
            }
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter a sentence to analyze: ");
    fgets(input, sizeof(input), stdin);

    // Compute the sentiment score of the input string
    int score = compute_sentiment_score(input);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", score);

    return 0;
}