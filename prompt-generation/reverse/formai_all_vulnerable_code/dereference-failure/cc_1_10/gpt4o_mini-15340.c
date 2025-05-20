//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 2048

// Function to check if the current character is a tag
int isTag(char c) {
    return (c == '<' || c == '>');
}

// Function to beautify the HTML content
void beautifyHTML(const char *input, char *output) {
    int indentLevel = 0;
    int inTag = 0;
    int outputIndex = 0;
    char ch;

    for (int i = 0; input[i] != '\0'; i++) {
        ch = input[i];

        if (isTag(ch)) {
            if (ch == '<') {
                if (inTag) {
                    // Close current tag
                    output[outputIndex++] = ch;
                } else {
                    // New tag start, handle indent
                    if (i > 0 && input[i - 1] != '\n') {
                        output[outputIndex++] = '\n';
                        for (int j = 0; j < indentLevel; j++) {
                            output[outputIndex++] = '\t';
                        }
                    }
                    output[outputIndex++] = ch;
                    inTag = 1;
                    if (input[i + 1] == '/') {
                        indentLevel--;
                    }
                }
            } else {
                output[outputIndex++] = ch;
                if (ch == '>') {
                    inTag = 0;
                    // Handle indent level for open tags
                    if (input[i - 1] != '/') {
                        indentLevel++;
                    }
                }
            }
        } else {
            output[outputIndex++] = ch;
        }
    }
    output[outputIndex] = '\0'; // Null-terminate the output string
}

// Main function to run the beautifier
int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];

    printf("Enter the HTML content (end with EOF):\n");
    
    // Read the entire input until EOF
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    
    beautifyHTML(input, output);
    
    printf("\nBeautified HTML content:\n%s\n", output);
    return 0;
}