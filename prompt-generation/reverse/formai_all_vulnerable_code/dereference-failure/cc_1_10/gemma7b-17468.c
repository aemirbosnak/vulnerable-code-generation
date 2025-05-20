//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 255

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
    char operator;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->result = 0.0;
    calc->operator = '\0';
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = num;
    calc->operator = '+';
}

void calculator_subtract(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = num;
    calc->operator = '-';
}

void calculator_multiply(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = num;
    calc->operator = '*';
}

void calculator_divide(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = num;
    calc->operator = '/';
}

void calculator_equal(Calculator* calc) {
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
}

int main() {
    Calculator* calc = calculator_init();

    // Calculate 5 + 10 = 15
    calculator_add(calc, 5);
    calculator_add(calc, 10);
    calculator_equal(calc);
    printf("The result is: %.2lf\n", calc->result);

    // Calculate 10 - 2 = 8
    calculator_subtract(calc, 2);
    calculator_equal(calc);
    printf("The result is: %.2lf\n", calc->result);

    // Calculate 8 * 2 = 16
    calculator_multiply(calc, 2);
    calculator_equal(calc);
    printf("The result is: %.2lf\n", calc->result);

    // Calculate 16 / 2 = 8
    calculator_divide(calc, 2);
    calculator_equal(calc);
    printf("The result is: %.2lf\n", calc->result);

    return 0;
}