//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int state;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->state = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '+';
    calc->result += num;
}

void calculator_sub(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '-';
    calc->result -= num;
}

void calculator_mul(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '*';
    calc->result *= num;
}

void calculator_div(Calculator* calc, double num) {
    calc->buffer[calc->pos++] = '/';
    calc->result /= num;
}

void calculator_equals(Calculator* calc) {
    calc->buffer[calc->pos++] = '=';
    printf("Result: %.2lf\n", calc->result);
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression and execute the operations
    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '+':
                calculator_add(calc, atof(input+i+1));
                break;
            case '-':
                calculator_sub(calc, atof(input+i+1));
                break;
            case '*':
                calculator_mul(calc, atof(input+i+1));
                break;
            case '/':
                calculator_div(calc, atof(input+i+1));
                break;
            case '=':
                calculator_equals(calc);
                break;
        }
    }

    return 0;
}