//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char **buffer;
    int size;
    int top;
    char operator;
} Calculator;

void calculator_init(Calculator *calc) {
    calc->buffer = NULL;
    calc->size = 0;
    calc->top = -1;
    calc->operator = '\0';
}

void calculator_push(Calculator *calc, char value) {
    if (calc->top == calc->size - 1) {
        calc->buffer = realloc(calc->buffer, (calc->size + 1) * sizeof(char));
        calc->size++;
    }
    calc->buffer[++calc->top] = value;
}

char calculator_pop(Calculator *calc) {
    if (calc->top == -1) {
        return '\0';
    }
    return calc->buffer[calc->top--];
}

void calculator_operator(Calculator *calc, char operator) {
    calc->operator = operator;
}

double calculator_result(Calculator *calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = calculator_pop(calc) + calculator_pop(calc);
            break;
        case '-':
            result = calculator_pop(calc) - calculator_pop(calc);
            break;
        case '*':
            result = calculator_pop(calc) * calculator_pop(calc);
            break;
        case '/':
            result = calculator_pop(calc) / calculator_pop(calc);
            break;
        default:
            break;
    }
    return result;
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    char *token = strtok(input, " ");
    while (token) {
        if (isdigit(token[0])) {
            calculator_push(&calc, token[0]);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            calculator_operator(&calc, token[0]);
        }
        token = strtok(NULL, " ");
    }

    double result = calculator_result(&calc);
    if (result != 0.0) {
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Invalid expression.\n");
    }

    return 0;
}