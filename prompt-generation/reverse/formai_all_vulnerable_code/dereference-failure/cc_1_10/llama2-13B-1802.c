//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERands 100
#define MAX_EXPR_LEN 100

// Structure to hold the expression and the operands
typedef struct {
    char *expr;
    int operands[MAX_OPERands];
} expr_t;

// Function to parse the input expression and return the evaluated result
int eval_expr(const char *expr) {
    // Tokenize the expression into operands and operators
    char *token, *next_token;
    int i = 0;
    expr_t *exp = malloc(sizeof(expr_t));
    exp->expr = expr;

    while ((token = strtok_r(expr, "+-*/", &next_token)) != NULL) {
        if (i >= MAX_OPERands) {
            fprintf(stderr, "Too many operands\n");
            return -1;
        }

        // Handle operators
        if (token[0] == '+') {
            exp->operands[i++] = 1;
        } else if (token[0] == '-') {
            exp->operands[i++] = -1;
        } else if (token[0] == '*') {
            exp->operands[i++] = pow(exp->operands[i - 1], atof(token + 1));
        } else if (token[0] == '/') {
            exp->operands[i++] = pow(exp->operands[i - 1], atof(token + 1));
        } else {
            fprintf(stderr, "Invalid operator\n");
            return -1;
        }
    }

    // Evaluate the expression
    int result = 0;
    for (int j = 0; j < i; j++) {
        result = (result *= exp->operands[j]) + exp->operands[j];
    }

    free(exp);
    return result;
}

int main() {
    srand(time(NULL));

    // Generate a random expression
    char *expr = malloc(MAX_EXPR_LEN);
    for (int i = 0; i < MAX_EXPR_LEN; i++) {
        expr[i] = 'a' + rand() % 26;
    }

    // Evaluate the expression
    int result = eval_expr(expr);

    // Print the result
    printf("%d\n", result);

    return 0;
}