//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the sum of the digits of a number
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}

// Function to reverse a string
char *reverseString(char *str) {
    if (*str == '\0') {
        return str;
    } else {
        char *rest = reverseString(str + 1);
        *str = *rest;
        *(rest + 1) = '\0';
        return str;
    }
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    } else {
        for (int i = 3; i <= n / 2; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// Function to convert a number from base 10 to any other base
char *convertBase(int n, int base) {
    if (n == 0) {
        return "0";
    } else {
        char *result = malloc(100);
        int i = 0;
        while (n > 0) {
            int digit = n % base;
            if (digit < 10) {
                result[i] = digit + '0';
            } else {
                result[i] = digit - 10 + 'A';
            }
            i++;
            n /= base;
        }
        result[i] = '\0';
        return reverseString(result);
    }
}

int main() {
    // Print the factorial of 5
    printf("Factorial of 5: %d\n", factorial(5));

    // Print the 10th Fibonacci number
    printf("10th Fibonacci number: %d\n", fibonacci(10));

    // Print the sum of the digits of 12345
    printf("Sum of the digits of 12345: %d\n", sumOfDigits(12345));

    // Reverse the string "Hello, world!"
    char *str = "Hello, world!";
    printf("Reversed string: %s\n", reverseString(str));

    // Check if 17 is prime
    printf("Is 17 prime? %s\n", isPrime(17) ? "Yes" : "No");

    // Find the greatest common divisor of 12 and 18
    printf("Greatest common divisor of 12 and 18: %d\n", gcd(12, 18));

    // Find the least common multiple of 12 and 18
    printf("Least common multiple of 12 and 18: %d\n", lcm(12, 18));

    // Convert 100 to base 2
    printf("100 in base 2: %s\n", convertBase(100, 2));

    return 0;
}