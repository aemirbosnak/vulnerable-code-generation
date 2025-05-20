//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define a struct to represent a C expression
typedef struct {
    char *id;    // identifier (e.g. "x", "y", etc.)
    char *op;    // operator (e.g. "+" , "-", etc.)
    int num1;   // numerical value of first operand
    int num2;   // numerical value of second operand
} CExpr;

// Function to parse a C expression
CExpr *parse_expr(char *str) {
    // Step 1: Tokenize the input string
    char *token = strtok(str, " \t");
    CExpr *expr = NULL;

    // Step 2: Create a new CExpr struct
    expr = malloc(sizeof(CExpr));
    expr->id = token;

    // Step 3: Parse the operator and operands
    while (token = strtok(NULL, " \t")) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
                strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            // Parse the operands
            if (expr->num1 == 0) {
                expr->op = token;
                expr->num2 = atoi(token);
            } else if (expr->num2 == 0) {
                expr->op = token;
                expr->num1 = atoi(token);
            } else {
                // Error: invalid syntax
                printf("Error: invalid syntax\n");
                return NULL;
            }
        } else {
            // Error: invalid token
            printf("Error: invalid token %s\n", token);
            return NULL;
        }
    }

    // Step 4: Return the parsed CExpr struct
    return expr;
}

int main() {
    char *str = "x + 5 * y - 2";
    CExpr *expr = parse_expr(str);

    // Print the parsed expression
    printf("Parsed expression: %s %s %d %d\n", expr->id, expr->op, expr->num1, expr->num2);

    // Free the memory allocated for the CExpr struct
    free(expr);

    return 0;
}