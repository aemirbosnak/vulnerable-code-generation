//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
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

    // Calculate the Levenshtein distances for the remaining cells in the matrix.
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = fmin(
                fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1),
                matrix[i - 1][j - 1] + cost
            );
        }
    }

    // Return the Levenshtein distance between the two strings.
    int distance = matrix[strlen(s1)][strlen(s2)];

    // Free the matrix.
    for (int i = 0; i <= strlen(s1); i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Print the Levenshtein distance between two strings.
void print_distance(const char *s1, const char *s2) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, levenshtein(s1, s2));
}

// Main function.
int main() {
    // Print the Levenshtein distance between two strings.
    print_distance("hello", "world");  // 4
    print_distance("kitten", "sitting");  // 3
    print_distance("algorithm", "altruistic");  // 6

    return 0;
}