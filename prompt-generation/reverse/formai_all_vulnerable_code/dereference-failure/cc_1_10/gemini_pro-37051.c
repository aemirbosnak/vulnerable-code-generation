//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to tokenize the input text
char** tokenize(char* text, int* num_tokens) {
    char** tokens = malloc(100 * sizeof(char*));
    int i = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    *num_tokens = i;
    return tokens;
}

// Function to calculate the frequency of each token
int* calculate_frequency(char** tokens, int num_tokens) {
    int* frequency = malloc(num_tokens * sizeof(int));
    memset(frequency, 0, num_tokens * sizeof(int));
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency[i]++;
            }
        }
    }
    return frequency;
}

// Function to sort the tokens by frequency
void sort_tokens(char** tokens, int* frequency, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (frequency[i] < frequency[j]) {
                char* temp = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp;
                int temp_freq = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp_freq;
            }
        }
    }
}

// Function to generate the summary
char* generate_summary(char** tokens, int* frequency, int num_tokens) {
    char* summary = malloc(1000 * sizeof(char));
    int num_sentences = num_tokens / 10;
    int i = 0;
    int j = 0;
    while (i < num_sentences) {
        strcat(summary, tokens[j]);
        strcat(summary, " ");
        j++;
        i++;
    }
    return summary;
}

int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter the text to summarize: ");
    gets(text);

    // Tokenize the input text
    int num_tokens;
    char** tokens = tokenize(text, &num_tokens);

    // Calculate the frequency of each token
    int* frequency = calculate_frequency(tokens, num_tokens);

    // Sort the tokens by frequency
    sort_tokens(tokens, frequency, num_tokens);

    // Generate the summary
    char* summary = generate_summary(tokens, frequency, num_tokens);

    // Print the summary
    printf("Summary: %s", summary);

    // Free the allocated memory
    free(tokens);
    free(frequency);
    free(summary);

    return 0;
}