//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Surprise! We're going to calculate the Levenshtein distance between two strings using a dynamic programming approach.
int levenshtein(const char *s1, const char *s2) {
    // Initialize the distance matrix.
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int **d = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        d[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        d[0][j] = j;
    }

    // Calculate the distance matrix.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    // Return the distance.
    int distance = d[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(d[i]);
    }
    free(d);
    return distance;
}

// Surprise! We've got a main function that you can use to test the Levenshtein distance calculator.
int main() {
    // Initialize the strings.
    char *s1 = "kitten";
    char *s2 = "sitting";

    // Calculate the Levenshtein distance.
    int distance = levenshtein(s1, s2);

    // Print the result.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}