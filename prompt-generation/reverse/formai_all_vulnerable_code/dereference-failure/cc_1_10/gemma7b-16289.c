//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->value = 0.0;
    calculator->operator = '\0';
    calculator->next = NULL;
    return calculator;
}

void addCalculator(Calculator* calculator, double value, char operator) {
    Calculator* newCalculator = createCalculator();
    newCalculator->value = value;
    newCalculator->operator = operator;
    newCalculator->next = calculator;
    calculator = newCalculator;
}

double calculate(Calculator* calculator) {
    double result = calculator->value;
    while (calculator->next) {
        switch (calculator->operator) {
            case '+':
                result += calculator->next->value;
                break;
            case '-':
                result -= calculator->next->value;
                break;
            case '*':
                result *= calculator->next->value;
                break;
            case '/':
                if (calculator->next->value == 0) {
                    return -1;
                }
                result /= calculator->next->value;
                break;
            default:
                return -1;
        }
        calculator = calculator->next;
    }
    return result;
}

int main() {
    Calculator* calculator = createCalculator();
    addCalculator(calculator, 10.0, '+');
    addCalculator(calculator, 20.0, '-');
    addCalculator(calculator, 30.0, '*');
    addCalculator(calculator, 40.0, '/');

    double result = calculate(calculator);
    if (result != -1) {
        printf("The result is: %f\n", result);
    } else {
        printf("Error: Invalid calculation.\n");
    }

    return 0;
}