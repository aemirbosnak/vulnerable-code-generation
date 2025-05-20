//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

// Function to read a line from a CSV file
char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to tokenize a CSV line into an array of strings
char **tokenizeCSVLine(char *line, int *numTokens) {
    char **tokens = malloc(MAX_COLUMNS * sizeof(char *));
    char *token = strtok(line, ",");
    *numTokens = 0;

    while (token != NULL && *numTokens < MAX_COLUMNS) {
        tokens[*numTokens] = malloc(strlen(token) + 1);
        strcpy(tokens[*numTokens], token);
        token = strtok(NULL, ",");
        (*numTokens)++;
    }
    return tokens;
}

// Function to free memory allocated for tokens
void freeTokens(char **tokens, int numTokens) {
    for (int i = 0; i < numTokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

// Main function to drive the CSV reader
int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open the CSV file!\n");
        return 1;
    }

    printf("🌟 Welcome to the CSV Reader! 🌟\n");
    printf("Here’s what we found in your CSV file:\n");

    char *line;
    while ((line = readLine(file)) != NULL) {
        int numTokens = 0;
        char **tokens = tokenizeCSVLine(line, &numTokens);

        // Check if we have a valid number of tokens
        if (numTokens < 2) {
            fprintf(stderr, "Invalid line format: %s\n", line);
            free(line);
            freeTokens(tokens, numTokens);
            continue;
        }

        // Print the tokens
        printf("Name: %s, Age: %s\n", tokens[0], tokens[1]);

        // Clean up
        free(line);
        freeTokens(tokens, numTokens);
    }

    fclose(file);
    printf("🎉 All done! Happy coding! 🎉\n");
    return 0;
}