//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compute Fibonacci numbers using memoization
unsigned long long fib(int n, unsigned long long *memo) {
    if (n <= 1) 
        return n;
    
    // Check if result already computed
    if (memo[n] != 0)
        return memo[n];

    // Recursive calculation with memoization
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

// Function to print Fibonacci numbers up to n
void print_fib_sequence(int n) {
    unsigned long long *memo = malloc((n + 1) * sizeof(unsigned long long));
    // Initialize memoization array
    for (int i = 0; i <= n; i++)
        memo[i] = 0;

    printf("Fibonacci Sequence up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d: %llu\n", i, fib(i, memo));
    }

    free(memo);
}

// Function to read an integer from user input
int read_input() {
    int n;
    printf("Enter a positive integer for Fibonacci calculation: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX_SIZE) {
        fprintf(stderr, "Invalid input. Please enter a valid positive integer.\n");
        exit(1);
    }
    return n;
}

int main() {
    int n = read_input();
    print_fib_sequence(n);
    return 0;
}