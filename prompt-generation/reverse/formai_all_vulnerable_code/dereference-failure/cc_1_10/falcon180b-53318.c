//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void printMatrix(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int levenshteinDistance(char *str1, char *str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * size1);
    for (int i = 0; i < size1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size2);
    }
    for (int i = 0; i < size1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < size2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    return matrix[size1 - 1][size2 - 1];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}