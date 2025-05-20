//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
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
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int distance = matrix[strlen(s1)][strlen(s2)];
    
    // Free the matrix
    for (int i = 0; i < strlen(s1) + 1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return distance;
}

// Function to test the Levenshtein distance calculator
int main() {
    // Test the Levenshtein distance calculator
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance = levenshtein(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}