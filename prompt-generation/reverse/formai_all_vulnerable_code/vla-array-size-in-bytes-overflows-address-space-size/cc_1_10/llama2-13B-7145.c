//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Define a function to calculate the sum of the first n positive integers
int sum(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}

// Define a function to calculate the product of the first n positive integers
int product(int n) {
    int p = 1;
    for (int i = 1; i <= n; i++) {
        p *= i;
    }
    return p;
}

int main() {
    int n, m;
    double average, standardDeviation;

    // Ask the user for the number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    // Allocate memory for the test cases
    int tests[n];
    for (int i = 0; i < n; i++) {
        tests[i] = 0;
    }

    // Ask the user for the first test case
    printf("Enter the first test case: ");
    scanf("%d", &m);

    // Calculate the factorial of the first test case
    int factorial_m = factorial(m);

    // Calculate the sum of the first test case
    int sum_m = sum(m);

    // Calculate the product of the first test case
    int product_m = product(m);

    // Calculate the average of the first test case
    double average_m = (double)sum_m / m;

    // Calculate the standard deviation of the first test case
    double standardDeviation_m = sqrt((double)(sum_m * (m - 1) / (m * m)));

    // Print the results
    printf("Test case %d:\n", m);
    printf("Factorial of %d: %d\n", m, factorial_m);
    printf("Sum of %d: %d\n", m, sum_m);
    printf("Product of %d: %d\n", m, product_m);
    printf("Average of %d: %f\n", m, average_m);
    printf("Standard deviation of %d: %f\n", m, standardDeviation_m);

    // Ask the user for the next test case
    printf("Enter the next test case: ");
    scanf("%d", &m);

    // Repeat the calculations for the next test case
    factorial_m = factorial(m);
    sum_m = sum(m);
    product_m = product(m);
    average_m = (double)sum_m / m;
    standardDeviation_m = sqrt((double)(sum_m * (m - 1) / (m * m)));

    // Print the results
    printf("Test case %d:\n", m);
    printf("Factorial of %d: %d\n", m, factorial_m);
    printf("Sum of %d: %d\n", m, sum_m);
    printf("Product of %d: %d\n", m, product_m);
    printf("Average of %d: %f\n", m, average_m);
    printf("Standard deviation of %d: %f\n", m, standardDeviation_m);

    // Repeat the loop until the user enters a negative number
    while (m >= 0) {
        // Print the results for the current test case
        printf("\n");

        // Ask the user for the next test case
        printf("Enter the next test case: ");
        scanf("%d", &m);
    }

    return 0;
}