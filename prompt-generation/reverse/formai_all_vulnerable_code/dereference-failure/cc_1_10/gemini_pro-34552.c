//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances.
    int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        matrix[0][j] = j;
    }

    // Compute the Levenshtein distances.
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int min = matrix[i - 1][j];
                if (matrix[i][j - 1] < min) min = matrix[i][j - 1];
                if (matrix[i - 1][j - 1] < min) min = matrix[i - 1][j - 1];
                matrix[i][j] = min + 1;
            }
        }
    }

    // Return the Levenshtein distance.
    int distance = matrix[strlen(s1)][strlen(s2)];
    for (int i = 0; i <= strlen(s1); i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

// Print the Levenshtein distance between two strings.
void print_distance(const char *s1, const char *s2) {
    int distance = levenshtein(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user has provided two strings.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    // Print the Levenshtein distance between the two strings.
    print_distance(argv[1], argv[2]);

    return 0;
}