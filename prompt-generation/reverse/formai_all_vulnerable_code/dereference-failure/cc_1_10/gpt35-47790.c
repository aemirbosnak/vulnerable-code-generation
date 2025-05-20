//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int levenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    int **matrix = (int **) malloc((len1+1) * sizeof(int *));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc((len2+1) * sizeof(int));
    }
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
                continue;
            }
            if (j == 0) {
                matrix[i][j] = i;
                continue;
            }
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            }
        }
    }
    int distance = matrix[len1][len2];
    for(i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein distance between %s and %s is %d", str1, str2, distance);
    return 0;
}