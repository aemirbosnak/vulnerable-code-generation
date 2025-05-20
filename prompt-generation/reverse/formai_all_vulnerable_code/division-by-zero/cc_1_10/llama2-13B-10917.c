//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MIN_VALUE 0
#define MAX_VALUE 1000

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;
    char str[MAX_LENGTH];

    // Initialize variables
    num1 = MIN_VALUE;
    num2 = MIN_VALUE;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

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
    printf("Diff: %d\n", diff);
    printf("Mult: %d\n", mult);
    printf("Div: %d\n", div);

    // Free memory
    free(str);

    return 0;
}