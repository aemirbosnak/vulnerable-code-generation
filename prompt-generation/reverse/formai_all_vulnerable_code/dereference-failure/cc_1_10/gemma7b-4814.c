//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    }
    return result;
}

int main() {
    char input[MAX_BUFFER_SIZE];
    double number;
    char operator;
    Calculator* calculator = createCalculator();

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            number = atoi(&input[i]);
            addCalculator(calculator, number, '\0');
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            operator = input[i];
            addCalculator(calculator, calculator->value, operator);
        }
    }

    // Calculate the result
    double result = calculate(calculator);

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}