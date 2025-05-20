//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
    char operator;
} calculator;

calculator* createCalculator() {
    calculator* calc = (calculator*)malloc(sizeof(calculator));
    calc->pos = 0;
    calc->result = 0.0;
    calc->operator = '\0';
    return calc;
}

void addNumber(calculator* calc, double num) {
    char number[20];
    sprintf(number, "%f", num);
    strcat(calc->buffer, number);
    calc->pos++;
}

void setOperator(calculator* calc, char operator) {
    calc->operator = operator;
}

double calculate(calculator* calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = atof(calc->buffer) + calc->result;
            break;
        case '-':
            result = atof(calc->buffer) - calc->result;
            break;
        case '*':
            result = atof(calc->buffer) * calc->result;
            break;
        case '/':
            result = atof(calc->buffer) / calc->result;
            break;
        default:
            break;
    }
    calc->result = result;
    return result;
}

int main() {
    calculator* calc = createCalculator();
    addNumber(calc, 10.0);
    setOperator(calc, '+');
    addNumber(calc, 20.0);
    setOperator(calc, '=');
    double result = calculate(calc);
    printf("The result is: %f\n", result);
    return 0;
}