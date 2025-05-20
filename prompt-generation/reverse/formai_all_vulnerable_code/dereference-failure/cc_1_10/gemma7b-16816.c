//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->index = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, double num) {
    calc->buffer[calc->index++] = num;
    calc->result += num;
}

void calculator_sub(Calculator* calc, double num) {
    calc->buffer[calc->index++] = num;
    calc->result -= num;
}

void calculator_mul(Calculator* calc, double num) {
    calc->buffer[calc->index++] = num;
    calc->result *= num;
}

void calculator_div(Calculator* calc, double num) {
    calc->buffer[calc->index++] = num;
    calc->result /= num;
}

void calculator_sqrt(Calculator* calc) {
    calc->buffer[calc->index++] = sqrt(calc->result);
    calc->result = sqrt(calc->result);
}

double calculator_get_result(Calculator* calc) {
    return calc->result;
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        double num = atof(input[i]) + 0.0;
        switch (input[i]) {
            case '+':
                calculator_add(calc, num);
                break;
            case '-':
                calculator_sub(calc, num);
                break;
            case '*':
                calculator_mul(calc, num);
                break;
            case '/':
                calculator_div(calc, num);
                break;
            case 'S':
                calculator_sqrt(calc);
                break;
        }
    }

    double result = calculator_get_result(calc);
    printf("The result is: %.2lf\n", result);

    free(calc);

    return 0;
}