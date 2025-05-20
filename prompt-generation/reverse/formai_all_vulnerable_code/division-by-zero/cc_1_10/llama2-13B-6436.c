//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the Retro Math Machine!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (add, subtract, multiply, or divide)
    printf("Enter the operation (+, -, *, or /): ");
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
        printf("Invalid operation! Please try again.\n");
        return;
    }

    // Print the result
    printf("The result of %d %c %d is %d\n", num1, op, num2, sum);

    // Print some retro-style graphics
    printf("_______\n");
    printf("|      |      |      |\n");
    printf("|  $$  |  $$  |  $$  |\n");
    printf("|_____|_____|_____|");

    // Wait for the user to press a key
    printf("Press any key to continue...");
    getch();
}