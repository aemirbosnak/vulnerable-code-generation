//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int levenshtein(const char *s1, const char *s2) {
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);

    int **matrix = calloc(len1 + 1, sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = calloc(len2 + 1, sizeof(int));
    }

    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = MIN(
                matrix[i - 1][j] + 1,  // deletion
                MIN(matrix[i][j - 1] + 1,  // insertion
                    matrix[i - 1][j - 1] + cost));  // substitution
        }
    }

    int result = matrix[len1][len2];

    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main() {
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, levenshtein(s1, s2));

    return 0;
}