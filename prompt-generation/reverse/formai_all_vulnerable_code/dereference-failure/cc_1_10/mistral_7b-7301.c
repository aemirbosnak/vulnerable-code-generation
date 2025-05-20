//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char str[MAX_LENGTH];
    int len;
} word;

void print_matrix(int **matrix, int size1, int size2) {
    int i, j;

    printf("\nLevenshtein Distance Matrix:\n");

    for (i = 0; i <= size1; i++) {
        printf(" %2d", i);
    }

    for (j = 0; j <= size2; j++) {
        printf("\n%2d", j);
        for (i = 0; i <= size1; i++) {
            printf(" %2d", matrix[i][j]);
        }
    }
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    }

    return c;
}

int levenshtein_distance(word str1, word str2) {
    int size1 = str1.len;
    int size2 = str2.len;

    int **matrix = (int **)calloc((size1 + 1), sizeof(int *));
    for (int i = 0; i <= size1; i++) {
        matrix[i] = (int *)calloc((size2 + 1), sizeof(int));
    }

    for (int i = 0; i <= size1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= size2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            int cost = (str1.str[i - 1] == str2.str[j - 1]) ? 0 : 1;

            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    int distance = matrix[size1][size2];

    for (int i = 0; i <= size1; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return distance;
}

int main() {
    word word1 = {"kangaroo", 7};
    word word2 = {"leopard", 6};

    int distance = levenshtein_distance(word1, word2);

    printf("\nThe Levenshtein Distance between %s and %s is %d.\n", word1.str, word2.str, distance);

    return 0;
}