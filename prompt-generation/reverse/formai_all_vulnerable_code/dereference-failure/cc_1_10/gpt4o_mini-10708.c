//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *input;
int pos = 0;

// Function to skip whitespace
void skipWhitespace() {
    while (input[pos] == ' ') {
        pos++;
    }
}

// Function to parse numbers
int parseNumber() {
    int value = 0;
    while (isdigit(input[pos])) {
        value = value * 10 + (input[pos] - '0');
        pos++;
    }
    return value;
}

// Function to parse factor (number or parentheses)
int parseFactor() {
    skipWhitespace();
    if (input[pos] == '(') {
        pos++;  // consuming '('
        int value = parseExpression();
        pos++;  // consuming ')'
        return value;
    } else {
        return parseNumber();
    }
}

// Function to parse term (factors with * or /)
int parseTerm() {
    int value = parseFactor();
    skipWhitespace();
    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos++];
        int right = parseFactor();
        if (op == '*') {
            value *= right;
        } else if (op == '/') {
            if (right == 0) {
                fprintf(stderr, "Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            value /= right;
        }
        skipWhitespace();
    }
    return value;
}

// Function to parse expression (terms with + or -)
int parseExpression() {
    int value = parseTerm();
    skipWhitespace();
    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos++];
        int right = parseTerm();
        if (op == '+') {
            value += right;
        } else if (op == '-') {
            value -= right;
        }
        skipWhitespace();
    }
    return value;
}

// Main function to drive the parser
int main() {
    // Prompt the user for an arithmetic expression
    printf("Welcome to the Magical Arithmetic Parser!\n");
    printf("Enter an expression (e.g., 2 + 3 * (4 - 1)): ");
    
    // Getting input from user
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    input = strdup(buffer);  // Duplicate the input for processing
    
    // Parse and evaluate the expression
    int result = parseExpression();
    
    // Output the result
    printf("The result of your magical expression is: %d\n", result);
    
    // Clean up dynamically allocated memory
    free(input);
    
    return 0;
}