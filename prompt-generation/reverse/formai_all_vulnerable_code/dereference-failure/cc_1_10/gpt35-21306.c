//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    return (x < y && x < z) ? x : (y < x && y < z) ? y : z;
}

int LevenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int** matrix = (int**)malloc((len1 + 1) * sizeof(int*));

    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc((len2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]) + 1;
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
    char* str1 = "kitten";
    char* str2 = "sitting";

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, LevenshteinDistance(str1, str2));

    return 0;
}