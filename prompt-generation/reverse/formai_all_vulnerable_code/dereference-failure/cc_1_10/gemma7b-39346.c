//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pointer;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pointer = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->pointer++] = num;
    calc->result += num;
}

void calculator_subtract(Calculator* calc, double num) {
    calc->buffer[calc->pointer++] = num;
    calc->result -= num;
}

void calculator_multiply(Calculator* calc, double num) {
    calc->buffer[calc->pointer++] = num;
    calc->result *= num;
}

void calculator_divide(Calculator* calc, double num) {
    if (num == 0) {
        printf("Error: Divide by zero is not allowed.\n");
        return;
    }
    calc->buffer[calc->pointer++] = num;
    calc->result /= num;
}

void calculator_sqrt(Calculator* calc, double num) {
    calc->buffer[calc->pointer++] = num;
    calc->result = sqrt(num);
}

double calculator_get_result(Calculator* calc) {
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();
    char command;
    double num;

    printf("Enter a command (add, subtract, multiply, divide, sqrt): ");
    scanf(" %c", &command);

    switch (command) {
        case 'a':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_add(calc, num);
            break;
        case 's':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_subtract(calc, num);
            break;
        case 'm':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_multiply(calc, num);
            break;
        case 'd':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_divide(calc, num);
            break;
        case 'sqrt':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_sqrt(calc, num);
            break;
        default:
            printf("Invalid command.\n");
    }

    printf("The result is: %.2lf\n", calculator_get_result(calc));

    return 0;
}