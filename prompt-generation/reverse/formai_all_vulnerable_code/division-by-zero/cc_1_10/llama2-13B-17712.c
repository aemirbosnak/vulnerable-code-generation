//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 5

// Function to print a thoughtful message
void print_message(const char *message) {
    printf("%s\n", message);
}

// Function to perform arithmetic operations
void perform_arithmetic_operations(int num1, int num2, char operation) {
    int result;

    switch (operation) {
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
            print_message("Invalid operation!");
            return;
    }

    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, operation;

    // Ask user for first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Ask user for second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Ask user for operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operations
    perform_arithmetic_operations(num1, num2, operation);

    return 0;
}