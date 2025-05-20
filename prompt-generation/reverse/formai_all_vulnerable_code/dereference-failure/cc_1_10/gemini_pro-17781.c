//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a string metric for measuring the difference between two sequences.
// It is commonly used to find the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one sequence into another.

// This function computes the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Initialize the distance matrix.
    int n = strlen(s1);
    int m = strlen(s2);
    int d[n + 1][m + 1];

    // Initialize the first row and column of the distance matrix.
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    // Compute the Levenshtein distance for each cell in the distance matrix.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,  // Deletion
                           d[i][j - 1] + 1,  // Insertion
                           d[i - 1][j - 1] + cost);  // Substitution
        }
    }

    // Return the Levenshtein distance.
    return d[n][m];
}

// This function finds the minimum of three integers.
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// This function prints the usage information for the program.
void usage(const char *program_name) {
    printf("Usage: %s string1 string2\n", program_name);
    printf("Computes the Levenshtein distance between two strings.\n");
}

// This is the main function of the program.
int main(int argc, char *argv[]) {
    // Check the number of arguments.
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Get the two strings from the command line.
    const char *s1 = argv[1];
    const char *s2 = argv[2];

    // Compute the Levenshtein distance between the two strings.
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance.
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}