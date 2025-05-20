//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->position = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, double number) {
    calc->buffer[calc->position++] = number;
    calc->result += number;
}

void calculator_subtract(Calculator* calc, double number) {
    calc->buffer[calc->position++] = number;
    calc->result -= number;
}

void calculator_multiply(Calculator* calc, double number) {
    calc->buffer[calc->position++] = number;
    calc->result *= number;
}

void calculator_divide(Calculator* calc, double number) {
    calc->buffer[calc->position++] = number;
    calc->result /= number;
}

void calculator_clear(Calculator* calc) {
    calc->position = 0;
    calc->result = 0.0;
}

void calculator_equals(Calculator* calc) {
    double total = 0.0;
    for (int i = 0; i < calc->position; i++) {
        total += (double)calc->buffer[i] * pow(10.0, calc->position - i - 1);
    }
    calc->result = total;
}

int main() {
    Calculator* calc = calculator_init();

    // Perform calculations
    calculator_add(calc, 5.0);
    calculator_multiply(calc, 2.0);
    calculator_subtract(calc, 1.0);
    calculator_divide(calc, 3.0);

    // Get the result
    printf("The result is: %.2lf", calc->result);

    // Clear the calculator
    calculator_clear(calc);

    return 0;
}