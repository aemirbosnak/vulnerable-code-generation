//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    else if (b <= a && b <= c) {
        return b;
    }
    else {
        return c;
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        matrix[0][j] = j;
    }
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            int substitution_cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,
                                matrix[i][j - 1] + 1,
                                matrix[i - 1][j - 1] + substitution_cost);
        }
    }
    int result = matrix[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main() {
    char *s1 = "Glimmer";
    char *s2 = "Glamor";

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, levenshtein_distance(s1, s2));
    return 0;
}