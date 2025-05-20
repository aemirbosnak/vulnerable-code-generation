//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    double result;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->index = 0;
    calculator->result = 0.0;
    return calculator;
}

void addToBuffer(Calculator* calculator, char character) {
    if (calculator->index >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calculator->buffer[calculator->index++] = character;
}

double calculateExpression(Calculator* calculator) {
    double result = 0.0;
    char operator = '\0';
    for (int i = 0; i < calculator->index; i++) {
        char character = calculator->buffer[i];
        if (character >= 'a' && character <= 'z') {
            operator = character;
        } else if (character >= '0' && character <= '9') {
            double number = character - '0';
            switch (operator) {
                case '+':
                    result += number;
                    break;
                case '-':
                    result -= number;
                    break;
                case '*':
                    result *= number;
                    break;
                case '/':
                    result /= number;
                    break;
                default:
                    break;
            }
        }
    }
    calculator->result = result;
    return result;
}

int main() {
    Calculator* calculator = createCalculator();
    addToBuffer(calculator, '5');
    addToBuffer(calculator, '2');
    addToBuffer(calculator, '+');
    addToBuffer(calculator, '3');
    addToBuffer(calculator, '=');

    double result = calculateExpression(calculator);
    printf("The result is: %.2lf\n", result);

    free(calculator);
    return 0;
}