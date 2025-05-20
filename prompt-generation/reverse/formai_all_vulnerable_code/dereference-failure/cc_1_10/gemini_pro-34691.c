//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to tokenize the input text
char **tokenize_text(const char *input_text, size_t *num_tokens) {
    // Initialize the tokenizer
    char **tokens = NULL;
    *num_tokens = 0;

    // Allocate memory for the first token
    tokens = realloc(tokens, sizeof(char *));
    tokens[0] = malloc(strlen(input_text) + 1);

    // Tokenize the input text
    char *token = strtok(input_text, " ");
    while (token != NULL) {
        // Copy the token into the array of tokens
        strcpy(tokens[*num_tokens], token);

        // Increment the number of tokens
        (*num_tokens)++;

        // Allocate memory for the next token
        tokens = realloc(tokens, sizeof(char *) * (*num_tokens + 1));
        tokens[*num_tokens] = malloc(strlen(token) + 1);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the array of tokens
    return tokens;
}

// Function to calculate the frequency of each token
int *calculate_token_frequency(char **tokens, size_t num_tokens) {
    // Initialize the frequency table
    int *frequency_table = calloc(num_tokens, sizeof(int));

    // Calculate the frequency of each token
    for (size_t i = 0; i < num_tokens; i++) {
        frequency_table[i] = 1;
        for (size_t j = i + 1; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency_table[i]++;
            }
        }
    }

    // Return the frequency table
    return frequency_table;
}

// Function to sort the tokens by frequency
void sort_tokens_by_frequency(char **tokens, size_t num_tokens, int *frequency_table) {
    // Sort the tokens by frequency
    for (size_t i = 0; i < num_tokens - 1; i++) {
        for (size_t j = i + 1; j < num_tokens; j++) {
            if (frequency_table[i] < frequency_table[j]) {
                // Swap the tokens
                char *temp = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp;

                // Swap the frequencies
                int temp_freq = frequency_table[i];
                frequency_table[i] = frequency_table[j];
                frequency_table[j] = temp_freq;
            }
        }
    }
}

// Function to generate the summary
char *generate_summary(char **tokens, size_t num_tokens, size_t num_sentences) {
    // Initialize the summary
    char *summary = malloc(1);
    summary[0] = '\0';

    // Generate the summary
    for (size_t i = 0; i < num_sentences && i < num_tokens; i++) {
        // Append the token to the summary
        summary = realloc(summary, strlen(summary) + strlen(tokens[i]) + 2);
        strcat(summary, tokens[i]);
        strcat(summary, " ");
    }

    // Return the summary
    return summary;
}

// Function to free the allocated memory
void free_memory(char **tokens, size_t num_tokens, int *frequency_table, char *summary) {
    // Free the tokens
    for (size_t i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    // Free the frequency table
    free(frequency_table);

    // Free the summary
    free(summary);
}

int main() {
    // Get the input text from the user
    char input_text[1024];
    printf("Enter the text to be summarized: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Tokenize the input text
    size_t num_tokens;
    char **tokens = tokenize_text(input_text, &num_tokens);

    // Calculate the frequency of each token
    int *frequency_table = calculate_token_frequency(tokens, num_tokens);

    // Sort the tokens by frequency
    sort_tokens_by_frequency(tokens, num_tokens, frequency_table);

    // Get the number of sentences in the summary
    size_t num_sentences;
    printf("Enter the number of sentences in the summary: ");
    scanf("%zu", &num_sentences);

    // Generate the summary
    char *summary = generate_summary(tokens, num_tokens, num_sentences);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free_memory(tokens, num_tokens, frequency_table, summary);

    return 0;
}