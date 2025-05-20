//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int get_min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int **matrix = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        matrix[i] = malloc(sizeof(int) * (m + 1));
    }

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
                matrix[i][j] = get_min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    return matrix[n][m];
}

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}