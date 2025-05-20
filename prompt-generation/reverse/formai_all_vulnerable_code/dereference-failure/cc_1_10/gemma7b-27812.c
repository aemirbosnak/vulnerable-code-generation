//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    int history[100];
    int history_index;
} Calculator;

void calculate(Calculator *calc) {
    char operator = calc->buffer[calc->top - 1];
    int num1 = atoi(&calc->buffer[calc->top - 2]);
    int num2 = atoi(&calc->buffer[calc->top - 3]);

    switch (operator) {
        case '+':
            calc->history[calc->history_index++] = num1 + num2;
            break;
        case '-':
            calc->history[calc->history_index++] = num1 - num2;
            break;
        case '*':
            calc->history[calc->history_index++] = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
                return;
            }
            calc->history[calc->history_index++] = num1 / num2;
            break;
    }

    calc->top = 0;
}

int main() {
    Calculator calc;
    calc.top = 0;
    calc.history_index = 0;

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    char *token = strtok(input, " ");

    while (token) {
        if (token[0] >= '0' && token[0] <= '9') {
            calc.buffer[calc.top++] = token[0];
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            calculate(&calc);
            calc.buffer[calc.top++] = token[0];
        }
        token = strtok(NULL, " ");
    }

    calculate(&calc);

    printf("History:\n");
    for (int i = 0; i < calc.history_index; i++) {
        printf("%d ", calc.history[i]);
    }

    return 0;
}