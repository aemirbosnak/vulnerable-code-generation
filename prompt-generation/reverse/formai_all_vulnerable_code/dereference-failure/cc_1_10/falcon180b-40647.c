//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

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

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_matrix(char *s1, char *s2, int **matrix, int n, int m) {
    for (int i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int **matrix = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (m + 1));
    }
    generate_matrix(s1, s2, matrix, n, m);
    int distance = matrix[n][m];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i]!= s2[j]) {
                matrix[i][j] = matrix[i + 1][j + 1] + 1;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);
    return 0;
}