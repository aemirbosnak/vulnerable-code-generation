//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int hist_pos;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->hist_pos = 0;
    return calc;
}

void calculator_add(Calculator* calc, int num) {
    char num_str[11];
    sprintf(num_str, "%d", num);
    calc->buffer[calc->pos++] = num_str[0];
    calc->buffer[calc->pos] = '\0';
}

void calculator_clear(Calculator* calc) {
    calc->pos = 0;
    calc->buffer[0] = '\0';
}

void calculator_history(Calculator* calc) {
    int i;
    for (i = 0; i < calc->hist_pos; i++) {
        printf("%s ", calc->history[i]);
    }
    printf("\n");
}

int main() {
    Calculator* calc = calculator_init();

    // Perform calculations
    calculator_add(calc, 5);
    calculator_add(calc, 10);
    calculator_add(calc, 2);
    calculator_add(calc, 3);

    // Display history
    calculator_history(calc);

    // Clear calculator
    calculator_clear(calc);

    // Perform further calculations
    calculator_add(calc, 8);
    calculator_add(calc, 9);

    // Display history after clearing
    calculator_history(calc);

    return 0;
}