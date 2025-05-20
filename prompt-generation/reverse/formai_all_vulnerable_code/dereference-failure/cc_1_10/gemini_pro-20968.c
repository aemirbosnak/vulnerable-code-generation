//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove punctuation from a string
char* remove_punctuation(char* str) {
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?' && str[i] != ';' && str[i] != ':') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// Function to summarize a text
char* summarize_text(char* text) {
    // Remove punctuation from the text
    char* new_text = remove_punctuation(text);

    // Tokenize the text
    char* tokens[100];
    int num_tokens = 0;
    char* token = strtok(new_text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Create a frequency table of the tokens
    int freq_table[100];
    memset(freq_table, 0, sizeof(freq_table));
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                freq_table[i]++;
            }
        }
    }

    // Find the top 5 most frequent tokens
    int top_5[5];
    for (int i = 0; i < 5; i++) {
        int max_freq = 0;
        int max_index = 0;
        for (int j = 0; j < num_tokens; j++) {
            if (freq_table[j] > max_freq) {
                max_freq = freq_table[j];
                max_index = j;
            }
        }
        top_5[i] = max_index;
        freq_table[max_index] = 0;
    }

    // Generate the summary
    char* summary = malloc(1000);
    int len = 0;
    for (int i = 0; i < 5; i++) {
        len += sprintf(summary + len, "%s ", tokens[top_5[i]]);
    }

    free(new_text);
    return summary;
}

int main() {
    // Get the text from the user
    char* text = malloc(1000);
    printf("Enter the text to be summarized: ");
    gets(text);

    // Summarize the text
    char* summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    free(summary);
    return 0;
}