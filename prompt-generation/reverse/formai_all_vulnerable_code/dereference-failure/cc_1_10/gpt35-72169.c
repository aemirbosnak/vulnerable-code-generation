//FormAI DATASET v1.0 Category: Text Summarizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 5000
#define MAX_LINES 1000

int main() {
    char input[MAX_CHARS];
    char output[MAX_CHARS];
    char lines[MAX_LINES][MAX_CHARS];
    char* token;
    char* rest = input;
    int lineCount = 0;
    int inputLength, outputLength = 0;
    int i;

    // Get user input
    printf("Enter text to summarize:\n");
    fgets(input, MAX_CHARS, stdin);
    inputLength = strlen(input);

    // Remove newline character from input
    if (input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
    }

    // Tokenize input into lines
    while ((token = strtok_r(rest, "\n", &rest))) {
        strcpy(lines[lineCount], token);
        lineCount++;
    }

    // Loop through lines and add to output until a threshold is reached
    for (i = 0; i < lineCount; i++) {
        if (outputLength + strlen(lines[i]) > MAX_CHARS) {
            break;
        }

        strcat(output, lines[i]);
        strcat(output, " ");
        outputLength += strlen(lines[i]) + 1;
    }

    // Add ellipsis to end of output
    strcat(output, "...");
    outputLength += 3;

    // Print the output
    printf("\nSummary:\n%s\n", output);

    return 0;
}