//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create matrix to store distances
    int **d = malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize matrix
    for (size_t i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    // Calculate distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]);
            }
        }
    }

    // Return distance
    int distance = d[len1][len2];

    // Free matrix
    for (size_t i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Main function
int main(void) {
    // Get strings from user
    char s1[100], s2[100];
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);

    // Calculate Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print distance
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}