//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    return ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));
}

int levenshtein(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    // Create a matrix to store the distances
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    // Calculate the distances for the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    // Return the distance between the two strings
    int distance = d[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *s1 = argv[1];
    const char *s2 = argv[2];

    int distance = levenshtein(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return EXIT_SUCCESS;
}