//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_NUMBER 1000

// Function to get user input
int get_user_input(int *num) {
    printf("Enter a number: ");
    scanf("%d", num);
    return 0;
}

// Function to perform arithmetic operations
int perform_ops(int num1, int num2, char op) {
    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            result = -1;
            break;
    }

    return result;
}

int main() {
    int num1, num2, op;

    // Ask user for first number
    get_user_input(&num1);

    // Ask user for second number
    get_user_input(&num2);

    // Ask user for operation
    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &op);

    // Perform arithmetic operation
    int result = perform_ops(num1, num2, op);

    // Print result
    printf("Result: %d\n", result);

    return 0;
}