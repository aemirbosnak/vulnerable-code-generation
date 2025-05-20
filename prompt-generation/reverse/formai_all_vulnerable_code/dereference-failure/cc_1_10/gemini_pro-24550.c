//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to find the minimum of three integers
int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein(char *str1, char *str2) {
    // Create a matrix to store the distances
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

    // Calculate the distances
    for (int i = 1; i < strlen(str1) + 1; i++) {
        for (int j = 1; j < strlen(str2) + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    // Return the distance
    return matrix[strlen(str1)][strlen(str2)];
}

// A utility function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// A utility function to test the Levenshtein distance function
void test_levenshtein() {
    char *str1 = "kitten";
    char *str2 = "sitting";

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
}

// A utility function to free the memory allocated for the matrix
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    test_levenshtein();
    return 0;
}