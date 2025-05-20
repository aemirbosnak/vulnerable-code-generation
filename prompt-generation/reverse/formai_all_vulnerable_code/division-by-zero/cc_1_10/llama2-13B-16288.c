//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char operation;

    printf("Welcome to the Arithmetic Playground!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);

        if (operation == '+') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
        } else if (operation == '-') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 - num2;
        } else if (operation == '*') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 * num2;
        } else if (operation == '/') {
            printf("Enter another number: ");
            scanf("%d", &num2);
            sum = num1 / num2;
        } else {
            printf("Invalid operation. Try again.\n");
            continue;
        }

        printf("Result: %d\n", sum);

        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &operation);
    } while (operation == 'y' || operation == 'Y');

    return 0;
}