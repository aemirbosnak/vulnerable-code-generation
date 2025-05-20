//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

Calculator* createCalculator() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->historyPos = 0;
    return calc;
}

void clearCalculator(Calculator* calc) {
    calc->pos = 0;
    calc->buffer[0] = '\0';
}

void addNumber(Calculator* calc, int number) {
    int len = strlen(calc->buffer);
    if (len == MAX_BUFFER_SIZE - 1) {
        return;
    }
    char numStr[11];
    sprintf(numStr, "%d", number);
    strcat(calc->buffer, numStr);
    calc->pos++;
}

void addOperator(Calculator* calc, char operator) {
    if (calc->pos > 0) {
        calc->history[calc->historyPos++] = calc->buffer[0] - '0';
    }
    calc->buffer[calc->pos++] = operator;
}

int calculate(Calculator* calc) {
    char operator = calc->buffer[calc->pos - 1];
    int num1 = calc->buffer[0] - '0';
    int num2 = calc->buffer[calc->pos] - '0';
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return -1;
    }
}

int main() {
    Calculator* calc = createCalculator();
    clearCalculator(calc);
    addNumber(calc, 10);
    addOperator(calc, '+');
    addNumber(calc, 20);
    addOperator(calc, '=');
    int result = calculate(calc);
    printf("The result is: %d\n", result);
    return 0;
}