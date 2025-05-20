//Falcon-180B DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the sum of two integers
int sum(int num1, int num2) {
    return num1 + num2;
}

// Function to calculate the product of two integers
int product(int num1, int num2) {
    return num1 * num2;
}

// Function to calculate the difference between two integers
int difference(int num1, int num2) {
    return num1 - num2;
}

// Function to calculate the quotient of two integers (ignoring remainder)
int quotient(int num1, int num2) {
    return num1 / num2;
}

// Function to handle errors
void error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Main function to prompt user for input and call appropriate functions
int main() {
    char input[100];
    int num1, num2, result;

    // Prompt user for first integer
    printf("Enter the first integer: ");
    fgets(input, 100, stdin);
    num1 = atoi(input);

    // Prompt user for second integer
    printf("Enter the second integer: ");
    fgets(input, 100, stdin);
    num2 = atoi(input);

    // Prompt user for operation
    printf("Enter the operation (+, -, *, /, q): ");
    fgets(input, 100, stdin);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        error("Invalid input");
    }

    // Convert input to integer
    int operation = atoi(input);

    // Call appropriate function based on operation
    switch (operation) {
        case 1:
            result = sum(num1, num2);
            printf("The sum is %d\n", result);
            break;
        case 2:
            result = difference(num1, num2);
            printf("The difference is %d\n", result);
            break;
        case 3:
            result = product(num1, num2);
            printf("The product is %d\n", result);
            break;
        case 4:
            result = quotient(num1, num2);
            printf("The quotient is %d\n", result);
            break;
        default:
            error("Invalid operation");
    }

    return 0;
}