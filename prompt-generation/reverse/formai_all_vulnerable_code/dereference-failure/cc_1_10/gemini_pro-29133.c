//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cost;
    int prev_row;
    int prev_col;
} cell_t;

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

int levenshtein_distance(const char *s1, const char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    cell_t **matrix = malloc((s1_len + 1) * sizeof(cell_t *));
    for (int i = 0; i <= s1_len; i++) {
        matrix[i] = malloc((s2_len + 1) * sizeof(cell_t));
    }
    for (int i = 0; i <= s1_len; i++) {
        matrix[i][0].cost = i;
        matrix[i][0].prev_row = i - 1;
        matrix[i][0].prev_col = 0;
    }
    for (int j = 0; j <= s2_len; j++) {
        matrix[0][j].cost = j;
        matrix[0][j].prev_row = 0;
        matrix[0][j].prev_col = j - 1;
    }
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j].cost = min(matrix[i - 1][j].cost + 1, matrix[i][j - 1].cost + 1, matrix[i - 1][j - 1].cost + cost);
            if (matrix[i][j].cost == matrix[i - 1][j].cost + 1) {
                matrix[i][j].prev_row = i - 1;
                matrix[i][j].prev_col = j;
            } else if (matrix[i][j].cost == matrix[i][j - 1].cost + 1) {
                matrix[i][j].prev_row = i;
                matrix[i][j].prev_col = j - 1;
            } else {
                matrix[i][j].prev_row = i - 1;
                matrix[i][j].prev_col = j - 1;
            }
        }
    }
    int distance = matrix[s1_len][s2_len].cost;
    free(matrix[0]);
    free(matrix);
    return distance;
}

int main() {
    char *s1 = "Hello";
    char *s2 = "World";
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
    return 0;
}