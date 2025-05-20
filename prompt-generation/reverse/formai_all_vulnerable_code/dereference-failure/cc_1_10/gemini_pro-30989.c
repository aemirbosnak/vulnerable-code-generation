//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the sentiment dictionary
typedef struct sentiment_dict_entry {
    char *word;
    int sentiment;
} sentiment_dict_entry;

sentiment_dict_entry sentiment_dict[] = {
    {"good", 1},
    {"bad", -1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"horrible", -3}
};

// Define the maximum size of the text to analyze
#define MAX_TEXT_SIZE 1000

// Analyze the sentiment of the given text
int analyze_sentiment(char *text) {
    // Convert the text to lowercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Search for the token in the sentiment dictionary
        int found = 0;
        for (int i = 0; i < sizeof(sentiment_dict) / sizeof(sentiment_dict_entry); i++) {
            if (strcmp(token, sentiment_dict[i].word) == 0) {
                // Add the sentiment score for the token
                sentiment_score += sentiment_dict[i].sentiment;
                found = 1;
                break;
            }
        }

        // If the token was not found, ignore it
        if (!found) {
            //printf("Ignoring token '%s'\n", token);
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment_score;
}

// Get the sentiment of the text from the user
char *get_text_from_user() {
    // Allocate memory for the text
    char *text = malloc(MAX_TEXT_SIZE);

    // Prompt the user for the text
    printf("Enter the text to analyze: ");
    fgets(text, MAX_TEXT_SIZE, stdin);

    // Remove the newline character from the text
    text[strlen(text) - 1] = '\0';

    // Return the text
    return text;
}

// Print the sentiment of the text
void print_sentiment(int sentiment_score) {
    if (sentiment_score > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }
}

// Main function
int main() {
    // Get the text from the user
    char *text = get_text_from_user();

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment of the text
    print_sentiment(sentiment_score);

    // Free the memory allocated for the text
    free(text);

    return 0;
}