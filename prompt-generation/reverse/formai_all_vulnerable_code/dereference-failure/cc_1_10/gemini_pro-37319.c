//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance matrix
int **matrix;

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Initialize the matrix
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1),
                                matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int distance = matrix[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Calculate the Levenshtein distance
    int distance = levenshtein(argv[1], argv[2]);

    // Print the Levenshtein distance
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}