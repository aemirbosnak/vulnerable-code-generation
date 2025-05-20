//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_NUM 1000

// Function to print a thoughtful message
void thoughtful_message(void) {
    printf("Thinking...\n");
    printf("Life is a journey, not a destination. Enjoy the ride, and don't forget to take in the views.\n");
}

// Function to read an integer from the user
int get_integer(void) {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    return num;
}

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the product of two integers
int product(int a, int b) {
    return a * b;
}

// Function to calculate the difference of two integers
int difference(int a, int b) {
    return a - b;
}

// Function to calculate the quotient of two integers
int quotient(int a, int b) {
    return a / b;
}

int main(void) {
    int num1, num2, result;
    char op;

    // Ask the user for the first number
    num1 = get_integer();
    thoughtful_message();

    // Ask the user for the second number
    num2 = get_integer();
    thoughtful_message();

    // Ask the user for the operation to perform
    printf("Enter an operation (+, -, x, /): ");
    scanf(" %c", &op);
    thoughtful_message();

    // Perform the operation
    switch (op) {
        case '+':
            result = sum(num1, num2);
            break;
        case '-':
            result = difference(num1, num2);
            break;
        case '*':
            result = product(num1, num2);
            break;
        case '/':
            result = quotient(num1, num2);
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}