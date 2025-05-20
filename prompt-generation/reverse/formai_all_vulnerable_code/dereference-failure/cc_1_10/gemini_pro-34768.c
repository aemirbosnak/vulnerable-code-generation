//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lively CSV reader that will make you dance with data!

// Function to read a line from the CSV file
char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    return line;
}

// Function to split a line into tokens
char** split_line(char* line) {
    char** tokens = NULL;
    int num_tokens = 0;

    // Count the number of tokens
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') {
            num_tokens++;
        }
    }

    // Allocate memory for the tokens
    tokens = malloc((num_tokens + 1) * sizeof(char*));

    // Split the line into tokens
    int start = 0;
    int end = 0;
    int token_index = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') {
            end = i;
            tokens[token_index] = malloc(end - start + 1);
            strncpy(tokens[token_index], line + start, end - start);
            tokens[token_index][end - start] = '\0';
            token_index++;
            start = end + 1;
        }
    }

    // Get the last token
    end = strlen(line);
    tokens[token_index] = malloc(end - start + 1);
    strncpy(tokens[token_index], line + start, end - start);
    tokens[token_index][end - start] = '\0';

    // Return the tokens
    return tokens;
}

// Function to print the tokens
void print_tokens(char** tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
    }
}

// Main function
int main() {
    // Open the CSV file
    FILE* fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first line of the CSV file
    char* line = read_line(fp);

    // Split the line into tokens
    char** tokens = split_line(line);

    // Print the tokens
    print_tokens(tokens);

    // Free the allocated memory
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(line);

    // Close the CSV file
    fclose(fp);

    return EXIT_SUCCESS;
}