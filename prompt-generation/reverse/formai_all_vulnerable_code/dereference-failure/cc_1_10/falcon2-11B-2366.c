//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to generate Fibonacci sequence up to a given number of elements
int* generate_fibonacci_sequence(int n) {
    int* sequence = (int*) malloc(n * sizeof(int));
    int a = 0, b = 1, c;
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; i++) {
        c = a + b;
        sequence[i] = c;
        a = b;
        b = c;
    }
    return sequence;
}

// Function to display Fibonacci sequence as ASCII art matrix
void display_fibonacci_matrix(int* sequence, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                printf("O");
            } else if (i + j == n - 1) {
                printf(" ");
            } else if (i + j < n - 1 && j > i) {
                printf(" ");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

// Main function to prompt user for input and display Fibonacci sequence
int main() {
    int n;
    printf("Enter the number of Fibonacci sequence elements to visualize: ");
    scanf("%d", &n);

    int* sequence = generate_fibonacci_sequence(n);
    display_fibonacci_matrix(sequence, n);

    free(sequence);
    return 0;
}