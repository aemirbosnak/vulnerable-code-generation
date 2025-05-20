//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 255

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[10];
    int historyIndex;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->historyIndex = 0;
    return calculator;
}

void addToCalculator(Calculator* calculator, char character) {
    if (calculator->top == MAX_BUFFER_SIZE - 1) {
        return;
    }
    calculator->buffer[++calculator->top] = character;
}

void calculate(Calculator* calculator) {
    int i = calculator->top;
    int result = 0;
    char operator = '\0';

    for (; i >= 0 && operator == '\0'; i--) {
        switch (calculator->buffer[i]) {
            case '+':
                operator = '+';
                break;
            case '-':
                operator = '-';
                break;
            case '*':
                operator = '*';
                break;
            case '/':
                operator = '/';
                break;
            default:
                break;
        }

        if (operator) {
            int num2 = calculator->buffer[i - 1] - '0';
            int num1 = calculator->buffer[i] - '0';
            result = num1 * num2 + result;
        }
    }

    calculator->history[calculator->historyIndex++] = result;
    printf("%d\n", result);
}

int main() {
    Calculator* calculator = createCalculator();

    char input;
    printf("Enter an expression: ");
    scanf("%c", &input);

    addToCalculator(calculator, input);

    calculate(calculator);

    return 0;
}