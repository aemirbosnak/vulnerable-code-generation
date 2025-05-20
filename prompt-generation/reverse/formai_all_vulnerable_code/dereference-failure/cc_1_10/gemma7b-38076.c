//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->value = 0.0;
    calculator->operator = '\0';
    calculator->next = NULL;
    return calculator;
}

void addCalculator(Calculator* head, double value, char operator) {
    Calculator* newCalculator = createCalculator();
    newCalculator->value = value;
    newCalculator->operator = operator;

    if (head == NULL) {
        head = newCalculator;
    } else {
        head->next = newCalculator;
    }
    head = newCalculator;
}

double calculate(Calculator* head) {
    double result = head->value;
    while (head->next) {
        switch (head->operator) {
            case '+':
                result += head->next->value;
                break;
            case '-':
                result -= head->next->value;
                break;
            case '*':
                result *= head->next->value;
                break;
            case '/':
                result /= head->next->value;
                break;
            default:
                break;
        }
        head = head->next;
    }
    return result;
}

int main() {
    Calculator* head = createCalculator();
    addCalculator(head, 10.0, '+');
    addCalculator(head, 5.0, '-');
    addCalculator(head, 2.0, '*');
    addCalculator(head, 3.0, '/');

    double result = calculate(head);
    printf("The result is: %f", result);

    return 0;
}