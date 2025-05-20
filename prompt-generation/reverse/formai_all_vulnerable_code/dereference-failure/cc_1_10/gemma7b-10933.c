//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    char operator;
    double result;
} Calculator;

void calculate(Calculator *calc) {
    switch (calc->operator) {
        case '+':
            calc->result = atof(calc->buffer) + calc->result;
            break;
        case '-':
            calc->result = atof(calc->buffer) - calc->result;
            break;
        case '*':
            calc->result = atof(calc->buffer) * calc->result;
            break;
        case '/':
            if (calc->result == 0) {
                printf("Cannot divide by zero\n");
            } else {
                calc->result = atof(calc->buffer) / calc->result;
            }
            break;
        default:
            printf("Invalid operator\n");
    }
}

int main() {
    Calculator *calc = malloc(sizeof(Calculator));
    calc->index = 0;
    calc->operator = '\0';
    calc->result = 0.0;

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");

    // Asynchronous input
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Process the input
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if the character is an operator
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            calc->operator = input[i];
            calculate(calc);
            printf("%f\n", calc->result);
        } else {
            calc->buffer[calc->index++] = input[i];
        }
    }

    free(calc);

    return 0;
}