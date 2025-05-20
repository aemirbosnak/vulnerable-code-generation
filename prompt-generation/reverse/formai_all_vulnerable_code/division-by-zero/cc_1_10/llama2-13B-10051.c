//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 100000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, difference, quotient, remainder;
    char operation;

    printf("Welcome to the Arithmetic Wonderland!\n");

    do {
        printf("Select an operation (+, -, *, /, %): ");
        scanf(" %c", &operation);

        if (operation == '+') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, sum);
        } else if (operation == '-') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            difference = num1 - num2;
            printf("The difference of %d and %d is %d.\n", num1, num2, difference);
        } else if (operation == '*') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            product = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, product);
        } else if (operation == '/') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            quotient = num1 / num2;
            remainder = num1 % num2;
            printf("The quotient of %d and %d is %d, with a remainder of %d.\n", num1, num2, quotient, remainder);
        } else if (operation == '%') {
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            remainder = num1 % num2;
            quotient = num1 / num2;
            printf("The remainder of %d and %d is %d, with a quotient of %d.\n", num1, num2, remainder, quotient);
        }
    } while (1);

    return 0;
}