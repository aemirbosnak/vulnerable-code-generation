//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return fmin(fmin(a, b), c);
}

int levenshtein_distance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int **d = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        d[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]) + 1;
            }
        }
    }

    int result = d[m][n];

    for (int i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}