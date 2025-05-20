//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A simple calculator program that takes in two numbers and performs basic arithmetic operations
int main() {
    // Declare variables to store user input and perform calculations
    int num1, num2, sum, diff, mult, div;
    char op;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operator from the user (add, subtract, multiply, or divide)
    printf("Enter the operator (+, -, *, or /): ");
    scanf(" %c", &op);

    // Perform the calculation based on the operator
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        mult = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // Print the result
    printf("Result: %d\n", sum);

    // Ask the user if they want to try again (y/n)
    printf("Do you want to try again? (y/n): ");
    char again;
    scanf(" %c", &again);

    // If the user wants to try again, repeat the process
    if (again == 'y') {
        main();
    } else {
        // If the user does not want to try again, print a goodbye message
        printf("Goodbye! \n");
    }

    return 0;
}