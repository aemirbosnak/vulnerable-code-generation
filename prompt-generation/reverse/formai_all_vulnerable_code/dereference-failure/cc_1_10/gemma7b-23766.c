//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[10];
    int history_index;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = 0;
    calc->history_index = 0;
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

void calculator_clear(Calculator* calc) {
    calc->top = 0;
}

void calculator_history_add(Calculator* calc, char operation, int result) {
    if (calc->history_index >= 10) {
        return;
    }
    calc->history[calc->history_index++] = operation;
    calc->history[calc->history_index++] = result;
}

int calculator_evaluate(Calculator* calc) {
    int result = 0;
    char operator = '\0';
    for (int i = 0; i < calc->top; i++) {
        char number = calc->buffer[i];
        switch (operator) {
            case '+':
                result += number - '0';
                break;
            case '-':
                result -= number - '0';
                break;
            case '*':
                result *= number - '0';
                break;
            case '/':
                result /= number - '0';
                break;
            default:
                operator = number;
                break;
        }
    }
    calculator_history_add(calc, operator, result);
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