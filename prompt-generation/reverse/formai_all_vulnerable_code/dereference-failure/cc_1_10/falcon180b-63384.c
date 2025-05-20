//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100
#define MAX_RESULT_LEN 100

// Tokenizer function
char* tokenizer(char* str) {
    char* token = strtok(str, " ");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Evaluate expression function
int evaluate_expression(char* expression, double* result) {
    char* endptr;
    double value = strtod(expression, &endptr);
    if (*endptr!= '\0') {
        printf("Invalid expression.\n");
        return 0;
    }
    *result = value;
    return 1;
}

// Main function
int main() {
    char expression[MAX_EXPR_LEN];
    double result;

    // Prompt user to enter expression
    printf("Enter expression: ");
    fgets(expression, MAX_EXPR_LEN, stdin);

    // Tokenize expression
    tokenizer(expression);

    // Evaluate expression
    if (evaluate_expression(expression, &result)) {
        printf("Result: %.2f\n", result);
    }

    return 0;
}