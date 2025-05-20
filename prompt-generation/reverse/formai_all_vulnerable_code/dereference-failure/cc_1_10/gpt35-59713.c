//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int LevenshteinDistance(char *s, char *t) {
    int m = strlen(s) + 1;
    int n = strlen(t) + 1;
    int i, j;

    int **d = malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        d[i] = malloc(n * sizeof(int));

    for (i = 0; i < m; i++)
        d[i][0] = i;

    for (j = 0; j < n; j++)
        d[0][j] = j;

    for (j = 1; j < n; j++) {
        for (i = 1; i < m; i++) {
            if (s[i - 1] == t[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
        }
    }

    int dist = d[m - 1][n - 1];

    for (i = 0; i < m; i++)
        free(d[i]);
    free(d);

    return dist;
}

int main() {
    char s[] = "kitten";
    char t[] = "sitting";

    int dist = LevenshteinDistance(s, t);

    printf("The Levenshtein distance between %s and %s is %d\n", s, t, dist);

    return 0;
}