//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the product of two numbers
int product(int a, int b) {
    return a * b;
}

// Function to calculate the difference between two numbers
int difference(int a, int b) {
    return a - b;
}

// Function to calculate the quotient of two numbers
int quotient(int a, int b) {
    return a / b;
}

// Function to calculate the remainder of two numbers
int remainder(int a, int b) {
    return a % b;
}

int main() {
    int num1, num2;
    char operation;

    // Prompt the user to enter the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Prompt the user to enter the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Prompt the user to enter the operation to perform
    printf("Enter the operation to perform (+, -, *, /, %): ");
    scanf(" %c", &operation);

    // Perform the operation and display the result
    switch(operation) {
        case '+':
            printf("The sum is %d\n", sum(num1, num2));
            break;
        case '-':
            printf("The difference is %d\n", difference(num1, num2));
            break;
        case '*':
            printf("The product is %d\n", product(num1, num2));
            break;
        case '/':
            printf("The quotient is %d\n", quotient(num1, num2));
            break;
        case '%':
            printf("The remainder is %d\n", remainder(num1, num2));
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }

    return 0;
}