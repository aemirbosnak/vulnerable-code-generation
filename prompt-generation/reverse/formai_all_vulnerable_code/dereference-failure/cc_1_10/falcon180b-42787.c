//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to tokenize the input text
void tokenize(char* input, char** tokens) {
    int count = 0;
    char* token = strtok(input, " \t\n\r\f\v,.?!;:\"'()[]{}<>");

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, " \t\n\r\f\v,.?!;:\"'()[]{}<>");
    }
}

// Function to generate a summary of the input text
void summarize(char** tokens, int num_tokens, char* summary, int max_summary_length) {
    int summary_length = 0;
    int i = 0;

    // Start with the first sentence
    while (i < num_tokens && summary_length < max_summary_length) {
        if (tokens[i][0] == '.' || tokens[i][0] == '?' || tokens[i][0] == '!') {
            // End of sentence, add to summary
            strncat(summary, tokens[i], max_summary_length - summary_length);
            summary_length += strlen(tokens[i]);
        }
        i++;
    }

    // Add ellipsis if summary is too long
    if (summary_length >= max_summary_length) {
        strncat(summary, "...", max_summary_length - summary_length);
    }
}

int main() {
    char input[1000];
    char* tokens[1000];
    char summary[500];

    // Prompt user for input text
    printf("Enter input text: ");
    fgets(input, 1000, stdin);

    // Tokenize input text
    tokenize(input, tokens);

    // Generate summary of input text
    summarize(tokens, 1000, summary, 500);

    // Print summary
    printf("Summary: %s\n", summary);

    return 0;
}