//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

int levenshtein(const char *s1, const char *s2) {
    size_t s1len = strlen(s1);
    size_t s2len = strlen(s2);

    int **d = malloc((s1len + 1) * sizeof(int *));
    for (size_t i = 0; i <= s1len; i++)
        d[i] = malloc((s2len + 1) * sizeof(int));

    for (size_t i = 0; i <= s1len; i++)
        d[i][0] = i;
    for (size_t j = 0; j <= s2len; j++)
        d[0][j] = j;

    for (size_t i = 1; i <= s1len; i++) {
        for (size_t j = 1; j <= s2len; j++) {
            int cost = (s1[i - 1] != s2[j - 1]);
            d[i][j] = min(d[i - 1][j] + 1,
                           d[i][j - 1] + 1,
                           d[i - 1][j - 1] + cost);
        }
    }

    int result = d[s1len][s2len];

    for (size_t i = 0; i <= s1len; i++)
        free(d[i]);
    free(d);

    return result;
}

int main() {
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    int distance = levenshtein(s1, s2);

    printf("Distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);

    return 0;
}