//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100000
#define MIN_NUM -100000

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the digits of a given number
int sum_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum = (sum + (n % 10)) % 10;
        n /= 10;
    }
    return sum;
}

// Function to calculate the greatest common divisor of two given numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2, result;
    char op;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user (either +, -, *, or /)
    printf("Enter the operation (+, -, *, or /): ");
    scanf(" %c", &op);

    // Perform the operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        printf("Invalid operation. Please try again.\n");
        return 1;
    }

    // Check if the result is negative
    if (result < 0) {
        printf("The result is negative. Please try again.\n");
        return 2;
    }

    // Print the result
    printf("The result is %d.\n", result);

    // Ask the user if they want to try again
    printf("Do you want to try again? (y/n): ");
    char again;
    scanf(" %c", &again);

    // If the user wants to try again, repeat the process
    if (again == 'y' || again == 'Y') {
        main();
    } else {
        return 0;
    }

    return 0;
}