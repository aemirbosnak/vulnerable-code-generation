//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshteinDistance(char *s1, char *s2) {
    if (!s1 || !s2) {
        return -1;
    }

    int m = strlen(s1);
    int n = strlen(s2);

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    int **d = (int **) malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++) {
        d[i] = (int *) malloc(sizeof(int) * (n + 1));
    }

    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                int min = d[i - 1][j] < d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
                min = min < d[i - 1][j - 1] ? min : d[i - 1][j - 1];
                d[i][j] = min + 1;
            }
        }
    }

    int distance = d[m][n];

    for (int i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";

    int distance = levenshteinDistance(s1, s2);

    printf("Levenshtein Distance between %s and %s: %d", s1, s2, distance);

    return 0;
}