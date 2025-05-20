//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
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

// Function to calculate the sum of the cubes of the first n natural numbers
int sum_of_cubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(i, 3);
    }
    return sum;
}

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
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Generate a random number between 1 and n
    int rand_num_1 = rand_num(1, n);
    int rand_num_2 = rand_num(1, n);

    // Calculate the greatest common divisor of the two random numbers
    int gcd_result = gcd(rand_num_1, rand_num_2);

    // Calculate the least common multiple of the two random numbers
    int lcm_result = lcm(rand_num_1, rand_num_2);

    // Calculate the sum of the cubes of the first n natural numbers
    int sum_of_cubes_result = sum_of_cubes(n);

    // Calculate the factorial of the input number
    int factorial_result = factorial(n);

    // Calculate the nth Fibonacci number
    int fibonacci_result = fibonacci(n);

    // Print the results
    printf("Random numbers: %d, %d\n", rand_num_1, rand_num_2);
    printf("GCD: %d\n", gcd_result);
    printf("LCM: %d\n", lcm_result);
    printf("Sum of cubes: %d\n", sum_of_cubes_result);
    printf("Factorial: %d\n", factorial_result);
    printf("Fibonacci number: %d\n", fibonacci_result);

    return 0;
}