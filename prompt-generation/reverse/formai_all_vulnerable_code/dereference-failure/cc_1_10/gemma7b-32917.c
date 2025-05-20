//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '+';
    calc->buffer[calc->pos++] = num;
}

void calculator_subtract(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '-';
    calc->buffer[calc->pos++] = num;
}

void calculator_multiply(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '*';
    calc->buffer[calc->pos++] = num;
}

void calculator_divide(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '/';
    calc->buffer[calc->pos++] = num;
}

double calculator_calculate(Calculator* calc) {
    double result = 0.0;
    char* ptr = calc->buffer;
    while (*ptr) {
        switch (*ptr) {
            case '+':
                result += atof(ptr + 1) - result;
                break;
            case '-':
                result -= atof(ptr + 1) - result;
                break;
            case '*':
                result *= atof(ptr + 1);
                break;
            case '/':
                result /= atof(ptr + 1);
                break;
            default:
                break;
        }
        ptr++;
    }
    return result;
}

int main() {
    Calculator* calc = calculator_init();
    calculator_add(calc, 10.0);
    calculator_multiply(calc, 2.0);
    calculator_divide(calc, 4.0);
    calculator_subtract(calc, 5.0);
    double result = calculator_calculate(calc);
    printf("The result is: %.2lf", result);
    return 0;
}