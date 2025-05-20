//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double operand;
    double result;
    char operator;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_position;
    int history_position;
} Calculator;

Calculator* calculator_init(void) {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->operand = 0.0;
    calculator->result = 0.0;
    calculator->operator = '\0';
    calculator->buffer_position = 0;
    calculator->history_position = -1;
    return calculator;
}

void calculator_free(Calculator* calculator) {
    free(calculator);
}

void calculator_clear(Calculator* calculator) {
    calculator->operand = 0.0;
    calculator->result = 0.0;
    calculator->buffer_position = 0;
    calculator->history_position = -1;
}

void calculator_append_number(Calculator* calculator, double number) {
    char number_str[16];
    int i = 0;

    sprintf(number_str, "%f", number);

    for (i = 0; number_str[i] != '\0'; i++) {
        calculator->buffer[calculator->buffer_position++] = number_str[i];
    }

    calculator->buffer[calculator->buffer_position] = '\0';
}

void calculator_append_operator(Calculator* calculator, char operator) {
    calculator->operator = operator;
}

double calculator_calculate(Calculator* calculator) {
    double result = 0.0;

    switch (calculator->operator) {
        case '+':
            result = calculator->operand + calculator->result;
            break;
        case '-':
            result = calculator->operand - calculator->result;
            break;
        case '*':
            result = calculator->operand * calculator->result;
            break;
        case '/':
            if (calculator->result == 0.0) {
                return 0.0;
            }
            result = calculator->operand / calculator->result;
            break;
        default:
            return 0.0;
    }

    calculator->result = result;
    return result;
}

int main() {
    Calculator* calculator = calculator_init();

    // Perform calculator operations here

    calculator_free(calculator);

    return 0;
}