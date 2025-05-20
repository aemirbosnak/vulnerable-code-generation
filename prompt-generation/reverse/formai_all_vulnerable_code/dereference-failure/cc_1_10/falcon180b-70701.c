//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

void levenshtein_distance(char *s1, char *s2, int **matrix, int n1, int n2) {
    int i, j;
    for (i = 0; i <= n1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= n2; j++) {
        matrix[0][j] = j;
    }
    for (i = 1; i <= n1; i++) {
        for (j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }
}

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
    char s1[MAX_SIZE], s2[MAX_SIZE];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int n1 = strlen(s1), n2 = strlen(s2);
    int **matrix = (int **)malloc(sizeof(int *) * (n1 + 1));
    for (int i = 0; i <= n1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (n2 + 1));
    }
    levenshtein_distance(s1, s2, matrix, n1, n2);
    printf("Levenshtein Distance: %d\n", matrix[n1][n2]);
    for (int i = n1; i >= 0; i--) {
        for (int j = n2; j >= 0; j--) {
            if (i == n1 && j == n2) {
                printf("%c ", s1[i - 1]);
            } else if (i == n1) {
                printf("  ");
            } else if (j == n2) {
                printf("%c ", s2[j - 1]);
            } else if (matrix[i - 1][j] == matrix[i][j - 1]) {
                printf("  ");
            } else if (matrix[i - 1][j] == matrix[i][j - 1] + 1) {
                printf("%c ", s1[i - 1]);
            } else {
                printf("%c ", s2[j - 1]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i <= n1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}