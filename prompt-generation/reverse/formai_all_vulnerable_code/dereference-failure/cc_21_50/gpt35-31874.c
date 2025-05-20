//FormAI DATASET v1.0 Category: Syntax parsing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Asynchronous style function to parse a C syntax statement
void parse_c_syntax(char *input) {
    int i = 0;
    bool is_valid = true;
    bool is_keyword = false;
    bool is_identifier = false;
    bool is_operator = false;
    bool is_literal = false;
    bool is_comment = false;
    bool is_header = false;
    char curr_char;

    // Loop through the input string character by character and determine the type of token
    while (true) {
        curr_char = input[i];

         // Check if we are currently inside a comment
        if (curr_char == '/' && input[i + 1] == '/') {
            is_comment = true;
        }

        // Check if we are currently inside a header file
        if (curr_char == '<' && input[i + 1] == 'h') {
            is_header = true;
        }

        // Check if the current character is a keyword
        if (isalpha(curr_char) && !is_identifier && !is_literal && !is_comment && !is_operator && !is_header) {
            is_keyword = true;
        } else {
            is_keyword = false;
        }

        // Check if the current character is an identifier
        if (!isalpha(curr_char) && isalnum(curr_char) && !is_keyword && !is_literal && !is_comment && !is_operator && !is_header) {
            is_identifier = true;
        } else {
            is_identifier = false;
        }

        // Check if the current character is a literal
        if ((curr_char == '\"' || curr_char == '\'') && !is_comment && !is_operator && !is_header) {
            is_literal = true;
        }

        // Check if the current character is an operator
        if ((curr_char == '+' || curr_char == '-' || curr_char == '*' || curr_char == '/' || curr_char == '=' || curr_char == '>' || curr_char == '<') && !is_comment && !is_literal && !is_header) {
            is_operator = true;
        } else {
            is_operator = false;
        }

        // Check if we have reached the end of the input string
        if (curr_char == '\0') {
            break;
        }

        // Print out the type of token
        if (is_keyword) {
            printf("Keyword: ");
        } else if (is_identifier) {
            printf("Identifier: ");
        } else if (is_operator) {
            printf("Operator: ");
        } else if (is_literal) {
            printf("Literal: ");
        } else if (is_comment) {
            printf("Comment: ");
        } else if (is_header) {
            printf("Header: ");
        }

        // Print out the actual token
        while (!isspace(curr_char) && curr_char != '\0') {
            printf("%c", curr_char);
            i++;
            curr_char = input[i];
        }

        printf("\n");

        // Reset boolean flags for the next token
        is_keyword = false;
        is_identifier = false;
        is_operator = false;
        is_literal = false;
        is_comment = false;
        is_header = false;

        i++; // Increment the current index
    }
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a C syntax statement: ");
    fgets(input, MAX_SIZE, stdin);

    printf("\nTokenizing C syntax statement...\n");
    parse_c_syntax(input);

    return 0;
}