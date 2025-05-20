//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

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

double calculator_get_result(Calculator* calc) {
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();

    // Calculate the following expression: (10 + 2) * 3 - 5 / 2
    calculator_add(calc, 10.0);
    calculator_add(calc, 2.0);
    calculator_multiply(calc, 3.0);
    calculator_subtract(calc, 5.0);
    calculator_divide(calc, 2.0);

    // Print the result
    printf("The result is: %.2lf\n", calculator_get_result(calc));

    // Free the calculator
    free(calc);

    return 0;
}