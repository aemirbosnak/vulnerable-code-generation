//FormAI DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// function prototypes
bool isPrime(int n);
int gcd(int a, int b);
int lcm(int a, int b);
double power(double base, int exponent);
int factorial(int n);

int main() {
    srand(time(NULL));  // seed random number generator
    int choice;

    do {
        // display menu to user
        printf("Choose an operation:\n"
               "1) Check if a number is prime\n"
               "2) Find the GCD of two numbers\n"
               "3) Find the LCM of two numbers\n"
               "4) Raise a number to a power\n"
               "5) Find the factorial of a number\n"
               "6) Quit\n");

        scanf("%d", &choice);  // read user's choice

        switch (choice) {
            case 1: {
                int num;
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPrime(num)) {
                    printf("The number is prime.\n");
                } else {
                    printf("The number is not prime.\n");
                }
                break;
            }
            case 2: {
                int a, b;
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("The GCD of %d and %d is %d.\n", a, b, gcd(a, b));
                break;
            }
            case 3: {
                int a, b;
                printf("Enter first number: ");
                scanf("%d", &a);
                printf("Enter second number: ");
                scanf("%d", &b);
                printf("The LCM of %d and %d is %d.\n", a, b, lcm(a, b));
                break;
            }
            case 4: {
                double base;
                int exponent;
                printf("Enter base: ");
                scanf("%lf", &base);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                printf("%lf raised to the power of %d is %lf.\n", base, exponent, power(base, exponent));
                break;
            }
            case 5: {
                int n;
                printf("Enter a number: ");
                scanf("%d", &n);
                printf("The factorial of %d is %d.\n", n, factorial(n));
                break;
            }
            case 6: {
                printf("Goodbye!\n");
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

/*
    Determines whether a number is prime or not.
    Returns true if the number is prime, false otherwise.
*/
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/*
    Computes the GCD of two numbers using Euclid's algorithm.
    Returns the GCD.
*/
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/*
    Computes the LCM of two numbers.
    Returns the LCM.
*/
int lcm(int a, int b) {
    int gcd_val = gcd(a, b);
    return a * (b / gcd_val);
}

/*
    Raises a base to an exponent.
    Returns the result.
*/
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/*
    Computes the factorial of a number.
    Returns the factorial.
*/
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}