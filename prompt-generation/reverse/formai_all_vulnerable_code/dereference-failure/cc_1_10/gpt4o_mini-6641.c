//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence and count occurrences of each number
void generateFibonacci(int n, int *fibArray, int *countArray) {
    int a = 0, b = 1, next, i;

    if (n > 0) {
        fibArray[0] = a;
        countArray[a]++; 
    }
    if (n > 1) {
        fibArray[1] = b;
        countArray[b]++; 
    }

    for (i = 2; i < n; i++) {
        next = a + b;
        fibArray[i] = next;
        countArray[next]++;
        a = b; 
        b = next;
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, int *fibArray, int *countArray) {
    int i;
    printf("Fibonacci Sequence:\n");
    
    for (i = 0; i < n; i++) {
        printf("%d ", fibArray[i]);
    }
    printf("\n\n");

    printf("Visualization:\n");
    for (i = 0; i < n; i++) {
        int counts = countArray[fibArray[i]];
        printf("%d: ", fibArray[i]);
        for (int j = 0; j < counts; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    // Create arrays for Fibonacci numbers and their counts
    int *fibArray = (int *)malloc(n * sizeof(int));
    int maxFib = 0; 

    // Dynamic allocation based on the maximum Fibonacci number we might need
    if (n > 0) {
        maxFib = (1 << 30); // Generously large assumption
    }
    int *countArray = (int *)calloc(maxFib, sizeof(int));

    // Generate the Fibonacci sequence
    generateFibonacci(n, fibArray, countArray);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(n, fibArray, countArray);

    // Cleanup
    free(fibArray);
    free(countArray);

    return 0;
}