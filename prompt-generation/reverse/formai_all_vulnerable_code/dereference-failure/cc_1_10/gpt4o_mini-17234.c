//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 256

char *input;
char current_char;
int position = 0;

void error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void next_char() {
    if (position < strlen(input)) {
        current_char = input[position++];
    } else {
        current_char = '\0';  // End of input
    }
}

void skip_whitespace() {
    while (isspace(current_char)) {
        next_char();
    }
}

int parse_expression(); 

int parse_factor() {
    skip_whitespace();
    
    int result = 0;

    if (isdigit(current_char)) {
        // Handle numbers
        while (isdigit(current_char)) {
            result = result * 10 + (current_char - '0');
            next_char();
        }
    } else if (current_char == '(') {
        next_char(); // Skip '('
        result = parse_expression();
        if (current_char != ')') {
            error("Missing closing parenthesis.");
        }
        next_char(); // Skip ')'
    } else {
        error("Unexpected character.");
    }

    return result;
}

int parse_term() {
    int result = parse_factor();

    while (1) {
        skip_whitespace();
        if (current_char == '*' || current_char == '/') {
            char op = current_char;
            next_char(); // Skip operator
            int next_factor = parse_factor();
            if (op == '*') {
                result *= next_factor;
            } else {
                if (next_factor == 0) {
                    error("Division by zero.");
                }
                result /= next_factor;
            }
        } else {
            break; // Exit loop if no more terms
        }
    }

    return result;
}

int parse_expression() {
    int result = parse_term();

    while (1) {
        skip_whitespace();
        if (current_char == '+' || current_char == '-') {
            char op = current_char;
            next_char(); // Skip operator
            int next_term = parse_term();
            if (op == '+') {
                result += next_term;
            } else {
                result -= next_term;
            }
        } else {
            break; // Exit loop if no more expressions
        }
    }

    return result;
}

int evaluate_expression(const char *expr) {
    input = strdup(expr);
    position = 0;
    next_char();
    int result = parse_expression();
    skip_whitespace();
    if (current_char != '\0') {
        error("Extra input after valid expression.");
    }
    free(input);
    return result;
}

int main() {
    char input_expr[MAX_INPUT];

    printf("Enter an arithmetic expression (e.g., 3 + 5 * (2 - 8)): ");
    fgets(input_expr, MAX_INPUT, stdin);

    // Remove newline character if present
    size_t len = strlen(input_expr);
    if (len > 0 && input_expr[len - 1] == '\n') {
        input_expr[len - 1] = '\0';
    }

    int result = evaluate_expression(input_expr);
    printf("Result: %d\n", result);

    return 0;
}