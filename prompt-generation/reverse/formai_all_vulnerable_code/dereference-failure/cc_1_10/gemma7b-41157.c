//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    double number;
    char operator;
    struct Calculator* next;
} Calculator;

void calculator_init(Calculator* calculator) {
    calculator->number = 0.0;
    calculator->operator = '\0';
    calculator->next = NULL;
}

void calculator_append(Calculator* calculator, char operator, double number) {
    Calculator* new_calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator_init(new_calculator);
    new_calculator->operator = operator;
    new_calculator->number = number;
    new_calculator->next = calculator->next;
    calculator->next = new_calculator;
}

double calculator_compute(Calculator* calculator) {
    double result = 0.0;
    switch (calculator->operator) {
        case '+':
            result = calculator->number + calculator_compute(calculator->next);
            break;
        case '-':
            result = calculator->number - calculator_compute(calculator->next);
            break;
        case '*':
            result = calculator->number * calculator_compute(calculator->next);
            break;
        case '/':
            result = calculator->number / calculator_compute(calculator->next);
            break;
        default:
            result = calculator->number;
            break;
    }
    return result;
}

int main() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator_init(calculator);

    char buffer[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char* token = strtok(buffer, " ");

    while (token) {
        calculator_append(calculator, token[0], atof(token + 1));
        token = strtok(NULL, " ");
    }

    double result = calculator_compute(calculator);

    printf("Result: %f\n", result);

    return 0;
}