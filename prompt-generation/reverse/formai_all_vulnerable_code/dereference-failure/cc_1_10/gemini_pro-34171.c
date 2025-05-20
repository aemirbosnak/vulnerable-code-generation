//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance matrix
static int **ldm;

// Levenshtein distance calculation
int levenshtein(const char *s1, const char *s2) {
    // Initialize matrix
    ldm = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(s1); i++) {
        ldm[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Fill first row and column
    for (int i = 0; i <= strlen(s1); i++) {
        ldm[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        ldm[0][j] = j;
    }

    // Fill matrix
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            ldm[i][j] = fmin(ldm[i - 1][j] + 1,  // Deletion
                             fmin(ldm[i][j - 1] + 1,  // Insertion
                                  ldm[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])));  // Substitution
        }
    }

    // Return result
    int result = ldm[strlen(s1)][strlen(s2)];

    // Free matrix
    for (int i = 0; i <= strlen(s1); i++) {
        free(ldm[i]);
    }
    free(ldm);

    return result;
}

int main() {
    // Sample input strings
    char *s1 = "kitten";
    char *s2 = "sitting";

    // Calculate Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print result
    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}