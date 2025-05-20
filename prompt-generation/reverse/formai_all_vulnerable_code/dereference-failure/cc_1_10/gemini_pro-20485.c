//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tokenize the text into words
char **tokenize(char *text) {
    char **tokens = malloc(sizeof(char *) * 100);
    int num_tokens = 0;
    // Split the text by spaces
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    // Reallocate the tokens array to its actual size
    tokens = realloc(tokens, sizeof(char *) * num_tokens);
    return tokens;
}

// Calculate the frequency of each word in the text
int *calculate_frequency(char **tokens, int num_tokens) {
    int *frequency = calloc(sizeof(int), num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency[i]++;
            }
        }
    }
    return frequency;
}

// Find the top 10 most frequent words in the text
char **find_top_10(int *frequency, char **tokens, int num_tokens) {
    char **top_10 = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++) {
        int max_frequency = 0;
        int max_frequency_index = -1;
        for (int j = 0; j < num_tokens; j++) {
            if (frequency[j] > max_frequency) {
                max_frequency = frequency[j];
                max_frequency_index = j;
            }
        }
        top_10[i] = tokens[max_frequency_index];
        frequency[max_frequency_index] = -1;  // Mark the word as found
    }
    return top_10;
}

// Summarize the text by extracting the top 10 most frequent words
char *summarize(char *text) {
    char **tokens = tokenize(text);
    int num_tokens = 0;
    while (tokens[num_tokens] != NULL) {
        num_tokens++;
    }
    int *frequency = calculate_frequency(tokens, num_tokens);
    char **top_10 = find_top_10(frequency, tokens, num_tokens);
    char *summary = malloc(sizeof(char) * 100);
    for (int i = 0; i < 10; i++) {
        strcat(summary, top_10[i]);
        strcat(summary, " ");
    }
    free(tokens);
    free(frequency);
    free(top_10);
    return summary;
}

int main() {
    char *text = "This is a sample text that we want to summarize. This text contains some repeated words, such as 'this' and 'the', which can be used to identify the main topics of the text. By identifying the most frequent words, we can get a good understanding of what the text is about.";
    char *summary = summarize(text);
    printf("Summary: %s\n", summary);
    free(summary);
    return 0;
}