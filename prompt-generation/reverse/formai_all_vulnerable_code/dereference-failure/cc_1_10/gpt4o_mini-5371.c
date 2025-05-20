//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

typedef struct {
    char operator;
    double operand;
} Token;

typedef struct {
    Token *tokens;
    size_t size;
} TokenList;

void initTokenList(TokenList *list) {
    list->tokens = malloc(MAX_INPUT_LENGTH * sizeof(Token));
    list->size = 0;
}

void freeTokenList(TokenList *list) {
    free(list->tokens);
    list->size = 0;
}

void addToken(TokenList *list, char operator, double operand) {
    list->tokens[list->size].operator = operator;
    list->tokens[list->size].operand = operand;
    list->size++;
}

void parseExpression(const char *expression, TokenList *list) {
    const char *ptr = expression;
    char operator = 0;
    double operand;
    
    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        if (isdigit(*ptr) || (*ptr == '-' && isdigit(*(ptr + 1)))) {
            operand = strtod(ptr, (char**)&ptr);
            addToken(list, operator, operand);
            operator = 0; // Reset operator after an operand.
        } else {
            operator = *ptr;
            ptr++;
        }
    }
}

double evaluateExpression(TokenList *list) {
    double result = 0.0;
    
    // Evaluate the first operand.
    if (list->size == 0) return result;
    
    result += list->tokens[0].operand;

    for (size_t i = 1; i < list->size; i++) {
        if (list->tokens[i].operator == '+') {
            result += list->tokens[i].operand;
        } else if (list->tokens[i].operator == '-') {
            result -= list->tokens[i].operand;
        } else if (list->tokens[i].operator == '*') {
            result *= list->tokens[i].operand;
        } else if (list->tokens[i].operator == '/') {
            if (list->tokens[i].operand != 0) {
                result /= list->tokens[i].operand;
            } else {
                fprintf(stderr, "Error: Division by zero!\n");
                return 0;
            }
        } else {
            fprintf(stderr, "Unrecognized operator: %c\n", list->tokens[i].operator);
        }
    }
    
    return result;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    TokenList tokenList;

    printf("Enter a mathematical expression (e.g., 3 + 4 * 2): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    initTokenList(&tokenList);
    parseExpression(input, &tokenList);
    
    double result = evaluateExpression(&tokenList);
    printf("The result of the expression is: %.2f\n", result);

    freeTokenList(&tokenList);
    return 0;
}