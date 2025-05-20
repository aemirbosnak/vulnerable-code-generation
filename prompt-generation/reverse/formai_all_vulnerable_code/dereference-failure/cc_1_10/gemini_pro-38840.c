//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Constants
#define MAX_INPUT_SIZE 10000
#define MAX_SUMMARY_SIZE 1000
#define STOP_WORDS_COUNT 150

// Function prototypes
void readInput(char *input);
void tokenizeInput(char *input, char **tokens, int *tokenCount);
void removeStopWords(char **tokens, int *tokenCount);
void summarizeText(char **tokens, int tokenCount, char *summary);
void printSummary(char *summary);

// Stop words list
char *stopWords[] = {
    "a", "an", "the", "and", "or", "but", "of", "in", "on", "at", "to", "from", "as", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "will", "would", "should", "could", "may", "might", "can", "cannot", "must", "need", "shall", "should", "will", "would", "could", "may", "might", "can", "cannot", "must", "need", "shall", "should", "will", "would", "could", "may", "might", "can", "cannot", "must", "need", "shall", "should", "will", "would", "could", "may", "might", "can", "cannot", "must", "need", "shall"
};

// Main function
int main() {
    // Declare variables
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_INPUT_SIZE];
    int tokenCount = 0;
    char summary[MAX_SUMMARY_SIZE];

    // Read input from the user
    printf("Enter the text you want to summarize: ");
    readInput(input);

    // Tokenize the input text
    tokenizeInput(input, tokens, &tokenCount);

    // Remove stop words from the tokenized text
    removeStopWords(tokens, &tokenCount);

    // Summarize the text
    summarizeText(tokens, tokenCount, summary);

    // Print the summary
    printSummary(summary);

    return 0;
}

// Function to read input from the user
void readInput(char *input) {
    // Get the input text from the user
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character from the end of the input text
    input[strlen(input) - 1] = '\0';
}

// Function to tokenize the input text
void tokenizeInput(char *input, char **tokens, int *tokenCount) {
    // Declare variables
    char *token;

    // Tokenize the input text using the strtok() function
    token = strtok(input, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Add the token to the tokens array
        tokens[*tokenCount] = token;

        // Increment the token count
        *tokenCount += 1;

        // Get the next token
        token = strtok(NULL, " ");
    }
}

// Function to remove stop words from the tokenized text
void removeStopWords(char **tokens, int *tokenCount) {
    // Declare variables
    int i, j;

    // Loop through the tokens
    for (i = 0; i < *tokenCount; i++) {
        // Convert the token to lowercase
        for (j = 0; tokens[i][j] != '\0'; j++) {
            tokens[i][j] = tolower(tokens[i][j]);
        }

        // Check if the token is a stop word
        for (j = 0; j < STOP_WORDS_COUNT; j++) {
            if (strcmp(tokens[i], stopWords[j]) == 0) {
                // If the token is a stop word, remove it from the tokens array
                for (j = i; j < *tokenCount - 1; j++) {
                    tokens[j] = tokens[j + 1];
                }

                // Decrement the token count
                *tokenCount -= 1;

                // Break out of the loop
                break;
            }
        }
    }
}

// Function to summarize the text
void summarizeText(char **tokens, int tokenCount, char *summary) {
    // Declare variables
    int i, j, k;
    int sentenceCount = 0;
    int sentenceLength = 0;
    char sentence[MAX_INPUT_SIZE];

    // Loop through the tokens
    for (i = 0; i < tokenCount; i++) {
        // Check if the token is a period
        if (tokens[i][strlen(tokens[i]) - 1] == '.') {
            // If the token is a period, increment the sentence count
            sentenceCount += 1;

            // Reset the sentence length
            sentenceLength = 0;
        } else {
            // If the token is not a period, add the token to the sentence
            strcat(sentence, tokens[i]);
            strcat(sentence, " ");

            // Increment the sentence length
            sentenceLength += 1;

            // Check if the sentence length is greater than the maximum sentence length
            if (sentenceLength > MAX_SUMMARY_SIZE) {
                // If the sentence length is greater than the maximum sentence length, break out of the loop
                break;
            }
        }
    }

    // Copy the sentence to the summary
    strcpy(summary, sentence);
}

// Function to print the summary
void printSummary(char *summary) {
    // Print the summary to the console
    printf("Summary: %s", summary);
}