//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double (*calculate)(double, double);
    char **buffer;
    int size;
    int top;
} Calculator;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Divide by zero is not allowed.\n");
        return -1;
    }
    return a / b;
}

void calculator_init(Calculator *calc) {
    calc->buffer = (char **)malloc(MAX_BUFFER_SIZE * sizeof(char *));
    calc->size = MAX_BUFFER_SIZE;
    calc->top = -1;
    calc->calculate = add;
}

void calculator_push(Calculator *calc, double value) {
    if (calc->top == calc->size - 1) {
        printf("Error: Buffer overflow.\n");
        return;
    }
    calc->buffer[++calc->top] = (char *)malloc(sizeof(char) * 20);
    sprintf(calc->buffer[calc->top], "%f", value);
}

double calculator_pop(Calculator *calc) {
    if (calc->top == -1) {
        printf("Error: Stack underflow.\n");
        return -1;
    }
    double value = atof(calc->buffer[calc->top]);
    free(calc->buffer[calc->top]);
    calc->top--;
    return value;
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    calculator_push(&calc, 10.0);
    calculator_push(&calc, 2.0);
    calculator_push(&calc, 3.0);
    calculator_push(&calc, 4.0);
    calculator_push(&calc, 5.0);

    double result = calculator_pop(&calc);
    double second_result = calculator_pop(&calc);

    if (result != -1 && second_result != -1) {
        printf("The result is: %f\n", result);
        printf("The second result is: %f\n", second_result);
    }

    return 0;
}