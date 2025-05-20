//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
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
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int result = matrix[strlen(s1)][strlen(s2)];

    // Free the matrix
    for (int i = 0; i <= strlen(s1); i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

// Print the usage information
void usage(const char *program_name) {
    printf("Usage: %s <string1> <string2>\n", program_name);
    printf("Calculate the Levenshtein distance between two strings.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Calculate the Levenshtein distance
    int distance = levenshtein(argv[1], argv[2]);

    // Print the Levenshtein distance
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}