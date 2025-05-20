//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    float result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = -1;
    calc->result = 0.0f;
    return calc;
}

void calculator_push(Calculator* calc, char num) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
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

void calculator_set_result(Calculator* calc, float result) {
    calc->result = result;
}

float calculator_get_result(Calculator* calc) {
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();

    // Example usage:
    calculator_push(calc, '5');
    calculator_push(calc, '2');
    calculator_push(calc, '+');
    calculator_push(calc, '3');
    calculator_push(calc, '=');

    calculator_set_result(calc, calculator_get_result(calc) + 10.0f);

    printf("The result is: %.2f", calculator_get_result(calc));

    return 0;
}