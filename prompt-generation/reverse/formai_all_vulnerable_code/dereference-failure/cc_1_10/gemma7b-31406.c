//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->result = 0.0;
    return calculator;
}

void calculator_push(Calculator* calculator, char character) {
    calculator->buffer[++calculator->top] = character;
}

double calculator_pop(Calculator* calculator) {
    if (calculator->top == -1) {
        return -1.0;
    }
    return calculator->buffer[calculator->top] - '0';
}

void calculator_clear(Calculator* calculator) {
    calculator->top = -1;
    calculator->result = 0.0;
}

void calculator_enter(Calculator* calculator) {
    double number = calculator_pop(calculator);
    if (number == -1.0) {
        return;
    }
    calculator->result += number;
}

void calculator_print(Calculator* calculator) {
    printf("%f", calculator->result);
}

int main() {
    Calculator* calculator = calculator_init();

    char input;
    double number;

    while (1) {
        printf("$ ");
        scanf("%c", &input);

        switch (input) {
            case 'c':
                calculator_clear(calculator);
                break;
            case 'e':
                calculator_enter(calculator);
                break;
            case '+':
                calculator_push(calculator, '+');
                break;
            case '-':
                calculator_push(calculator, '-');
                break;
            case '*':
                calculator_push(calculator, '*');
                break;
            case '/':
                calculator_push(calculator, '/');
                break;
            case '=':
                calculator_print(calculator);
                break;
            default:
                calculator_push(calculator, input);
                break;
        }

        if (input == '=') {
            break;
        }
    }

    free(calculator);
    return 0;
}