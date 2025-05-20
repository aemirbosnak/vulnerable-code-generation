//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a measure of the similarity between two strings.
// It is computed as the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other.

// This function computes the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances.
    int n = strlen(s1) + 1;
    int m = strlen(s2) + 1;
    int d[n][m];

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < m; j++) {
        d[0][j] = j;
    }

    // Compute the Levenshtein distances.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // If the characters are the same, then the Levenshtein distance is the same as the Levenshtein distance between the previous characters.
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            // Otherwise, the Levenshtein distance is the minimum of the Levenshtein distances between the previous characters plus 1.
            else {
                d[i][j] = 1 + fmin(d[i - 1][j], fmin(d[i][j - 1], d[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance.
    return d[n - 1][m - 1];
}

// This function prints the Levenshtein distance between two strings.
void print_levenshtein(const char *s1, const char *s2) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, levenshtein(s1, s2));
}

// This function is the entry point of the program.
int main(int argc, char **argv) {
    // Check if the user has provided two strings.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Print the Levenshtein distance between the two strings.
    print_levenshtein(argv[1], argv[2]);

    return 0;
}