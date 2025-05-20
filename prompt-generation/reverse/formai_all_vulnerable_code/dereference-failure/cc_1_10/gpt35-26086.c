//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int levenshtein_distance(char *s1, char *s2, int m, int n) {
    int **distance = malloc(sizeof(int*) * (m+1));
    for (int i=0; i<=m; i++) {
        distance[i] = malloc(sizeof(int) * (n+1));
    }

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = 1 + minimum(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]);
            }
        }
    }

    int result = distance[m][n];

    for (int i=0; i<=m; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

int main() {

    char s1[] = "kitten";
    char s2[] = "sitting";

    int m = strlen(s1);
    int n = strlen(s2);

    int distance = levenshtein_distance(s1, s2, m, n);

    printf("Levenshtein Distance between %s and %s is %d", s1, s2, distance);

    return 0;
}