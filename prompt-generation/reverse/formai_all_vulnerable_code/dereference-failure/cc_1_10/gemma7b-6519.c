//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->top = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char operand) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->top] = operand;
}

double calculator_pop(Calculator* calc) {
    if (calc->top < 0) {
        return -1.0;
    }
    return (double)calc->buffer[calc->top--];
}

double calculator_calculate(Calculator* calc) {
    double a, b, result;
    char operator;

    a = calculator_pop(calc);
    operator = calculator_pop(calc);
    b = calculator_pop(calc);

    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = b - a;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                return -1.0;
            }
            result = b / a;
            break;
        default:
            return -1.0;
    }

    calc->result = result;
    return result;
}

int main() {
    Calculator* calc = calculator_init();

    // Example usage
    calculator_push(calc, '5');
    calculator_push(calc, '2');
    calculator_push(calc, '+');
    calculator_push(calc, '3');
    calculator_push(calc, '-');
    calculator_push(calc, '4');
    calculator_push(calc, '*');
    calculator_push(calc, '6');
    calculator_push(calc, '/');

    calculator_calculate(calc);

    // Print the result
    printf("The result is: %.2lf", calc->result);

    return 0;
}