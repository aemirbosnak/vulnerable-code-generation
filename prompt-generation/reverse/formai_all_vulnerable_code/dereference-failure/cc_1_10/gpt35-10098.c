//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
/*
 * A Sentiment Analysis tool to analyze the emotions in a given text.
 *
 * This program reads in a user's input text and evaluates the overall sentiment
 * as positive, negative, or neutral. It uses a pre-defined list of positive and
 * negative words to determine the sentiment.
 *
 * Author: John Doe
 * Date: February 15, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of user input and sentiment word lists
#define MAX_INPUT_LEN 1000
#define MAX_WORD_LEN 20

// Define the sentiment list size
#define POS_LIST_SIZE 10
#define NEG_LIST_SIZE 10

// Positive sentiment word list
char pos_list[POS_LIST_SIZE][MAX_WORD_LEN] = {
    "happy", "love", "amazing", "fantastic", "exciting",
    "great", "excellent", "wonderful", "awesome", "good"
};

// Negative sentiment word list
char neg_list[NEG_LIST_SIZE][MAX_WORD_LEN] = {
    "sad", "hate", "disappointing", "terrible", "horrible",
    "bad", "awful", "not good", "poor", "unhappy"
};

// Function to determine if a word is in the positive sentiment list
int is_positive(char *word) {
    for (int i = 0; i < POS_LIST_SIZE; i++) {
        if (strcmp(pos_list[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to determine if a word is in the negative sentiment list
int is_negative(char *word) {
    for (int i = 0; i < NEG_LIST_SIZE; i++) {
        if (strcmp(neg_list[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the sentiment score of the given text
int sentiment_analysis(char *text) {
    char *token, *rest;
    int sentiment_score = 0;

    // Get the first token
    token = strtok_r(text, " \n", &rest);

    // Loop through all tokens
    while (token != NULL) {
        if (is_positive(token)) {
            sentiment_score++;
        } else if (is_negative(token)) {
            sentiment_score--;
        }
        // Get the next token
        token = strtok_r(rest, " \n", &rest);
    }

    return sentiment_score;
}

// Main function to read user input, perform sentiment analysis, and output results
int main() {
    char input_text[MAX_INPUT_LEN];
    int sentiment_score;

    // Read user input
    printf("Enter text to analyze sentiment: ");
    fgets(input_text, MAX_INPUT_LEN, stdin);

    // Perform sentiment analysis
    sentiment_score = sentiment_analysis(input_text);

    // Output sentiment score and classification
    if (sentiment_score > 0) {
        printf("Sentiment score: %d. Positive!\n", sentiment_score);
    } else if (sentiment_score < 0) {
        printf("Sentiment score: %d. Negative :(\n", sentiment_score);
    } else {
        printf("Sentiment score: %d. Neutral.\n", sentiment_score);
    }

    return 0;
}