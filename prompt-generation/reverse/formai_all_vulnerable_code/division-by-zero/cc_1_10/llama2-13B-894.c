//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 1

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    difference = 0;
    product = 0;
    quotient = 0;
    remainder = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, x, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        difference = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    }

    // Print the results
    printf("Result of %d %s %d: %d\n", num1, op, num2, sum);
    printf("Result of %d %s %d: %d\n", num1, op, num2, difference);
    printf("Result of %d %s %d: %d\n", num1, op, num2, product);
    printf("Result of %d %s %d: %d\n", num1, op, num2, quotient);
    printf("Result of %d %s %d: %d\n", num1, op, num2, remainder);

    return 0;
}