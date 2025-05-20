//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

int levenshtein(char *s1, char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int i, j;

    int **matrix = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (i = 0; i <= len_s1; i++) {
        matrix[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (i = 0; i <= len_s1; i++) {
        for (j = 0; j <= len_s2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            }
            else if (j == 0) {
                matrix[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]);
            }
        }
    }

    int distance = matrix[len_s1][len_s2];

    for (i = 0; i <= len_s1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    int distance = levenshtein(str1, str2);

    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}