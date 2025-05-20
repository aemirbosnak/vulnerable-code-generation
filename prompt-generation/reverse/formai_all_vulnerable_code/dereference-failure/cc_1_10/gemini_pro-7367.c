//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <string.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Initialize the distance matrix.
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int d[m][n];
    for (int i = 0; i < m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        d[0][j] = j;
    }

    // Compute the distance matrix.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    // Return the distance.
    return d[m - 1][n - 1];
}

// Find the minimum of three integers.
int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    } else {
        return b < c ? b : c;
    }
}

// Print the usage information.
void usage() {
    printf("Usage: levenshtein <string1> <string2>\n");
}

// Main function.
int main(int argc, char *argv[]) {
    // Check the number of arguments.
    if (argc != 3) {
        usage();
        return 1;
    }

    // Get the two strings.
    const char *s1 = argv[1];
    const char *s2 = argv[2];

    // Compute the Levenshtein distance.
    int distance = levenshtein(s1, s2);

    // Print the distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}