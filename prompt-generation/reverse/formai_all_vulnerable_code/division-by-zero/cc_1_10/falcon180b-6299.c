//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

// Function to calculate the modulus of two integers
int modulus(int a, int b) {
    return a % b;
}

// Function to calculate the power of two integers
int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int main() {
    int num1, num2, result;
    char operation;

    // Prompt user to enter two integers and an operation
    printf("Enter two integers and an operation:\n");
    scanf("%d %d %c", &num1, &num2, &operation);

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = add(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '%':
            result = modulus(num1, num2);
            printf("The result is %d.\n", result);
            break;
        case '^':
            result = power(num1, num2);
            printf("The result is %d.\n", result);
            break;
        default:
            printf("Invalid operation. Please enter a valid operation.\n");
            break;
    }

    return 0;
}