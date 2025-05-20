//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100

int main() {
    int num1, num2, sum, diff, multi, div;
    char op;
    char input[MAX_LENGTH];

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Dynamic Error Handling Program!\n");

    // prompt user for input
    printf("Enter a math operation (+, -, *, /): ");
    fgets(input, MAX_LENGTH, stdin);

    // parse input
    if (strlen(input) > 0) {
        op = input[0];

        // handle invalid input
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("Invalid input. Please enter a valid math operation.\n");
            return 1;
        }
    } else {
        printf("No input provided. Please enter a valid math operation.\n");
        return 1;
    }

    // get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // handle invalid input
    if (num1 < MIN_VALUE || num1 > 100) {
        printf("Invalid input. Please enter a valid number between %d and 100.\n", MIN_VALUE, 100);
        return 1;
    }

    // get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // handle invalid input
    if (num2 < MIN_VALUE || num2 > 100) {
        printf("Invalid input. Please enter a valid number between %d and 100.\n", MIN_VALUE, 100);
        return 1;
    }

    // perform the math operation
    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        diff = num1 - num2;
    } else if (op == '*') {
        multi = num1 * num2;
    } else if (op == '/') {
        div = num1 / num2;
    }

    // handle division by zero
    if (num2 == 0) {
        printf("Error: division by zero. Please enter valid numbers.\n");
        return 1;
    }

    // display the result
    printf("Result: %d\n", sum);

    return 0;
}