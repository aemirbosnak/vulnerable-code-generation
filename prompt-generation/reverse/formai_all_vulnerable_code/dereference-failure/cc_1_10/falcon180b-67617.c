//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    int distance = matrix[len1][len2];
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                distance = matrix[i - 1][j - 1];
                break;
            }
        }
    }
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    printf("Enter first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);
    return 0;
}