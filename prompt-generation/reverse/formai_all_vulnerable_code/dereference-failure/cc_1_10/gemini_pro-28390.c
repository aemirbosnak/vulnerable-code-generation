//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a matrix to store the Levenshtein distances
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i < len1 + 1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (size_t i = 0; i < len1 + 1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j < len2 + 1; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (size_t i = 1; i < len1 + 1; i++) {
        for (size_t j = 1; j < len2 + 1; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(
                matrix[i - 1][j] + 1, // Deletion
                fmin(
                    matrix[i][j - 1] + 1, // Insertion
                    matrix[i - 1][j - 1] + cost // Substitution
                )
            );
        }
    }

    // Return the Levenshtein distance
    int distance = matrix[len1][len2];

    // Free the matrix
    for (size_t i = 0; i < len1 + 1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    // Example strings
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);

    return 0;
}