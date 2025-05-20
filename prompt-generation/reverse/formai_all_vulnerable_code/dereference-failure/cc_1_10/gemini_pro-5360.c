//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256

int main() {
    char *s1, *s2;
    int s1_len, s2_len, i, j, cost;
    int **d;

    printf("Enter the first string (max %d chars): ", MAX_STR_LEN);
    s1 = malloc(MAX_STR_LEN * sizeof(char));
    scanf("%s", s1);

    printf("Enter the second string (max %d chars): ", MAX_STR_LEN);
    s2 = malloc(MAX_STR_LEN * sizeof(char));
    scanf("%s", s2);

    s1_len = strlen(s1);
    s2_len = strlen(s2);

    // Initialize the distance matrix
    d = malloc((s1_len + 1) * sizeof(int *));
    for (i = 0; i <= s1_len; i++) {
        d[i] = malloc((s2_len + 1) * sizeof(int));
    }

    // Initialize the first row and column of the distance matrix
    for (i = 0; i <= s1_len; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= s2_len; j++) {
        d[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (i = 1; i <= s1_len; i++) {
        for (j = 1; j <= s2_len; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            d[i][j] = min(d[i - 1][j] + 1,  // Deletion
                           min(d[i][j - 1] + 1,  // Insertion
                               d[i - 1][j - 1] + cost));  // Substitution
        }
    }

    // Print the distance matrix
    printf("Levenshtein distance matrix:\n");
    for (i = 0; i <= s1_len; i++) {
        for (j = 0; j <= s2_len; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    // Print the Levenshtein distance
    printf("Levenshtein distance: %d\n", d[s1_len][s2_len]);

    // Free the allocated memory
    free(s1);
    free(s2);
    for (i = 0; i <= s1_len; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}

int min(int a, int b, int c) {
    int m = a;

    if (b < m) {
        m = b;
    }
    if (c < m) {
        m = c;
    }

    return m;
}