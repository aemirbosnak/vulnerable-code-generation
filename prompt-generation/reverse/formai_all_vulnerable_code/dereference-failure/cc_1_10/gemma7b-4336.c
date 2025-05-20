//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    char operator;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->top = -1;
    calc->operator = '\0';
    calc->result = 0.0;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->top] = number;
}

double calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        return -1.0;
    }
    return (double)calc->buffer[calc->top--];
}

void calculator_set_operator(Calculator* calc, char operator) {
    calc->operator = operator;
}

double calculator_calculate(Calculator* calc) {
    switch (calc->operator) {
        case '+':
            calc->result = calculator_pop(calc) + calculator_pop(calc);
            break;
        case '-':
            calc->result = calculator_pop(calc) - calculator_pop(calc);
            break;
        case '*':
            calc->result = calculator_pop(calc) * calculator_pop(calc);
            break;
        case '/':
            if (calculator_pop(calc) == 0) {
                return -1.0;
            }
            calc->result = calculator_pop(calc) / calculator_pop(calc);
            break;
        default:
            return -1.0;
    }
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression and operate on the calculator
    for (int i = 0; input[i] != '\0'; i++) {
        char number = input[i];
        switch (number) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                calculator_push(calc, number);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                calculator_set_operator(calc, number);
                break;
        }
    }

    double result = calculator_calculate(calc);

    if (result != -1.0) {
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Error: invalid expression.\n");
    }

    free(calc);

    return 0;
}