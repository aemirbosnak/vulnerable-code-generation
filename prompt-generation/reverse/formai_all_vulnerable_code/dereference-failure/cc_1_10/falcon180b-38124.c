//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int **matrix;
    int i, j, k, m, n;
    int cost;
    matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (j = 0; j <= len2; j++) {
            matrix[i][j] = j;
        }
    }
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = matrix[i - 1][j] + 1;
            matrix[i][j] = matrix[i][j - 1] + 1;
            matrix[i][j] = matrix[i - 1][j - 1] + cost;
        }
    }
    return matrix[len1][len2];
}

int main(int argc, char *argv[]) {
    int i, len1, len2;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    if (argc!= 4) {
        printf("Usage: %s string1 string2\n", argv[0]);
        exit(1);
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 > MAX_LENGTH || len2 > MAX_LENGTH) {
        printf("Error: Strings are too long.\n");
        exit(1);
    }

    int distance = levenshteinDistance(str1, str2, len1, len2);
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}