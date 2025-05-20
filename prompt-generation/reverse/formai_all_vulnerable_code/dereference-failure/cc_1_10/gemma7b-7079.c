//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char value) {
    calc->buffer[calc->top++] = value;
}

double calculator_pop(Calculator* calc) {
    if (calc->top == 0) {
        return -1.0;
    }
    return (double)calc->buffer[calc->top - 1];
}

double calculator_evaluate(Calculator* calc) {
    double result = 0.0;
    char operator = '\0';
    int i = 0;

    for (i = 0; i < calc->top; i++) {
        char number = calc->buffer[i];

        if (number >= '0' && number <= '9') {
            result = result * 10 + number - '0';
        } else if (operator != '\0') {
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
            }
        } else {
            operator = number;
        }
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
    calculator_push(calc, '*');
    calculator_push(calc, '4');
    calculator_push(calc, '=');

    double result = calculator_evaluate(calc);

    printf("The result is: %.2lf\n", result);

    return 0;
}