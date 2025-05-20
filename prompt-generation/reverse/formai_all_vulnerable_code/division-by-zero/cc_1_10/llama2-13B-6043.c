//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MIN_NUM 1

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the fibonacci series of a given number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to check if a given number is prime or not
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// Function to find the largest prime factor of a given number
int largestPrimeFactor(int n) {
    int largest = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int factor = n / i;
            if (isPrime(factor)) {
                largest = factor;
            }
        }
    }
    return largest;
}

int main() {
    int num1, num2, sum, product, factor, largest;
    char op;

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
        sum = num1 - num2;
    } else if (op == '*') {
        product = num1 * num2;
    } else if (op == '/') {
        product = num1 / num2;
    }

    // Check if the result is a prime number
    largest = largestPrimeFactor(sum);

    // Print the result
    printf("Result: %d\n", sum);

    // Print the prime factor of the result
    printf("Largest prime factor: %d\n", largest);

    return 0;
}