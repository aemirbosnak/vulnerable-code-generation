//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 256

typedef struct {
    char *tokens[MAX_EXPR_LENGTH];
    int token_count;
} Expression;

void free_expression(Expression *expr) {
    for (int i = 0; i < expr->token_count; i++) {
        free(expr->tokens[i]);
    }
    expr->token_count = 0;
}

int is_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void tokenize_expression(const char *input, Expression *expr) {
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, " ");
    
    while (token != NULL) {
        expr->tokens[expr->token_count++] = strdup(token);
        token = strtok(NULL, " ");
    }

    free(input_copy);
}

int validate_expression(Expression *expr) {
    for (int i = 0; i < expr->token_count; i++) {
        if (!isdigit(expr->tokens[i][0]) && !is_operator(expr->tokens[i][0])) {
            printf("Error: Invalid token '%s'\n", expr->tokens[i]);
            return 0;
        }
    }
    return 1;
}

int evaluate_expression(Expression *expr) {
    int result = atoi(expr->tokens[0]);
    for (int i = 1; i < expr->token_count; i += 2) {
        char op = expr->tokens[i][0];
        int next_value = atoi(expr->tokens[i + 1]);
        switch (op) {
            case '+':
                result += next_value;
                break;
            case '-':
                result -= next_value;
                break;
            case '*':
                result *= next_value;
                break;
            case '/':
                if (next_value == 0) {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                result /= next_value;
                break;
        }
    }
    return result;
}

int main() {
    char input[MAX_EXPR_LENGTH];
    Expression expr = {.token_count = 0};

    printf("Enter a mathematical expression (e.g., 3 + 4 * 2): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    tokenize_expression(input, &expr);

    if (validate_expression(&expr)) {
        int result = evaluate_expression(&expr);
        printf("Result: %d\n", result);
    } else {
        fprintf(stderr, "Invalid expression\n");
    }

    free_expression(&expr);
    return EXIT_SUCCESS;
}