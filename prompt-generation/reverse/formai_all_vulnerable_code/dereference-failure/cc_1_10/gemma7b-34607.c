//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[100];
    int historyIndex;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->historyIndex = 0;
    return calculator;
}

void calculator_push(Calculator* calculator, char number) {
    calculator->buffer[++calculator->top] = number;
}

char calculator_pop(Calculator* calculator) {
    if (calculator->top == -1) {
        return '\0';
    } else {
        return calculator->buffer[calculator->top--];
    }
}

int calculator_evaluate(Calculator* calculator) {
    int result = 0;
    int i = calculator->top;
    char operator;

    while (i >= 0) {
        operator = calculator->buffer[i];
        switch (operator) {
            case '+':
                result += calculator_pop(calculator) - '0';
                break;
            case '-':
                result -= calculator_pop(calculator) - '0';
                break;
            case '*':
                result *= calculator_pop(calculator) - '0';
                break;
            case '/':
                result /= calculator_pop(calculator) - '0';
                break;
            default:
                break;
        }
        i--;
    }

    return result;
}

void calculator_history_add(Calculator* calculator, int result) {
    calculator->history[calculator->historyIndex++] = result;
}

int main() {
    Calculator* calculator = calculator_init();

    // Example usage:
    calculator_push(calculator, '5');
    calculator_push(calculator, '3');
    calculator_push(calculator, '+');
    calculator_push(calculator, '2');
    calculator_push(calculator, '*');
    calculator_push(calculator, '4');
    calculator_push(calculator, '=');

    int result = calculator_evaluate(calculator);
    calculator_history_add(calculator, result);

    printf("Result: %d\n", result);

    // Print history:
    for (int i = 0; i < calculator->historyIndex; i++) {
        printf("History: %d\n", calculator->history[i]);
    }

    return 0;
}