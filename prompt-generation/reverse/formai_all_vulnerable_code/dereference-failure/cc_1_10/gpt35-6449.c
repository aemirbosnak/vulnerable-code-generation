//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a;

    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }

    return m;
}

int levenshtein_distance(char *s, char *t, int m, int n) {
    int **d, cost;
    int i, j;

    d = (int **) malloc(sizeof(int *) * (m + 1));
    for (i = 0; i <= m; i++) {
        d[i] = (int *) malloc(sizeof(int) * (n + 1));
    }

    for (i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            d[i][j] = min(
                d[i - 1][j] + 1,
                d[i][j - 1] + 1,
                d[i - 1][j - 1] + cost
            );
        }
    }

    int dist = d[m][n];

    for (i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);

    return dist;
}

int main() {
    char s[] = "energy";
    char t[] = "synergy";

    int dist = levenshtein_distance(s, t, strlen(s), strlen(t));

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s, t, dist);

    return 0;
}