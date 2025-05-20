//FormAI DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A simple C program that demonstrates parsing and evaluating arithmetic expressions */

/* Function prototypes */
double parse_expression(char *);
double parse_term(char *);
double parse_factor(char *);
bool is_op(char c);

/* Utility macro to handle whitespace */
#define skip_whitespace(str) \
    while(*str == ' ') { \
        str++; \
    }

int main() {
    char expression[] = "4 * (3 + 2) - 6 / 2";
    double result = parse_expression(expression);
    printf("Result: %lf", result);
    return 0;
}

/* Parse an arithmetic expression */
double parse_expression(char *str) {
    double value = parse_term(str);
    while (*str) {
        if (*str == '+') {
            value += parse_term(str + 1);
        }
        else if (*str == '-') {
            value -= parse_term(str + 1);
        }
        else {
            return value;
        }
    }
    return value;
}

/* Parse an arithmetic term */
double parse_term(char *str) {
    double value = parse_factor(str);
    while (*str) {
        if (*str == '*') {
            value *= parse_factor(str + 1);
        }
        else if (*str == '/') {
            double divisor = parse_factor(str + 1);
            if (divisor == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            value /= divisor;
        }
        else {
            return value;
        }
    }
    return value;
}

/* Parse an arithmetic factor */
double parse_factor(char *str) {
    double value;
    skip_whitespace(str);
    if (*str == '(') {
        /* Evaluate the sub-expression */
        value = parse_expression(str + 1);

        /* Check for matching closing parenthesis */
        skip_whitespace(str);
        if(*str != ')') {
            printf("Error: Missing closing parenthesis\n");
            exit(1);
        }
    }
    else if (isdigit(*str)) {
        /* Parse a numeric literal */
        char *endptr;
        value = strtod(str, &endptr);
        str = endptr - 1;
    }
    else {
        printf("Error: Unexpected character: %c\n", *str);
        exit(1);
    }
    /* Handle any unary operators */
    str++;
    while (is_op(*str)) {
        if (*str == '-') {
            value = -value;
        }
        str++;
    }
    return value;
}

/* Check if a character is an operator */
bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}