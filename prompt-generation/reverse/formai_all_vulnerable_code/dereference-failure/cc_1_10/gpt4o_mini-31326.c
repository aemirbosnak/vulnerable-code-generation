//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 1000

// Allocate an array for memoization
long long memo[MAX_FIB];

// Function to initialize memo array
void initialize_memo() {
    for (int i = 0; i < MAX_FIB; i++) {
        memo[i] = -1;  // Use -1 to signify uninitialized values
    }
}

// Memoized Fibonacci function
long long fibonacci(int n) {
    if (n < 0) {
        // Invalid input
        fprintf(stderr, "Input should be a non-negative integer.\n");
        exit(EXIT_FAILURE);
    }
    
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    
    // Return the already computed value if it exists
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Store the computed value in the memo array
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

// Function to print Fibonacci series up to n
void print_fibonacci_series(int n) {
    printf("Fibonacci series up to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");
}

// Main function to demonstrate performance of Fibonacci calculation
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <non-negative integer>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int n = atoi(argv[1]);
    
    // Check for valid input
    if (n < 0 || n >= MAX_FIB) {
        fprintf(stderr, "Please enter a non-negative integer less than %d.\n", MAX_FIB);
        return EXIT_FAILURE;
    }
    
    // Initialize memoization array
    initialize_memo();
    
    // Print the Fibonacci series
    print_fibonacci_series(n);
    
    return EXIT_SUCCESS;
}