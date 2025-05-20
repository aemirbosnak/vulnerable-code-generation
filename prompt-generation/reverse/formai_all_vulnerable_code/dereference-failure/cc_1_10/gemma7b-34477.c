//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int historySize;
    char **history;
} Calculator;

Calculator *createCalculator() {
    Calculator *calculator = malloc(sizeof(Calculator));
    calculator->position = 0;
    calculator->historySize = 0;
    calculator->history = NULL;
    return calculator;
}

void addHistory(Calculator *calculator, char *expression) {
    calculator->historySize++;
    calculator->history = realloc(calculator->history, calculator->historySize * sizeof(char *));
    calculator->history[calculator->historySize - 1] = strdup(expression);
}

void clearHistory(Calculator *calculator) {
    free(calculator->history);
    calculator->historySize = 0;
    calculator->history = NULL;
}

void displayHistory(Calculator *calculator) {
    for (int i = 0; i < calculator->historySize; i++) {
        printf("%s\n", calculator->history[i]);
    }
}

int main() {
    Calculator *calculator = createCalculator();

    // Use the calculator
    calculator->buffer[0] = '5';
    calculator->buffer[1] = '3';
    calculator->buffer[2] = '+';
    calculator->buffer[3] = '2';
    calculator->buffer[4] = '=';

    addHistory(calculator, calculator->buffer);

    // Display the history
    displayHistory(calculator);

    clearHistory(calculator);

    // Display the history after clearing
    displayHistory(calculator);

    return 0;
}