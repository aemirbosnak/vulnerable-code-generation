//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cost of insertion, deletion, and substitution
#define COST_INSERT 1
#define COST_DELETE 1
#define COST_SUBSTITUTE 1

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = (int **)malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i] = (int *)malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + COST_DELETE, matrix[i][j - 1] + COST_INSERT), matrix[i - 1][j - 1] + COST_SUBSTITUTE);
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[strlen(s1)][strlen(s2)];
}

// Print the Levenshtein distance matrix
void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the Levenshtein distance matrix
void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Get the two strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}