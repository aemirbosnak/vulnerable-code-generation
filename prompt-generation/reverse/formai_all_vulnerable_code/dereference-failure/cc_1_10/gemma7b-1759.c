//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[10];
    int historyIndex;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = 0;
    calc->historyIndex = 0;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
        return;
    }

    calc->buffer[calc->top++] = number;
}

void calculator_pop(Calculator* calc) {
    if (calc->top == 0) {
        return;
    }

    calc->top--;
}

void calculator_history_push(Calculator* calc, char operation, int value) {
    if (calc->historyIndex >= 10) {
        return;
    }

    calc->history[calc->historyIndex++] = operation;
    calc->history[calc->historyIndex++] = value;
}

int calculator_evaluate(Calculator* calc) {
    int result = 0;
    int i = 0;

    for (i = 0; i < calc->top; i++) {
        switch (calc->buffer[i]) {
            case '+':
                result += calculator_evaluate(calc) + calc->buffer[i + 1] - '0';
                break;
            case '-':
                result -= calculator_evaluate(calc) + calc->buffer[i + 1] - '0';
                break;
            case '*':
                result *= calculator_evaluate(calc) + calc->buffer[i + 1] - '0';
                break;
            case '/':
                result /= calculator_evaluate(calc) + calc->buffer[i + 1] - '0';
                break;
            default:
                result = result * 10 + calc->buffer[i] - '0';
                break;
        }
    }

    return result;
}

int main() {
    Calculator* calc = calculator_init();

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        calculator_push(calc, input[i]);
    }

    int result = calculator_evaluate(calc);

    printf("Result: %d\n", result);

    free(calc);

    return 0;
}