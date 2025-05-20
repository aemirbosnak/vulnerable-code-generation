//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein(char *s, char *t, int m, int n) {
    int i, j;
    int **table;

    table = (int **) malloc((m + 1) * sizeof(int *));
    for (i = 0; i <= m; i++) {
        table[i] = (int *) malloc((n + 1) * sizeof(int));
    }

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) {
                table[i][j] = j;
            } else if (j == 0) {
                table[i][j] = i;
            } else {
                int substitutionCost = s[i - 1] == t[j - 1] ? 0 : 1;
                table[i][j] = min(table[i - 1][j] + 1,          /* deletion */
                                table[i][j - 1] + 1,          /* insertion */
                                table[i - 1][j - 1] + substitutionCost); /* substitution */
            }
        }
    }

    int distance = table[m][n];

    for (i = 0; i <= m; i++) {
        free(table[i]);
    }
    free(table);

    return distance;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    int distance = levenshtein(s1, s2, strlen(s1), strlen(s2));
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}