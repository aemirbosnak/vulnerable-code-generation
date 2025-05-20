//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 10

struct operation {
    char op[2];  // operator (e.g. +, -, *, /)
    int a, b;    // operands
};

int main() {
    int num1, num2, result;
    char op[2];
    struct operation operations[MAX_OPERATIONS];
    int i, j;

    // initialize operations array
    for (i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].op[0] = '\0';
        operations[i].a = 0;
        operations[i].b = 0;
    }

    // prompt user for first number and operation
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op[0]);

    // perform operation
    switch (op[0]) {
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
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // prompt user for second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // display result
    printf("Result: %d\n", result);

    // loop until user enters a valid operation
    while (1) {
        // prompt user for next operation
        printf("Enter the next operation (+, -, *, /): ");
        scanf(" %c", &op[0]);

        // check if user entered a valid operation
        if (op[0] == ' ' || op[0] == '\n') {
            break;
        }

        // perform operation and display result
        switch (op[0]) {
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
                result = num1 / num2;
                break;
            default:
                printf("Invalid operation. Please try again.\n");
                continue;
        }

        // display result
        printf("Result: %d\n", result);

        // prompt user for next number
        printf("Enter the next number: ");
        scanf("%d", &num2);
    }

    return 0;
}