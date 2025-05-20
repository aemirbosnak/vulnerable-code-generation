//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1, *str2;
    int len1, len2, i, j, cost;
    int **matrix;

    printf("Enter the first string: ");
    str1 = malloc(100);
    scanf("%s", str1);
    len1 = strlen(str1);

    printf("Enter the second string: ");
    str2 = malloc(100);
    scanf("%s", str2);
    len2 = strlen(str2);

    matrix = malloc((len1 + 1) * sizeof(int *));
    for (i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, matrix[len1][len2]);

    for (i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(str1);
    free(str2);

    return 0;
}