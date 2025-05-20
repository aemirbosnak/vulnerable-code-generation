//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#define N 3

// Recursive function to generate the Sierpinski triangle
void sierpinski(int n, int x, int y, int **matrix) {
    if (n == 1) {
        matrix[x][y] = 1; // Fill the middle pixel with white
        return;
    }
    
    // Recursively call the function on the four sub-triangles
    sierpinski(n - 1, x + 1, y, matrix);
    sierpinski(n - 1, x + 1, y + 1, matrix);
    sierpinski(n - 1, x, y + 1, matrix);
    sierpinski(n - 1, x + 1, y + 1, matrix);
}

// Main function to generate and display the Sierpinski triangle
int main() {
    int n = 6; // Number of iterations
    
    // Allocate memory for the 2D array
    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }
    
    // Initialize the matrix with black pixels
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Generate the Sierpinski triangle
    sierpinski(n, 1, 1, matrix);
    
    // Display the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}