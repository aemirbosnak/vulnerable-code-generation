//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INT 2147483647
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum;
    char op;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    op = '+';

    // Read input from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /): ");
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
    }

    // Check for overflow
    if (sum > MAX_INT || sum < -MAX_INT) {
        printf("Overflow! The result is %d\n", sum);
    } else {
        printf("The result is %d\n", sum);
    }

    // Add some magic
    if (sum == MAGIC_NUMBER) {
        printf("Congratulations! You found the secret number!\n");
    }

    return 0;
}