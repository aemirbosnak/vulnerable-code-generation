//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold the syntax of a C program
typedef struct {
    char *name;      // Name of the variable
    char *type;     // Type of the variable
    int line;       // Line number where the variable is declared
} syntax_t;

// Function to parse the input string and extract the syntax
syntax_t *parse_string(char *input) {
    // Initialize the syntax structure to NULL
    syntax_t *syntax = NULL;

    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current character is a keyword
        if (strchr("if else switch case default", input[i]) != NULL) {
            // If it is a keyword, extract the keyword and the following space
            char *keyword = strndup(input + i, 1);
            i++;

            // Check if the keyword is "if"
            if (strcmp(keyword, "if") == 0) {
                // If it is "if", extract the condition and the following space
                char *condition = strndup(input + i + 1, 1);
                i++;

                // Check if the condition is a valid expression
                if (is_valid_expression(condition)) {
                    // If the condition is valid, create a new syntax structure
                    syntax = (syntax_t *)malloc(sizeof(syntax_t));
                    syntax->name = keyword;
                    syntax->type = "condition";
                    syntax->line = i - 1;

                    // Advance the loop to the next character
                    i++;
                }
            }

            // Check if the keyword is "else"
            else if (strcmp(keyword, "else") == 0) {
                // If it is "else", extract the following space and the "{"
                char *else_token = strndup(input + i + 1, 1);
                i++;

                // Check if the "else" token is followed by a "{"
                if (input[i] == '{') {
                    // If it is, create a new syntax structure
                    syntax = (syntax_t *)malloc(sizeof(syntax_t));
                    syntax->name = keyword;
                    syntax->type = "else clause";
                    syntax->line = i - 1;

                    // Advance the loop to the next character
                    i++;
                }
            }
        }

        // Check if the current character is a identifier or a number
        else if (isalpha(input[i]) || isdigit(input[i])) {
            // If it is a identifier or a number, extract the identifier or number
            char *identifier = strndup(input + i, 1);

            // Check if the identifier is a variable
            if (is_variable(identifier)) {
                // If it is a variable, create a new syntax structure
                syntax = (syntax_t *)malloc(sizeof(syntax_t));
                syntax->name = identifier;
                syntax->type = "variable";
                syntax->line = i - 1;
            }
        }
    }

    // Return the syntax structure
    return syntax;
}

// Function to check if a string is a valid C expression
int is_valid_expression(char *expression) {
    // Check if the expression is a simple identifier
    if (isalpha(expression[0]) && isalpha(expression[1])) {
        // If it is a simple identifier, return 1
        return 1;
    }

    // Check if the expression is a number
    else if (isdigit(expression[0])) {
        // If it is a number, return 1
        return 1;
    }

    // Check if the expression is a binary operator
    else if (expression[0] == '+' || expression[0] == '-' || expression[0] == '*' || expression[0] == '/') {
        // If it is a binary operator, return 1
        return 1;
    }

    // Check if the expression is a unary operator
    else if (expression[0] == '!' || expression[0] == '~') {
        // If it is a unary operator, return 1
        return 1;
    }

    // If the expression is not a valid C expression, return 0
    return 0;
}

// Function to check if a string is a variable
int is_variable(char *name) {
    // Check if the name is a simple identifier
    if (isalpha(name[0]) && isalpha(name[1])) {
        // If it is a simple identifier, return 1
        return 1;
    }

    // If the name is not a variable, return 0
    return 0;
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a C program:\n");
    fgets(input, 100, stdin);

    // Parse the input string and extract the syntax
    syntax_t *syntax = parse_string(input);

    // Print the syntax structure
    printf("Syntax of the C program:\n");
    printf("Name: %s\n", syntax->name);
    printf("Type: %s\n", syntax->type);
    printf("Line: %d\n", syntax->line);

    // Free the memory allocated for the syntax structure
    free(syntax);

    return 0;
}