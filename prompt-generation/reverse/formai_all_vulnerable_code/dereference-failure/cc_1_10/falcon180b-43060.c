//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0 || len2 == 0) {
        return 0;
    }

    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int distance = matrix[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Enter string 1: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    printf("Enter string 2: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}