//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int n1 = strlen(s1), n2 = strlen(s2);
    int **matrix = (int **)malloc(sizeof(int *) * (n1 + 2));
    for (int i = 0; i <= n1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (n2 + 2));
        for (int j = 0; j <= n2; j++) {
            matrix[i][j] = j;
        }
    }
    for (int i = 1; i <= n1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 1; j <= n2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }
    int result = matrix[n1][n2];
    for (int i = 0; i <= n1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    char *s1 = argv[1];
    char *s2 = argv[2];
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);
    return 0;
}