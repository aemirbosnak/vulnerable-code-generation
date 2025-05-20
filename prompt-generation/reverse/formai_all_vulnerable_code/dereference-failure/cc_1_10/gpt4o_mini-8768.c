//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
int levenshteinDistance(const char *str1, const char *str2);
void printMatrix(int **matrix, int len1, int len2);
int **allocateMatrix(int rows, int cols);
void freeMatrix(int **matrix);

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    int distance = levenshteinDistance(str1, str2);
    
    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}

int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Allocate a matrix
    int **matrix = allocateMatrix(len1 + 1, len2 + 1);

    // Initialize the first row and column
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Populate the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1,  // Deletion
                                      matrix[i][j - 1] + 1), // Insertion
                                      matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Optionally print the matrix
    printf("\nLevenshtein Matrix:\n");
    printMatrix(matrix, len1 + 1, len2 + 1);

    // Get the distance from the bottom-right cell
    int distance = matrix[len1][len2];

    // Free the allocated matrix
    freeMatrix(matrix);
    
    return distance;
}

// Function to print the matrix
void printMatrix(int **matrix, int len1, int len2) {
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to allocate a 2D matrix
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free the allocated matrix
void freeMatrix(int **matrix) {
    free(matrix[0]); // Free the first row
    free(matrix);    // Free the pointers
}