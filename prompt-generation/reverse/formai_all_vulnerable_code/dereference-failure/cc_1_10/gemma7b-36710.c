//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    float result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->result = 0.0f;
    return calc;
}

void calculator_add(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result += num;
}

void calculator_subtract(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result -= num;
}

void calculator_multiply(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result *= num;
}

void calculator_divide(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result /= num;
}

void calculator_equal(Calculator* calc) {
    calc->buffer[calc->pos] = '\0';
    calc->result = (float)atof(calc->buffer);
}

int main() {
    Calculator* calc = calculator_init();

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Parse the input expression and perform calculations
    char* token = strtok(input, " ");
    while (token) {
        float num = (float)atof(token);
        switch (*token) {
            case '+':
                calculator_add(calc, num);
                break;
            case '-':
                calculator_subtract(calc, num);
                break;
            case '*':
                calculator_multiply(calc, num);
                break;
            case '/':
                calculator_divide(calc, num);
                break;
            case '=':
                calculator_equal(calc);
                break;
            default:
                printf("Error: Invalid operator.\n");
                return 1;
        }
        token = strtok(NULL, " ");
    }

    // Print the result
    printf("Result: %.2f\n", calc->result);

    return 0;
}