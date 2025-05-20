//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int n = strlen(s1);
    int m = strlen(s2);
    int matrix[n + 1][m + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, // Deletion
                               matrix[i][j - 1] + 1, // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Return the Levenshtein distance
    return matrix[n][m];
}

// Find the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Print the usage message
void usage(const char *program_name) {
    printf("Usage: %s <string1> <string2>\n", program_name);
    printf("Calculate the Levenshtein distance between two strings.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Get the two strings
    const char *s1 = argv[1];
    const char *s2 = argv[2];

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return EXIT_SUCCESS;
}