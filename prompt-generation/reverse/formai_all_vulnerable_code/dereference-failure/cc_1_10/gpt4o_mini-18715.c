//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char operator;
    double operand;
} Token;

char *expression;
int current_position = 0;

Token get_next_token() {
    Token token;
    token.operator = '\0';
    token.operand = 0;

    while (isspace(expression[current_position])) {
        current_position++;
    }

    if (isdigit(expression[current_position])) {
        token.operator = '\0';
        token.operand = strtod(&expression[current_position], &expression[current_position]);
    } else if (expression[current_position] == '+' || 
               expression[current_position] == '-' || 
               expression[current_position] == '*' || 
               expression[current_position] == '/') {
        token.operator = expression[current_position++];
    }
    
    return token;
}

double parse_expression() {
    Token current_token = get_next_token();
    double result = current_token.operand;

    while (current_token.operator != '\0') {
        char op = current_token.operator;
        current_token = get_next_token();
        double next_operand = current_token.operand;

        switch (op) {
            case '+': 
                result += next_operand; 
                break;
            case '-': 
                result -= next_operand; 
                break;
            case '*': 
                result *= next_operand; 
                break;
            case '/': 
                if (next_operand != 0)
                    result /= next_operand; 
                else {
                    printf("Error: Division by zero.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default: 
                printf("Error: Unknown operator %c\n", op);
                exit(EXIT_FAILURE);
        }
        current_token = get_next_token();
    }
    
    return result;
}

int main() {
    expression = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (expression == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter a mathematical expression (e.g., 3 + 4 * 2 / (1 - 5)): ");
    fgets(expression, MAX_LENGTH, stdin);
    // Removing newline character if it's read in
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    double result = parse_expression();
    printf("The result is: %f\n", result);

    free(expression);
    return 0;
}