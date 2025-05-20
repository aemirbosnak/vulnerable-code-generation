//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OPERATIONS 4

// Function to handle errors and print cryptic messages
void handle_error(const char* message) {
    printf("🤔 Error: %s\n", message);
}

int main() {
    char op[MAX_INPUT_LENGTH];
    int num1, num2, result;

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(op, MAX_INPUT_LENGTH, stdin);
    num1 = atoi(op);

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(op, MAX_INPUT_LENGTH, stdin);
    num2 = atoi(op);

    // Perform the operation selected by the user
    switch (op[0]) {
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
            handle_error("Invalid operation");
            return 1;
    }

    // Check for division by zero
    if (num2 == 0) {
        handle_error("Division by zero");
        return 2;
    }

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}