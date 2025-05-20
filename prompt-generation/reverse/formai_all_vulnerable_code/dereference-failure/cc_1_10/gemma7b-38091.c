//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

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
    switch (calculator->operator) {
        case '+':
            result += calculate(calculator->next);
            break;
        case '-':
            result -= calculate(calculator->next);
            break;
        case '*':
            result *= calculate(calculator->next);
            break;
        case '/':
            result /= calculate(calculator->next);
            break;
        default:
            break;
    }
    return result;
}

int main() {
    Calculator* calculator = createCalculator();
    addCalculator(calculator, 10.0, '+');
    addCalculator(calculator, 5.0, '*');
    addCalculator(calculator, 2.0, '-');
    addCalculator(calculator, 3.0, '/');

    double result = calculate(calculator);
    printf("The result is: %.2lf\n", result);

    return 0;
}