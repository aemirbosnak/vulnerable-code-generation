//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b) {
    return a < b? a : b;
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** matrix = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2 + 1));
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
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + 1;
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return matrix[len1][len2];
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}