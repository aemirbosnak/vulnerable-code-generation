//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[MAX_BUFFER_SIZE];
    int historyIndex;
} calculator;

calculator* createCalculator() {
    calculator* calc = (calculator*)malloc(sizeof(calculator));
    calc->top = -1;
    calc->historyIndex = 0;
    return calc;
}

void addNumber(calculator* calc, int number) {
    calc->buffer[++calc->top] = number;
}

void addOperator(calculator* calc, char operator) {
    calc->buffer[++calc->top] = operator;
}

int evaluateExpression(calculator* calc) {
    int result = 0;
    int i = 0;
    char operator = '\0';

    for (i = 0; i <= calc->top && operator != '\0'; i++) {
        operator = calc->buffer[i];

        switch (operator) {
            case '+':
                result += calc->buffer[i + 1] - '0';
                break;
            case '-':
                result -= calc->buffer[i + 1] - '0';
                break;
            case '*':
                result *= calc->buffer[i + 1] - '0';
                break;
            case '/':
                result /= calc->buffer[i + 1] - '0';
                break;
            default:
                break;
        }
    }

    return result;
}

int main() {
    calculator* calc = createCalculator();
    addNumber(calc, 10);
    addOperator(calc, '+');
    addNumber(calc, 20);
    addOperator(calc, '*');
    addNumber(calc, 30);
    addOperator(calc, '/');
    addNumber(calc, 40);
    addOperator(calc, '=');

    int result = evaluateExpression(calc);
    printf("The result is: %d\n", result);

    return 0;
}