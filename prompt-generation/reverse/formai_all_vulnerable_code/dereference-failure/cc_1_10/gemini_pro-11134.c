//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
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

    // Calculate the distance matrix.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1]));
            }
        }
    }

    // Return the distance.
    return d[m - 1][n - 1];
}

// Find the minimum of three integers.
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

// Print the usage message and exit.
void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s string1 string2\n", program_name);
    exit(EXIT_FAILURE);
}

// Main function.
int main(int argc, char *argv[]) {
    // Check the arguments.
    if (argc != 3) {
        usage(argv[0]);
    }

    // Calculate the Levenshtein distance.
    int distance = levenshtein(argv[1], argv[2]);

    // Print the distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", argv[1], argv[2], distance);

    return EXIT_SUCCESS;
}