//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    double result;
    char operator;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->position = 0;
    calc->result = 0.0;
    calc->operator = '\0';
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->position++] = num;
    calc->operator = '+';
}

void calculator_subtract(Calculator* calc, double num) {
    calc->buffer[calc->position++] = num;
    calc->operator = '-';
}

void calculator_multiply(Calculator* calc, double num) {
    calc->buffer[calc->position++] = num;
    calc->operator = '*';
}

void calculator_divide(Calculator* calc, double num) {
    calc->buffer[calc->position++] = num;
    calc->operator = '/';
}

double calculator_calculate(Calculator* calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = calc->buffer[0] + calc->buffer[1];
            break;
        case '-':
            result = calc->buffer[0] - calc->buffer[1];
            break;
        case '*':
            result = calc->buffer[0] * calc->buffer[1];
            break;
        case '/':
            result = calc->buffer[0] / calc->buffer[1];
            break;
    }
    calc->result = result;
    return result;
}

int main() {
    Calculator* calc = calculator_init();
    calculator_add(calc, 10.0);
    calculator_add(calc, 20.0);
    calculator_multiply(calc, 2.0);
    calculator_divide(calc, 4.0);
    double result = calculator_calculate(calc);
    printf("The result is: %f", result);
    return 0;
}