//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Returns the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a matrix to hold the distances
    int **d = (int **) malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *) malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column with values 0 to len2
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    // Compute the distance for every substring
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,          // deletion
                          d[i][j - 1] + 1,          // insertion
                          d[i - 1][j - 1] + cost);  // substitution
        }
    }

    // Store the final result and free the memory allocated for the matrix
    int result = d[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

int main() {
    // Test the function with some examples
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance);

    char *s3 = "Saturday";
    char *s4 = "Sunday";
    distance = levenshtein_distance(s3, s4);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s3, s4, distance);

    char *s5 = "book";
    char *s6 = "back";
    distance = levenshtein_distance(s5, s6);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s5, s6, distance);

    return 0;
}