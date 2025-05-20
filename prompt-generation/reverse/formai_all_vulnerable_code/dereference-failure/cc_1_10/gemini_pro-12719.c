//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = (int **)malloc(sizeof(int *) * (strlen(s1) + 1));
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (strlen(s2) + 1));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int distance = matrix[strlen(s1)][strlen(s2)];

    // Free the matrix
    for (int i = 0; i <= strlen(s1); i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Main function
int main() {
    // Get the two strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}