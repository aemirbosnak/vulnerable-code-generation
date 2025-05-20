//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int levenshtein_distance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int **d = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        d[i] = malloc((m + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
        d[i][0] = i;
    for (int j = 0; j <= m; j++)
        d[0][j] = j;

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == t[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = minimum(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
        }
    }

    int distance = d[n][m];

    for (int i = 0; i <= n; i++)
        free(d[i]);
    free(d);

    return distance;
}

int main() {
    char string1[] = "Hello";
    char string2[] = "Hola";
    int distance = levenshtein_distance(string1, string2);
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", string1, string2, distance);

    return 0;
}