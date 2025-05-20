//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void print_matrix(int **matrix, int size) {
    int i, j;

    printf("\nLevenshtein Distance Matrix:\n");
    for (i = 0; i <= size; i++) {
        printf(" %2d", i);
    }

    for (i = 0; i <= size; i++) {
        printf("\n-");
        for (int k = 0; k <= i; k++) {
            printf(" %2d", matrix[i][k]);
        }
    }
}

void levenshtein_distance(char *str1, char *str2, int **matrix, int size) {
    int i, j;

    for (i = 0; i <= size; i++) {
        matrix[i] = (int *)calloc((size + 1), sizeof(int));
        for (j = 0; j <= i; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] =
                    1 + (min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }
}

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

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int size, i;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    size = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);

    int **matrix = (int **)calloc((size + 1), sizeof(int *));
    for (i = 0; i <= size; i++) {
        matrix[i] = (int *)calloc((size + 1), sizeof(int));
    }

    levenshtein_distance(str1, str2, matrix, size);
    print_matrix(matrix, size);

    for (i = 0; i <= size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}