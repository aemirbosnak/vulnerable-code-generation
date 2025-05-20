//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100
#define MIN_NUM -100

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the Fibonacci sequence of a given number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to calculate the sum of the first n Fibonacci numbers
int fibonacci_sum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fibonacci(i);
    }
    return sum;
}

int main() {
    int num, n;
    double average, deviation;

    // Get the number of test cases
    scanf("%d", &num);

    // Loop through each test case
    for (int i = 0; i < num; i++) {
        // Get the number and the Fibonacci sequence length
        scanf("%d%d", &n, &n);

        // Calculate the Fibonacci sequence
        int fibonacci_array[n];
        for (int j = 0; j < n; j++) {
            fibonacci_array[j] = fibonacci(j);
        }

        // Calculate the sum of the Fibonacci sequence
        int sum = fibonacci_sum(n);

        // Calculate the average of the Fibonacci sequence
        average = (double)sum / n;

        // Calculate the deviation of the Fibonacci sequence
        deviation = sqrt((double)(sum * sum) / (n * n));

        // Print the results
        printf("Case %d: Sum = %d, Average = %.2f, Deviation = %.2f\n", i + 1, sum, average, deviation);
    }

    return 0;
}