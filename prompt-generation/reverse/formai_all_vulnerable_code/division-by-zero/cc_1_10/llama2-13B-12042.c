//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char operator;

    // Initialize variables
    printf("Welcome to the Arithmetic Playground!\n");
    printf("Please enter two numbers and an operator (+, -, *, /, or %).\n");

    // Get the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operator
    printf("Enter the operator (+, -, *, /, or %): ");
    scanf(" %c", &operator);

    // Perform the operation
    switch (operator) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            difference = num1 - num2;
            break;
        case '*':
            product = num1 * num2;
            break;
        case '/':
            quotient = num1 / num2;
            remainder = num1 % num2;
            break;
        case '%':
            remainder = num1 % num2;
            quotient = num1 / num2;
            break;
        default:
            printf("Invalid operator! Please try again.\n");
            return 1;
    }

    // Print the results
    printf("The result of %d + %d is %d\n", num1, num2, sum);
    printf("The result of %d - %d is %d\n", num1, num2, difference);
    printf("The result of %d * %d is %d\n", num1, num2, product);
    printf("The result of %d / %d is %d with a remainder of %d\n", num1, num2, quotient, remainder);
    printf("The result of %d %d is %d\n", num1, num2, remainder);

    // Print some magic
    printf("The answer to the ultimate question of life, the universe, and everything is %d\n", MAGIC_NUMBER);

    return 0;
}