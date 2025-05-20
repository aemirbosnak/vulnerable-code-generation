//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the arithmetic wonderland! \n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask the user for the operation
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        sum = num1 / num2;
    } else {
        sum = -1;
    }

    // Print the result
    printf("The result is: %d\n", sum);

    // Wait for the user to press a key
    getchar();

    // Print a magic message
    printf("Magic happens when you least expect it...\n");

    // Print the magic number
    printf("The magic number is: %d\n", MAGIC_NUMBER);

    return 0;
}