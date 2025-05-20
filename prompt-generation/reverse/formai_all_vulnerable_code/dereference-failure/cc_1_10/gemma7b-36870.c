//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = -1;
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top == MAX_BUFFER_SIZE - 1) {
        printf("Error: buffer overflow\n");
        return;
    }
    calc->buffer[++calc->top] = number;
}

double calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        printf("Error: stack underflow\n");
        return -1.0;
    }
    return calc->buffer[calc->top--];
}

void calculator_clear(Calculator* calc) {
    calc->top = -1;
    calc->result = 0.0;
}

double calculator_evaluate(Calculator* calc) {
    double result = 0.0;
    char operator;
    int i = 0;

    for (; calc->buffer[i] != '\0'; i++) {
        operator = calc->buffer[i];
        switch (operator) {
            case '+':
                result += calculator_pop(calc);
                break;
            case '-':
                result -= calculator_pop(calc);
                break;
            case '*':
                result *= calculator_pop(calc);
                break;
            case '/':
                result /= calculator_pop(calc);
                break;
            default:
                break;
        }
    }

    calc->result = result;
    return result;
}

int main() {
    Calculator* calc = calculator_init();

    calculator_push(calc, '5');
    calculator_push(calc, '2');
    calculator_push(calc, '+');
    calculator_push(calc, '3');
    calculator_push(calc, '*');
    calculator_push(calc, '4');
    calculator_push(calc, '=');

    calculator_evaluate(calc);

    printf("The result is: %.2lf\n", calc->result);

    calculator_clear(calc);

    return 0;
}