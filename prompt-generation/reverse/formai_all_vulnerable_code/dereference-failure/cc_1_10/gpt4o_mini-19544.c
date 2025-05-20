//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int min(int a, int b, int c);
int levenshteinDistance(const char *s1, const char *s2);
void print_matrix(int **matrix, int rows, int cols);

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Extract strings from the command line
    const char *s1 = argv[1];
    const char *s2 = argv[2];

    // Calculate the Levenshtein distance
    int distance = levenshteinDistance(s1, s2);

    // Display the result
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

// Function to compute Levenshtein Distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a matrix to hold distances
    int **matrix = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        matrix[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize matrix
    for (int i = 0; i <= len_s1; i++) {
        matrix[i][0] = i; // Distance from s1[0..i] to ""
    }
    for (int j = 0; j <= len_s2; j++) {
        matrix[0][j] = j; // Distance from "" to s2[0..j]
    }

    // Compute distances
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Cost of substitution
            matrix[i][j] = min(matrix[i - 1][j] + 1,     // Deletion
                               matrix[i][j - 1] + 1,     // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    // Store the result
    int distance = matrix[len_s1][len_s2];

    // Print the matrix for debugging purposes
    print_matrix(matrix, len_s1 + 1, len_s2 + 1);

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Function to print the distance matrix
void print_matrix(int **matrix, int rows, int cols) {
    printf("Distance Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}