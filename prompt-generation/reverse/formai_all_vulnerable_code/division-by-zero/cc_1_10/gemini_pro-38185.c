//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

// A function to find the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// A function to find the sum of the digits of a number
int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sum_of_digits(n / 10);
    }
}

// A function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// A function to find the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// A function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// A function to find the nth Catalan number
int catalan(int n) {
    if (n == 0) {
        return 1;
    } else {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += catalan(i) * catalan(n - i - 1);
        }
        return sum;
    }
}

int main() {
    // Find the factorial of a number
    int n;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, factorial(n));

    // Find the sum of the digits of a number
    printf("Enter a number to find the sum of its digits: ");
    scanf("%d", &n);
    printf("The sum of the digits of %d is %d\n", n, sum_of_digits(n));

    // Find the greatest common divisor of two numbers
    int a, b;
    printf("Enter two numbers to find their greatest common divisor: ");
    scanf("%d %d", &a, &b);
    printf("The greatest common divisor of %d and %d is %d\n", a, b, gcd(a, b));

    // Find the least common multiple of two numbers
    printf("Enter two numbers to find their least common multiple: ");
    scanf("%d %d", &a, &b);
    printf("The least common multiple of %d and %d is %d\n", a, b, lcm(a, b));

    // Find the nth Fibonacci number
    printf("Enter a number to find the nth Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    // Find the nth Catalan number
    printf("Enter a number to find the nth Catalan number: ");
    scanf("%d", &n);
    printf("The %dth Catalan number is %d\n", n, catalan(n));

    return 0;
}