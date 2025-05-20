//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our very own parser!
struct parser {
    char *input;
    int index;
};

// Initialize our parser with the input string
void init_parser(struct parser *p, char *input) {
    p->input = input;
    p->index = 0;
}

// Get the next character from the input
char get_char(struct parser *p) {
    return p->input[p->index++];
}

// Check if the current character is a space
int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Skip spaces in the input
void skip_spaces(struct parser *p) {
    while (is_space(get_char(p)));
}

// Get the next token from the input
char *get_token(struct parser *p) {
    skip_spaces(p);

    // Check if we've reached the end of the input
    if (p->index >= strlen(p->input)) {
        return NULL;
    }

    // Get the start of the token
    int start = p->index;

    // Advance the index until we reach the end of the token
    while (!is_space(get_char(p)));

    // Create a string for the token
    char *token = malloc(p->index - start + 1);

    // Copy the token into the string
    strncpy(token, p->input + start, p->index - start);

    // Add the null terminator to the string
    token[p->index - start] = '\0';

    // Return the token
    return token;
}

// Parse an expression
int parse_expression(struct parser *p) {
    // Get the first token
    char *token = get_token(p);

    // Check if the token is a number
    if (token != NULL && isdigit(token[0])) {
        // Convert the token to an integer
        int value = atoi(token);

        // Free the token
        free(token);

        // Return the value of the expression
        return value;
    }

    // Check if the token is an operator
    if (token != NULL && (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)) {
        // Get the left and right operands
        int left = parse_expression(p);
        int right = parse_expression(p);

        // Perform the operation
        int result;
        if (strcmp(token, "+") == 0) {
            result = left + right;
        } else if (strcmp(token, "-") == 0) {
            result = left - right;
        } else if (strcmp(token, "*") == 0) {
            result = left * right;
        } else if (strcmp(token, "/") == 0) {
            result = left / right;
        }

        // Free the token
        free(token);

        // Return the result of the expression
        return result;
    }

    // If we reach this point, there was an error in the input
    printf("Error: Invalid expression\n");
    exit(1);
}

// Parse the input string
int main() {
    // Get the input string from the user
    char input[1024];
    printf("Enter an expression: ");
    fgets(input, 1024,stdin);

    // Initialize the parser
    struct parser p;
    init_parser(&p, input);

    // Parse the expression
    int result = parse_expression(&p);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}