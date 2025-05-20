//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *s1, char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int i, j, cost, **d;

    d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (i = 0; i <= len_s1; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= len_s2; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= len_s1; i++) {
        for (j = 1; j <= len_s2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len_s1][len_s2];

    for (i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}