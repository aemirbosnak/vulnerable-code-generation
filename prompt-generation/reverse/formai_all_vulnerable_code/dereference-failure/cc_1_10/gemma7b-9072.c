//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int history[10];
    int historyIndex;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->position = 0;
    calc->historyIndex = 0;

    return calc;
}

void calculator_add(Calculator* calc, char number) {
    calc->buffer[calc->position++] = number;
}

void calculator_clear(Calculator* calc) {
    calc->position = 0;
}

void calculator_history(Calculator* calc) {
    for (int i = 0; i < calc->historyIndex; i++) {
        printf("%c ", calc->history[i]);
    }
}

int main() {
    Calculator* calc = calculator_init();

    // Calculate 10 + 20 = 30
    calculator_add(calc, '1');
    calculator_add(calc, '0');
    calculator_add(calc, '+');
    calculator_add(calc, '2');
    calculator_add(calc, '0');
    calculator_add(calc, '=');

    // Calculate 30 - 10 = 20
    calculator_add(calc, '3');
    calculator_add(calc, '0');
    calculator_add(calc, '-');
    calculator_add(calc, '1');
    calculator_add(calc, '0');
    calculator_add(calc, '=');

    // Clear the calculator
    calculator_clear(calc);

    // Calculate 5 * 5 = 25
    calculator_add(calc, '5');
    calculator_add(calc, '*');
    calculator_add(calc, '5');
    calculator_add(calc, '=');

    // Display the history
    calculator_history(calc);

    free(calc);

    return 0;
}