//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *str1, const char *str2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = malloc((strlen(str1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(str1) + 1; i++) {
        matrix[i] = malloc((strlen(str2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i < strlen(str1) + 1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < strlen(str2) + 1; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i < strlen(str1) + 1; i++) {
        for (int j = 1; j < strlen(str2) + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[strlen(str1)][strlen(str2)];
}

// Print the Levenshtein distance matrix
void print_matrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the memory allocated for the Levenshtein distance matrix
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Get the two strings from the user
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(str1, str2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}