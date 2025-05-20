//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000000
#define MIN_NUM 1

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;
    char user_input[10];

    printf("Welcome to the Arithmetic Scaling Program!\n");

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(user_input, 10, stdin);
    num1 = atoi(user_input);

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(user_input, 10, stdin);
    num2 = atoi(user_input);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    fgets(user_input, 10, stdin);
    op = user_input[0];

    // Perform the operation
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

    // Ask the user if they want to scale the result
    printf("Do you want to scale the result? (y/n): ");
    fgets(user_input, 10, stdin);
    if (user_input[0] == 'y') {
        // Scale the result by a factor
        int factor = atoi(user_input + 1);
        sum *= factor;
        printf("Scaled result: %d\n", sum);
    }

    return 0;
}