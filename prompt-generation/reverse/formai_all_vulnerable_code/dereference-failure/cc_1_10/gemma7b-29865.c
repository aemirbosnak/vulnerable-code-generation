//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
} calculator;

calculator* calculator_new() {
    calculator* calc = malloc(sizeof(calculator));
    calc->pos = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '+';
    calc->buffer[calc->pos++] = num;
}

void calculator_subtract(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '-';
    calc->buffer[calc->pos++] = num;
}

void calculator_multiply(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '*';
    calc->buffer[calc->pos++] = num;
}

void calculator_divide(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '/';
    calc->buffer[calc->pos++] = num;
}

double calculator_calculate(calculator* calc) {
    double result = 0.0;
    int i = 0;
    for (i = 0; calc->buffer[i] != '\0'; i++) {
        switch (calc->buffer[i]) {
            case '+':
                result += calc->buffer[i+1] - '0';
                break;
            case '-':
                result -= calc->buffer[i+1] - '0';
                break;
            case '*':
                result *= calc->buffer[i+1] - '0';
                break;
            case '/':
                result /= calc->buffer[i+1] - '0';
                break;
        }
    }
    return result;
}

int main() {
    calculator* calc = calculator_new();
    calculator_add(calc, 10.0);
    calculator_multiply(calc, 2.0);
    calculator_subtract(calc, 5.0);
    calculator_divide(calc, 3.0);
    double result = calculator_calculate(calc);
    printf("The result is: %.2lf", result);
    return 0;
}