//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER 1

int main() {
    int number1, number2, sum, difference, product, quotient, remainder;
    char operation;

    printf("Welcome to the Arithmetic Playground!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &number1);

        printf("Enter another number: ");
        scanf("%d", &number2);

        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);

        switch (operation) {
            case '+':
                sum = number1 + number2;
                break;
            case '-':
                difference = number1 - number2;
                break;
            case '*':
                product = number1 * number2;
                break;
            case '/':
                quotient = number1 / number2;
                remainder = number1 % number2;
                break;
            default:
                printf("Invalid operation. Try again.\n");
                continue;
        }

        printf("Result: %d\n", sum);

        if (operation == '/') {
            printf("Remainder: %d\n", remainder);
        }

    } while (1);

    return 0;
}