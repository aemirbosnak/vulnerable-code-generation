//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int is_numeric(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

double get_number(char* str) {
    int len = strlen(str);
    char* endptr;
    double num = strtod(str, &endptr);
    if (endptr == str) {
        printf("Invalid number: %s\n", str);
        exit(1);
    }
    return num;
}

int get_operator_priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

double apply_operator(double num1, double num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        default:
            printf("Invalid operator: %c\n", op);
            exit(1);
    }
}

double evaluate_expression(char* expr) {
    int len = strlen(expr);
    char* token = strtok(expr, " ");
    double num1 = get_number(token);
    while ((token = strtok(NULL, " "))!= NULL) {
        if (is_numeric(token)) {
            double num2 = get_number(token);
            num1 = apply_operator(num1, num2, '+');
        } else {
            char op = token[0];
            double num2 = get_number(token + 1);
            while (get_operator_priority(op) <= get_operator_priority(expr[len - 1])) {
                num1 = apply_operator(num1, num2, op);
                if ((token = strtok(NULL, " ")) == NULL) {
                    break;
                }
                op = token[0];
                num2 = get_number(token + 1);
            }
            expr[len - 1] = '\0';
            strcat(expr, token);
        }
    }
    return num1;
}

int main() {
    char input[100];
    while (1) {
        printf("Enter an expression: ");
        fgets(input, sizeof(input), stdin);
        double result = evaluate_expression(input);
        printf("Result: %.2f\n", result);
    }
    return 0;
}