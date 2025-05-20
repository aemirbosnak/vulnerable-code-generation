//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance matrix
int **matrix;

// Compute the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Initialize the matrix
    matrix = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (n + 1));
    }

    // Initialize the first row and column
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Compute the Levenshtein distance
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[m][n];
}

// Free the memory allocated for the matrix
void free_matrix(int **matrix, int m) {
    for (int i = 0; i <= m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Compute the Levenshtein distance
    int distance = levenshtein(argv[1], argv[2]);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", argv[1], argv[2], distance);

    // Free the memory allocated for the matrix
    free_matrix(matrix, strlen(argv[1]));

    return 0;
}