//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100
#define MAX_TOKENS 50

typedef struct {
    char *tokens[MAX_TOKENS];
    int count;
} TokenList;

// Function to initialize the token list
void initTokenList(TokenList *list) {
    list->count = 0;
}

// Function to free the token list
void freeTokenList(TokenList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->tokens[i]);
    }
}

// Function to tokenize the input expression
void tokenize(const char *expression, TokenList *list) {
    const char *delimiters = " \t";
    char *token = strtok((char *)expression, delimiters);
    
    while (token != NULL) {
        if (list->count < MAX_TOKENS) {
            list->tokens[list->count] = malloc(strlen(token) + 1);
            strcpy(list->tokens[list->count], token);
            list->count++;
        }
        token = strtok(NULL, delimiters);
    }
}

// Function to evaluate a simple expression
int evaluate(TokenList *list) {
    int i = 0;
    int result = atoi(list->tokens[i++]);

    while (i < list->count) {
        char operator = list->tokens[i++][0];
        int operand = atoi(list->tokens[i++]);

        switch (operator) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                if (operand != 0) {
                    result /= operand;
                } else {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                fprintf(stderr, "Error: Unknown operator %c\n", operator);
                exit(EXIT_FAILURE);
        }
    }
    
    return result;
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    TokenList tokenList;

    printf("Enter a mathematical expression (e.g., 5 + 10 - 2 * 3): ");
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // Remove trailing newline character
    expression[strcspn(expression, "\n")] = '\0';

    initTokenList(&tokenList);
    tokenize(expression, &tokenList);
    
    int result = evaluate(&tokenList);
    printf("Result: %d\n", result);

    freeTokenList(&tokenList);
    return 0;
}