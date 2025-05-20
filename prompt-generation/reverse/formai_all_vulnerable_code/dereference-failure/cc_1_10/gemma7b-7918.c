//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char **buffer;
    int top;
    int size;
} Calculator;

Calculator *createCalculator(int size) {
    Calculator *calc = malloc(sizeof(Calculator));
    calc->buffer = malloc(size * sizeof(char *));
    calc->top = -1;
    calc->size = size;

    return calc;
}

void addToCalculator(Calculator *calc, char *number) {
    calc->buffer[++calc->top] = number;
}

char *calculate(Calculator *calc) {
    char *result = malloc(MAX_BUFFER_SIZE);
    int i = 0;

    for (i = 0; i <= calc->top; i++) {
        strcat(result, calc->buffer[i]);
        if (i < calc->top) {
            strcat(result, "+");
        }
    }

    return result;
}

int main() {
    Calculator *calc = createCalculator(10);
    addToCalculator(calc, "5");
    addToCalculator(calc, "2");
    addToCalculator(calc, "3");
    addToCalculator(calc, "4");
    addToCalculator(calc, "6");
    addToCalculator(calc, "+");
    addToCalculator(calc, "8");
    addToCalculator(calc, "9");
    addToCalculator(calc, "=");

    char *result = calculate(calc);
    printf("%s", result);

    return 0;
}