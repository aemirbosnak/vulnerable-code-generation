//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the permutation of two numbers
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate the combination of two numbers
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Main function
int main() {
    // Declare variables
    int choice, n, r, a, b;

    // Display the menu
    printf("Scientific Calculator\n");
    printf("1. Factorial\n");
    printf("2. Permutation\n");
    printf("3. Combination\n");
    printf("4. Greatest Common Divisor\n");
    printf("5. Least Common Multiple\n");
    printf("6. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the calculation based on the user's choice
    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("The factorial of %d is %d\n", n, factorial(n));
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &n, &r);
            printf("The permutation of %d and %d is %d\n", n, r, permutation(n, r));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &n, &r);
            printf("The combination of %d and %d is %d\n", n, r, combination(n, r));
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("The greatest common divisor of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("The least common multiple of %d and %d is %d\n", a, b, lcm(a, b));
            break;
        case 6:
            printf("Exiting the calculator\n");
            exit(0);
        default:
            printf("Invalid choice\n");
    }

    return 0;
}