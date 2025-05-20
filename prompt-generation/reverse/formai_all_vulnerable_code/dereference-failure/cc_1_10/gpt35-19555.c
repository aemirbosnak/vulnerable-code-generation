//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y) {
        if (x < z) {
            return x;
        } else {
            return z;
        }
    } else {
        if (y < z) {
            return y;
        } else {
            return z;
        }
    }
}

int levenshtein(char *s, char *t) {
    int s_len = strlen(s), t_len = strlen(t);
    int **matrix = (int **)malloc((s_len + 1) * sizeof(int *));
    for (int i = 0; i <= s_len; i++) {
        matrix[i] = (int *)malloc((t_len + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j <= t_len; j++) {
        matrix[0][j] = j;
    }

    for (int j = 1; j <= t_len; j++) {
        for (int i = 1; i <= s_len; i++) {
            if (s[i - 1] == t[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + 1);
            }
        }
    }

    int result = matrix[s_len][t_len];
    for (int i = 0; i <= s_len; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    int distance = levenshtein(str1, str2);
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}