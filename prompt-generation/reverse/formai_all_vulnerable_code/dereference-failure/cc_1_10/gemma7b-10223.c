//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->pos = 0;
    calculator->result = 0.0;
    return calculator;
}

void addNumber(Calculator* calculator, double number) {
    sprintf(calculator->buffer + calculator->pos, "%f", number);
    calculator->pos += strlen(calculator->buffer) + 1;
}

void setOperator(Calculator* calculator, char operator) {
    calculator->buffer[calculator->pos++] = operator;
}

double calculate(Calculator* calculator) {
    double result = 0.0;
    char* token = strtok(calculator->buffer, " ");
    while (token) {
        double number = atof(token);
        switch (calculator->buffer[calculator->pos - 1]) {
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
        token = strtok(NULL, " ");
    }
    calculator->result = result;
    return result;
}

int main() {
    Calculator* calculator = createCalculator();
    addNumber(calculator, 10.0);
    setOperator(calculator, '+');
    addNumber(calculator, 20.0);
    setOperator(calculator, '*');
    addNumber(calculator, 30.0);
    setOperator(calculator, '/');
    addNumber(calculator, 40.0);
    setOperator(calculator, '=');
    double result = calculate(calculator);
    printf("The result is: %f", result);
    return 0;
}