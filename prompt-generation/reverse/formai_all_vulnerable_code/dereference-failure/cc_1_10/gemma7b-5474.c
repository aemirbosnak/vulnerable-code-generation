//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double number;
    char operator;
    struct Calculator* next;
} Calculator;

void calculate(Calculator* calculator) {
    switch (calculator->operator) {
        case '+':
            calculator->number = calculator->next->number + calculator->number;
            break;
        case '-':
            calculator->number = calculator->next->number - calculator->number;
            break;
        case '*':
            calculator->number = calculator->next->number * calculator->number;
            break;
        case '/':
            if (calculator->next->number == 0) {
                printf("Error: Divide by zero is not allowed.\n");
                return;
            }
            calculator->number = calculator->next->number / calculator->number;
            break;
        default:
            printf("Error: Invalid operator.\n");
            return;
    }
    calculator->next = NULL;
}

int main() {
    Calculator* head = NULL;

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    // Parse the input expression and create a linked list of calculators
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            Calculator* newCalculator = (Calculator*)malloc(sizeof(Calculator));
            newCalculator->number = 0;
            newCalculator->operator = input[i];
            newCalculator->next = head;
            head = newCalculator;
        } else if (input[i] >= '0' && input[i] <= '9') {
            double number = input[i] - '0';
            while (input[i + 1] >= '0' && input[i + 1] <= '9') {
                number = number * 10 + input[i + 1] - '0';
                i++;
            }
            Calculator* newCalculator = (Calculator*)malloc(sizeof(Calculator));
            newCalculator->number = number;
            newCalculator->operator = '=';
            newCalculator->next = head;
            head = newCalculator;
        }
    }

    // Calculate the result of the expression
    calculate(head);

    // Print the result
    printf("The result is: %.2lf\n", head->number);

    return 0;
}