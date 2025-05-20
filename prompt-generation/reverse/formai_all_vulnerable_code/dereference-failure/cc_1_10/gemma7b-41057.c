//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double number;
    char operator;
    struct Calculator* next;
} Calculator;

void calculator_add(Calculator* head, double number, char operator) {
    Calculator* new_calculator = malloc(sizeof(Calculator));
    new_calculator->number = number;
    new_calculator->operator = operator;
    new_calculator->next = NULL;

    if (head == NULL) {
        head = new_calculator;
    } else {
        head->next = new_calculator;
    }
}

double calculator_evaluate(Calculator* head) {
    double result = 0;
    double number;
    char operator;

    while (head) {
        number = head->number;
        operator = head->operator;

        switch (operator) {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                if (number == 0) {
                    return -1;
                }
                result /= number;
                break;
            default:
                return -1;
        }

        head = head->next;
    }

    return result;
}

int main() {
    Calculator* head = NULL;

    calculator_add(head, 5, '+');
    calculator_add(head, 10, '-');
    calculator_add(head, 2, '*');
    calculator_add(head, 3, '/');

    double result = calculator_evaluate(head);

    if (result != -1) {
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Error: Invalid expression.\n");
    }

    return 0;
}