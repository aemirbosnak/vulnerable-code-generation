//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance matrix calculation
int **levenshtein(const char *s1, const char *s2) {
    const size_t m = strlen(s1) + 1;
    const size_t n = strlen(s2) + 1;
    int **matrix = malloc(m * sizeof(int *));
    for (size_t i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    // Initialize the first row and column
    for (size_t i = 0; i < m; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j < n; j++) {
        matrix[0][j] = j;
    }
    // Fill in the rest of the matrix
    for (size_t i = 1; i < m; i++) {
        for (size_t j = 1; j < n; j++) {
            const int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1),
                                 matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix;
}

// Print the Levenshtein distance matrix
void print_matrix(int **matrix, const size_t m, const size_t n) {
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the Levenshtein distance matrix
void free_matrix(int **matrix, const size_t m) {
    for (size_t i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    // Calculate the Levenshtein distance matrix
    int **matrix = levenshtein(s1, s2);
    const size_t m = strlen(s1) + 1;
    const size_t n = strlen(s2) + 1;

    // Print the Levenshtein distance matrix
    printf("Levenshtein distance matrix:\n");
    print_matrix(matrix, m, n);

    // Free the Levenshtein distance matrix
    free_matrix(matrix, m);

    return 0;
}