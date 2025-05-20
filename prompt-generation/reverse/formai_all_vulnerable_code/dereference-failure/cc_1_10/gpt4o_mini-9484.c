//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size for the Fibonacci cache
#define MAX_FIB 100

// Array to hold computed Fibonacci values
long long fib_cache[MAX_FIB];

// Function to initialize the Fibonacci cache
void initialize_fib_cache() {
    for(int i = 0; i < MAX_FIB; i++) {
        fib_cache[i] = -1; // Use -1 to denote that the value is not computed yet
    }
}

// Recursive function to compute Fibonacci number using memoization
long long fibonacci(int n) {
    // Check for valid input
    if (n < 0) {
        fprintf(stderr, "Error: Negative input for Fibonacci function.\n");
        exit(EXIT_FAILURE);
    }
    
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // If the value is already computed, return it from the cache
    if (fib_cache[n] != -1) {
        return fib_cache[n];
    }
    
    // Compute the value and store it in the cache
    fib_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    return fib_cache[n];
}

// Main function
int main(int argc, char *argv[]) {
    // Ensure that the user has provided a command line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Convert the command line argument to an integer
    int n = atoi(argv[1]);
    
    // Initialize the Fibonacci cache
    initialize_fib_cache();
    
    // Calculate the Fibonacci number
    long long result = fibonacci(n);
    
    // Print the result
    printf("Fibonacci(%d) = %lld\n", n, result);
    
    return EXIT_SUCCESS;
}