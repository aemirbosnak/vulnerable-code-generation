//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[10000];

// Initialize the sentiment scores
void init_sentiment_scores() {
    FILE *f = fopen("sentiment_scores.txt", "r");
    if (f == NULL) {
        perror("Error opening sentiment scores file");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        char *word = strtok(line, " ");
        char *score = strtok(NULL, " ");

        sentiment_scores[atoi(word)] = atoi(score);
    }

    fclose(f);
}

// Calculate the sentiment score for a given text
int calculate_sentiment_score(char *text) {
    int score = 0;

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Get the sentiment score for the token
        int token_score = sentiment_scores[atoi(token)];

        // Add the token's score to the total score
        score += token_score;

        // Get the next token
        token = strtok(NULL, " ");
    }

    return score;
}

// Print the sentiment score for a given text
void print_sentiment_score(char *text) {
    int score = calculate_sentiment_score(text);

    printf("Sentiment score for \"%s\": %d\n", text, score);
}

// Main function
int main() {
    // Initialize the sentiment scores
    init_sentiment_scores();

    // Get the text from the user
    char text[1024];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Calculate and print the sentiment score
    print_sentiment_score(text);

    return 0;
}