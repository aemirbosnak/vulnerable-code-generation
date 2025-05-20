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
    calculator->value = value;
    calculator->operator = operator;
    calculator->next = createCalculator();
}

double calculateExpression(Calculator* calculator) {
    double result = calculator->value;
    switch (calculator->operator) {
        case '+':
            result += calculateExpression(calculator->next);
            break;
        case '-':
            result -= calculateExpression(calculator->next);
            break;
        case '*':
            result *= calculateExpression(calculator->next);
            break;
        case '/':
            result /= calculateExpression(calculator->next);
            break;
        default:
            break;
    }
    return result;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    Calculator* calculator = createCalculator();
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression and add calculators to the linked list
    char* token = strtok(buffer, " ");
    while (token) {
        double value = atof(token);
        addCalculator(calculator, value, token[0]);
        token = strtok(NULL, " ");
    }

    // Calculate the result of the expression
    double result = calculateExpression(calculator);

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}