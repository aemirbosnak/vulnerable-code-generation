//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to hold the syntax elements
typedef struct {
    char *id;   // identifier (e.g. "if", "while", etc.)
    char *left; // left operand
    char *right; // right operand
} SyntaxElement;

// Function to parse a single line of C code
SyntaxElement parseLine(char *line) {
    // Tokenize the line into individual words
    char *words[5];
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < 5) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }

    // Check if the line is a keyword
    if (strcmp(words[0], "if") == 0) {
        // If it is, return an element with the keyword and the two operands
        return (SyntaxElement) {
            .id = words[0],
            .left = words[1],
            .right = words[2]
        };
    } else if (strcmp(words[0], "while") == 0) {
        // If it's a while loop, return an element with the keyword and the condition
        return (SyntaxElement) {
            .id = words[0],
            .left = words[1],
            .right = words[2]
        };
    } else {
        // If it's not a keyword, return an element with the entire line as the right operand
        return (SyntaxElement) {
            .id = words[0],
            .left = words[1],
            .right = line
        };
    }
}

int main() {
    // Read in a list of lines from standard input
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Parse the line and print the result
        SyntaxElement element = parseLine(line);
        printf("Parsed line: %s (%s %s %s)\n", element.id, element.left, element.right, element.id);
    }
    return 0;
}