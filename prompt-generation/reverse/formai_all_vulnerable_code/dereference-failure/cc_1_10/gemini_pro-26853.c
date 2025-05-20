//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Watson, fetch me the magnifying glass and the chalk!

// The Adventure of the Singular Matrix

// The magnifying glass to reveal the hidden secrets
int determinant(int **matrix, int n) {
    int det = 0;
    if (n == 1)
        return matrix[0][0];
    int i, j, k;
    int **submatrix = (int **)malloc(sizeof(int *) * (n - 1));
    for (i = 0; i < n - 1; i++)
        submatrix[i] = (int *)malloc(sizeof(int) * (n - 1));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int subDet = 0;
            for (k = 1; k < n; k++) {
                int p = k % 2 ? 0 : j;
                int q = k % 2 ? j : 0;
                submatrix[k - 1][q] = matrix[k][p];
            }
            subDet = determinant(submatrix, n - 1);
            // Elementary, my dear Watson!
            det += (i % 2 ? -1 : 1) * matrix[0][j] * subDet;
        }
    }
    for (i = 0; i < n - 1; i++)
        free(submatrix[i]);
    free(submatrix);
    return det;
}

// The chalk to delineate the suspects
void printMatrix(int **matrix, int n) {
    int i, j;
    printf("The matrix under investigation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// The grand finale
int main() {
    int n;
    printf("Watson, what is the dimension of the matrix?");
    scanf("%d", &n);
    // Instantiating the crime scene
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(sizeof(int) * n);
    printf("Now, the contents of the matrix:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Time to solve the mystery
    printMatrix(matrix, n);
    int det = determinant(matrix, n);
    if (det == 0)
        printf("The matrix is singular, my dear Watson. The mystery remains unsolved.");
    else
        printf("Elementary, my dear Watson! The determinant is %d. The mystery is solved.", det);
    // Cleaning up the crime scene
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}