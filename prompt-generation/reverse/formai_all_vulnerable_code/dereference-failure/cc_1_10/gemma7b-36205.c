//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    char operator;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->top = -1;
    calc->operator = '\0';
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char num) {
    if (calc->top == MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->top] = num;
}

void calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        return;
    }
    calc->top--;
}

void calculator_set_operator(Calculator* calc, char op) {
    calc->operator = op;
}

double calculator_get_result(Calculator* calc) {
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();

    // Calculate 5 + 3 =
    calculator_push(calc, '5');
    calculator_push(calc, '+');
    calculator_push(calc, '3');
    calculator_set_operator(calc, '=');
    calc->result = calculator_get_result(calc);

    // Print the result
    printf("The result is: %.2lf\n", calc->result);

    // Free the calculator
    free(calc);

    return 0;
}