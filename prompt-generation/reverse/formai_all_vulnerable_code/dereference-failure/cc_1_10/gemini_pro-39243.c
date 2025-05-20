//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the Levenshtein distance matrix
int **initialize_matrix(int m, int n) {
    int **matrix = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (n + 1));
    }
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }
    return matrix;
}

// Deallocate the Levenshtein distance matrix
void deallocate_matrix(int **matrix, int m) {
    for (int i = 0; i <= m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(char *a, char *b, int m, int n) {
    int **matrix = initialize_matrix(m, n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int min = matrix[i - 1][j - 1];
                if (min > matrix[i - 1][j]) {
                    min = matrix[i - 1][j];
                }
                if (min > matrix[i][j - 1]) {
                    min = matrix[i][j - 1];
                }
                matrix[i][j] = min + 1;
            }
        }
    }
    int distance = matrix[m][n];
    deallocate_matrix(matrix, m);
    return distance;
}

// Print the Levenshtein distance matrix
void print_matrix(int **matrix, int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Test the Levenshtein distance calculator
int main() {
    char *a = "kitten";
    char *b = "sitting";
    int m = strlen(a);
    int n = strlen(b);
    int distance = levenshtein_distance(a, b, m, n);
    printf("Levenshtein distance between '%s' and '%s': %d\n", a, b, distance);
    return 0;
}