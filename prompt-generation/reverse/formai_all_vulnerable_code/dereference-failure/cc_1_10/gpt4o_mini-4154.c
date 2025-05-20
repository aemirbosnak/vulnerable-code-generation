//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 20

// Function to determine if a character is a space or newline
int isSpaceOrNewline(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

// Function to beautify the HTML code
void beautifyHTML(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;  // Tracks the current indentation level
    int inQuotes = 0;     // Tracks whether we are currently inside quotes

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;  // Pointer to iterate over the line
        char *outputBuffer = (char *)malloc(MAX_LINE_LENGTH);
        int outputIndex = 0;  // Index for the output buffer

        // Process each character in the line
        while (*ptr) {
            // Handle starting and ending of tags
            if (*ptr == '<') {
                // Check for closing tags
                if (*(ptr + 1) == '/') {
                    // Decrease indentation for closing tags
                    indentLevel--;
                }

                // Add the current indentation level
                for (int i = 0; i < indentLevel; i++) {
                    outputBuffer[outputIndex++] = '\t'; // Using tab for indentation
                }

                // Add the '<' character to the output
                outputBuffer[outputIndex++] = *ptr;
                ptr++;

                // Check for a complete closing tag
                while (*ptr && *ptr != '>') {
                    // Detect quotes (to not alter the content inside them)
                    if (*ptr == '"' || *ptr == '\'') {
                        inQuotes = !inQuotes;  // Toggle the inQuotes status
                    }
                    outputBuffer[outputIndex++] = *ptr;
                    ptr++;
                }
                // Add the '>' character to the output
                outputBuffer[outputIndex++] = *ptr;

                // Check if it's an opening tag (not a closing tag)
                if (*(ptr - 1) != '/') {
                    if (*(ptr - 2) != '/') {
                        indentLevel++;  // Increase indentation for opening tags
                    }
                }
            } else if (*ptr == '\n') {
                // Replace new line with a formatted one
                outputBuffer[outputIndex++] = '\n';
                for (int i = 0; i < indentLevel; i++) {
                    outputBuffer[outputIndex++] = '\t';
                }
                ptr++;
                continue;  // To avoid adding the same character twice
            } else {
                // Add regular characters to the output
                outputBuffer[outputIndex++] = *ptr;
            }
            ptr++;
        }

        // Null-terminate the output buffer
        outputBuffer[outputIndex] = '\0';
        fprintf(output, "%s", outputBuffer);
        free(outputBuffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Call the beautify function to format HTML
    beautifyHTML(inputFile, outputFile);

    // Clean up
    fclose(inputFile);
    fclose(outputFile);

    printf("HTML beautification complete. Output written to '%s'.\n", argv[2]);
    return EXIT_SUCCESS;
}