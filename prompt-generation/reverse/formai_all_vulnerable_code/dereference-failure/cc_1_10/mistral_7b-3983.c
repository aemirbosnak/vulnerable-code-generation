//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 256
#define MATRIX_SIZE(x, y) (sizeof(int) * x * y)

typedef struct {
    char str[MAX_CHAR];
    int len;
} FuturisticString;

void levenshtein_distance(FuturisticString str1, FuturisticString str2, int **matrix) {
    int i, j, cost, min;

    for (i = 0; i <= str1.len; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= str2.len; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= str1.len; i++) {
        for (j = 1; j <= str2.len; j++) {
            cost = (str1.str[i - 1] == str2.str[j - 1]) ? 0 : 1;

            matrix[i][j] =
                (matrix[i - 1][j] < matrix[i][j - 1] && matrix[i - 1][j] <= matrix[i][j - 1] + cost) ? matrix[i - 1][j] :
                (matrix[i][j - 1] < matrix[i - 1][j] && matrix[i][j - 1] <= matrix[i - 1][j] + cost) ? matrix[i][j - 1] : matrix[i - 1][j] + cost;
        }
    }
}

int main(int argc, char *argv[]) {
    FuturisticString str1 = {"Futuristic", 8};
    FuturisticString str2 = {"Programming", 11};
    int **matrix = calloc(strlen(argv[1]) + 1, sizeof(int *)), **temp;

    for (int i = 0; i <= str1.len; i++) {
        matrix[i] = calloc(str2.len + 1, sizeof(int));
    }

    levenshtein_distance(str1, str2, matrix);

    printf("Levenshtein Distance: %d\n", matrix[str1.len][str2.len]);

    for (int i = 0; i <= str1.len; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}