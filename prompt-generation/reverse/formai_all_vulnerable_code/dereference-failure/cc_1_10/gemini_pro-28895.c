//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int n = strlen(s1) + 1;
    int m = strlen(s2) + 1;
    int **d = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        d[i] = malloc(m * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i < n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < m; j++) {
        d[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, min(d[i][j - 1] + 1, d[i - 1][j - 1] + cost));
        }
    }

    // Return the Levenshtein distance
    int result = d[n - 1][m - 1];

    // Free the matrix
    for (int i = 0; i < n; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

// Find the minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Print the usage message
void usage() {
    printf("Usage: levenshtein <string1> <string2>\n");
    printf("Calculates the Levenshtein distance between two strings.\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        usage();
        return 1;
    }

    // Calculate the Levenshtein distance
    int distance = levenshtein(argv[1], argv[2]);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", argv[1], argv[2], distance);

    return 0;
}