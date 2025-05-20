//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
    int state;
} Calculator;

void initCalculator(Calculator *calc) {
    calc->pos = 0;
    calc->result = 0.0;
    calc->state = 0;
    calc->buffer[0] = '\0';
}

void addNumber(Calculator *calc, double num) {
    double fnum = floor(num);
    int i = 0;
    char *snum = (char *)malloc(sizeof(char) * 11);
    sprintf(snum, "%lf", fnum);

    if (calc->state == 0) {
        calc->buffer[calc->pos++] = snum[0];
    } else {
        calc->buffer[calc->pos++] = '.';
        calc->buffer[calc->pos++] = snum[0];
    }

    free(snum);
}

void addOperator(Calculator *calc, char op) {
    calc->buffer[calc->pos++] = op;
    calc->state = 1;
}

void calculate(Calculator *calc) {
    double num1 = atof(calc->buffer);
    double num2 = atof(calc->buffer + calc->pos - 1);
    double result = 0.0;

    switch (calc->buffer[calc->pos - 2]) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Cannot divide by zero\n");
                return;
            }
            result = num1 / num2;
            break;
    }

    calc->result = result;
    calc->state = 0;
}

int main() {
    Calculator calc;
    initCalculator(&calc);

    addNumber(&calc, 10);
    addOperator(&calc, '+');
    addNumber(&calc, 20);
    addOperator(&calc, '=');

    calculate(&calc);

    printf("The result is: %.2lf\n", calc.result);

    return 0;
}