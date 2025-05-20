//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration options
#define INDENT_SIZE 2
#define MAX_LINE_LENGTH 80

// Function prototypes
char *html_beautify(char *input);
char *indent(int level);
char *newline();

int main() {
    // Get the input HTML from the user
    char *input = malloc(1024);
    printf("Enter your HTML code:\n");
    fgets(input, 1024, stdin);

    // Beautify the HTML
    char *output = html_beautify(input);

    // Print the beautified HTML
    printf("Beautified HTML:\n");
    printf("%s", output);

    // Free the allocated memory
    free(input);
    free(output);

    return 0;
}

char *html_beautify(char *input) {
    // Initialize the output string
    char *output = malloc(1024);
    int output_length = 0;

    // Initialize the current indentation level
    int level = 0;

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if we need to start a new line
        if (output_length > MAX_LINE_LENGTH) {
            strcat(output, newline());
            output_length = 0;
        }

        // Append the current character to the output string
        char c = input[i];
        strncat(output, &c, 1);
        output_length++;

        // Check if we need to indent
        if (c == '<') {
            level++;
            strcat(output, indent(level));
        } else if (c == '>') {
            level--;
            strcat(output, newline());
        }
    }

    // Return the beautified HTML
    return output;
}

char *indent(int level) {
    // Initialize the indentation string
    char *indentation = malloc(1024);
    int indentation_length = 0;

    // Add the appropriate number of spaces to the indentation string
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        strcat(indentation, " ");
        indentation_length++;
    }

    // Return the indentation string
    return indentation;
}

char *newline() {
    // Return a newline character
    return "\n";
}