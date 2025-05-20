//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a decimal number
void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    printf("%d", n % 2);
    printBinary(n / 2);
}

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate Fibonacci series using recursion
void fibonacci(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    printf("%d ", 0);
    fibonacci(n - 1);
    printf("%d ", 1);
    fibonacci(n - 2);
}

// Function to calculate GCD using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate LCM using recursion
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    // Example usage of printBinary function
    printf("Enter a decimal number: ");
    int num;
    scanf("%d", &num);
    printf("Binary representation: ");
    printBinary(num);
    printf("\n");

    // Example usage of factorial function
    printf("Enter a non-negative integer: ");
    int n;
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    // Example usage of fibonacci function
    printf("Enter the number of terms in the Fibonacci series: ");
    int terms;
    scanf("%d", &terms);
    printf("Fibonacci series up to %d terms:\n", terms);
    fibonacci(terms);

    // Example usage of gcd and lcm functions
    printf("Enter two integers: ");
    int x, y;
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    printf("LCM of %d and %d is %d\n", x, y, lcm(x, y));

    return 0;
}