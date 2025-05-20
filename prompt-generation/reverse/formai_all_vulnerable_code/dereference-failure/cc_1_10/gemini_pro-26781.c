//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tokenize the input text into an array of strings
char **tokenize(char *text) {
    char **tokens = malloc(strlen(text) * sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

// Count the number of occurrences of each word in the tokenized text
int *count_words(char **tokens, int num_tokens) {
    int *counts = malloc(num_tokens * sizeof(int));
    for (int i = 0; i < num_tokens; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                counts[i]++;
            }
        }
    }
    return counts;
}

// Find the top 10 most frequent words in the tokenized text
char **find_top_10_words(char **tokens, int *counts, int num_tokens) {
    char **top_10_words = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        top_10_words[i] = NULL;
    }
    for (int i = 0; i < num_tokens; i++) {
        int j;
        for (j = 0; j < 10; j++) {
            if (top_10_words[j] == NULL) {
                top_10_words[j] = tokens[i];
                break;
            } else if (counts[i] > counts[j]) {
                for (int k = 9; k > j; k--) {
                    top_10_words[k] = top_10_words[k - 1];
                }
                top_10_words[j] = tokens[i];
                break;
            }
        }
    }
    return top_10_words;
}

// Print the summary of the input text
void print_summary(char **top_10_words) {
    printf("Here is a summary of the text you provided:\n\n");
    for (int i = 0; i < 10; i++) {
        if (top_10_words[i] != NULL) {
            printf("%d. %s\n", i + 1, top_10_words[i]);
        }
    }
}

int main() {
    // Get the input text from the user
    char *text = malloc(1024 * sizeof(char));
    printf("Enter the text you want to summarize: ");
    fgets(text, 1024, stdin);

    // Tokenize the input text
    char **tokens = tokenize(text);

    // Count the number of occurrences of each word in the tokenized text
    int *counts = count_words(tokens, strlen(text));

    // Find the top 10 most frequent words in the tokenized text
    char **top_10_words = find_top_10_words(tokens, counts, strlen(text));

    // Print the summary of the input text
    print_summary(top_10_words);

    // Free the allocated memory
    free(text);
    free(tokens);
    free(counts);
    free(top_10_words);

    return 0;
}