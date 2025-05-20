//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 80
#define MAX_INDENT 4

// Function to calculate the number of spaces needed for indentation
int getIndentSize(int level) {
    return level * MAX_INDENT;
}

// Function to format the HTML code and return the formatted string
char* formatHTML(char* input) {
    // Initialize the output string
    char* output = malloc(strlen(input) * 2 + 1);
    int outputIndex = 0;

    // Loop through the input HTML code
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current character is a newline
        if (input[i] == '\n') {
            // Increment the level of indentation
            int level = getIndentSize(outputIndex / MAX_LINE_LENGTH);

            // Append the appropriate number of spaces for indentation
            memset(output + outputIndex, ' ', level);
            outputIndex += level;

            // Reset the output index
            outputIndex = 0;
        }

        // Append the current character to the output string
        output[outputIndex++] = input[i];
    }

    // Append the final newline to the output string
    output[outputIndex++] = '\n';

    // Return the formatted HTML string
    return output;
}

int main() {
    // Read the raw HTML input from the user
    char input[1024];
    printf("Enter raw HTML code: ");
    fgets(input, 1024, stdin);

    // Format the HTML code and print the result
    char* formatted = formatHTML(input);
    printf("%s\n", formatted);

    // Free the memory allocated for the output string
    free(formatted);

    return 0;
}