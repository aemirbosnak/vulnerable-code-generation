//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int cost;
    int prev;
    int x;
    int y;
} cell;

int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

int levenshtein(char *s1, char *s2) {
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;

    cell **matrix = malloc(sizeof(cell *) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(sizeof(cell) * n);
    }

    for (int i = 0; i < m; i++) {
        matrix[i][0].cost = i;
        matrix[i][0].prev = -1;
        matrix[i][0].x = i - 1;
        matrix[i][0].y = 0;
    }

    for (int j = 0; j < n; j++) {
        matrix[0][j].cost = j;
        matrix[0][j].prev = -1;
        matrix[0][j].x = 0;
        matrix[0][j].y = j - 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;

            int min_cost = min(
                matrix[i - 1][j].cost + 1,  // deletion
                matrix[i][j - 1].cost + 1,  // insertion
                matrix[i - 1][j - 1].cost + cost  // substitution
            );

            matrix[i][j].cost = min_cost;

            if (min_cost == matrix[i - 1][j].cost + 1) {
                matrix[i][j].prev = matrix[i - 1][j].cost;
                matrix[i][j].x = i - 1;
                matrix[i][j].y = j;
            } else if (min_cost == matrix[i][j - 1].cost + 1) {
                matrix[i][j].prev = matrix[i][j - 1].cost;
                matrix[i][j].x = i;
                matrix[i][j].y = j - 1;
            } else {
                matrix[i][j].prev = matrix[i - 1][j - 1].cost;
                matrix[i][j].x = i - 1;
                matrix[i][j].y = j - 1;
            }
        }
    }

    int distance = matrix[m - 1][n - 1].cost;

    free(matrix);

    return distance;
}

int main() {
    char s1[] = "Hello";
    char s2[] = "World";

    int distance = levenshtein(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}