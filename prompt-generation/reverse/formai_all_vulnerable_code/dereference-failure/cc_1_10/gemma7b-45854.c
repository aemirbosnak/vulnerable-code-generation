//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->result = 0.0;
    return calculator;
}

void addToCalculator(Calculator* calculator, char character) {
    calculator->buffer[++calculator->top] = character;
}

double calculateResult(Calculator* calculator) {
    double result = 0.0;
    int i = 0;
    char* number = calculator->buffer;
    for (; number[i] != '\0'; i++) {
        double digit = number[i] - '0';
        result = result * 10.0 + digit;
    }
    calculator->result = result;
    return result;
}

int main() {
    Calculator* calculator = createCalculator();
    addToCalculator(calculator, '5');
    addToCalculator(calculator, '3');
    addToCalculator(calculator, '+');
    addToCalculator(calculator, '2');
    addToCalculator(calculator, '4');
    addToCalculator(calculator, '=');

    calculateResult(calculator);

    printf("The result is: %.2lf", calculator->result);

    free(calculator);

    return 0;
}