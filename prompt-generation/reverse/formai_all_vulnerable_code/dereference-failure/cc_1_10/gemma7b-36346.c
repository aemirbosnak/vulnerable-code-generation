//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->result = 0.0;
    return calculator;
}

void calculator_push(Calculator* calculator, char number) {
    if (calculator->top == MAX_BUFFER_SIZE - 1) {
        printf("Error: Buffer overflow\n");
        return;
    }
    calculator->buffer[++calculator->top] = number;
}

double calculator_pop(Calculator* calculator) {
    if (calculator->top == -1) {
        printf("Error: Empty buffer\n");
        return -1.0;
    }
    return (double)calculator->buffer[calculator->top--];
}

double calculator_evaluate(Calculator* calculator) {
    double operand1 = calculator_pop(calculator);
    double operand2 = calculator_pop(calculator);
    char operator = calculator_pop(calculator);

    switch (operator) {
        case '+':
            calculator->result = operand1 + operand2;
            break;
        case '-':
            calculator->result = operand1 - operand2;
            break;
        case '*':
            calculator->result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                printf("Error: Divide by zero\n");
                return -1.0;
            }
            calculator->result = operand1 / operand2;
            break;
        default:
            printf("Error: Invalid operator\n");
            return -1.0;
    }

    return calculator->result;
}

int main() {
    Calculator* calculator = calculator_init();

    // Example usage
    calculator_push(calculator, '5');
    calculator_push(calculator, '2');
    calculator_push(calculator, '+');
    calculator_push(calculator, '3');
    calculator_push(calculator, '-');
    calculator_push(calculator, '4');
    calculator_push(calculator, '*');
    calculator_push(calculator, '6');
    calculator_push(calculator, '/');

    calculator_evaluate(calculator);

    printf("The result is: %.2lf\n", calculator->result);

    free(calculator);

    return 0;
}