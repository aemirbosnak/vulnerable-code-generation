//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a mathematical expression
typedef struct {
    char op; // operator (e.g. +, -, *, /)
    int num1, num2; // numbers in the expression
} expr_t;

// Function to parse a mathematical expression
expr_t* parse_expr(char* str) {
    // Initialize the expression struct with some default values
    expr_t* exp = (expr_t*)calloc(1, sizeof(expr_t));
    exp->op = '+';
    exp->num1 = 0;
    exp->num2 = 0;

    // Parse the expression and fill in the struct
    char* p = str;
    while (*p != '\0') {
        // Check for operators
        if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            // Save the operator and its arguments
            exp->op = *p;
            p++;
            if (*p == '(') {
                // Parse the arguments inside the parentheses
                p++;
                exp->num1 = parse_expr(p);
                p++;
                exp->num2 = parse_expr(p);
                p++;
            } else {
                // Save the arguments as is
                exp->num1 = atoi(p);
                p++;
                exp->num2 = atoi(p);
            }
        } else {
            // Save the number as is
            exp->num1 = atoi(p);
            p++;
        }
    }

    return exp;
}

int main() {
    // Test expressions
    char* exprs[] = {"2+3", "+4*5", "6/2", "3-2", "2+2"};
    int i;
    for (i = 0; i < sizeof(exprs) / sizeof(char*); i++) {
        expr_t* exp = parse_expr(exprs[i]);
        printf("%c %d %d = %d\n", exp->op, exp->num1, exp->num2, exp->num1 + exp->num2);
        free(exp);
    }
    return 0;
}