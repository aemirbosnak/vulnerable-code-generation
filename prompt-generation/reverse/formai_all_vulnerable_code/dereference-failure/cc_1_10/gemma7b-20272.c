//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

Calculator* calculator_new() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->value = 0.0;
    calc->operator = '\0';
    calc->next = NULL;
    return calc;
}

void calculator_append(Calculator* calc, char operator, double value) {
    calc->operator = operator;
    calc->value = value;
    calc->next = calculator_new();
}

double calculator_eval(Calculator* calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = calc->value + calculator_eval(calc->next);
            break;
        case '-':
            result = calc->value - calculator_eval(calc->next);
            break;
        case '*':
            result = calc->value * calculator_eval(calc->next);
            break;
        case '/':
            result = calc->value / calculator_eval(calc->next);
            break;
        default:
            result = calc->value;
            break;
    }
    return result;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    double result;
    Calculator* calculator = calculator_new();

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression and append operators and values to the calculator
    char* token = strtok(buffer, " ");
    while (token) {
        calculator_append(calculator, token[0], atof(token + 1));
        token = strtok(NULL, " ");
    }

    // Evaluate the expression
    result = calculator_eval(calculator);

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}