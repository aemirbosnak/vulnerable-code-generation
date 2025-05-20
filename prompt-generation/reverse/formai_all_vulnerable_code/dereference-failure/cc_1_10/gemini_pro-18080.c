//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

int levdist(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
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
                int min = ERROR;
                if (min == ERROR || matrix[i - 1][j] < min) {
                    min = matrix[i - 1][j];
                }
                if (min == ERROR || matrix[i][j - 1] < min) {
                    min = matrix[i][j - 1];
                }
                if (min == ERROR || matrix[i - 1][j - 1] < min) {
                    min = matrix[i - 1][j - 1];
                }
                matrix[i][j] = min + 1;
            }
        }
    }
    int result = matrix[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    int distance = levdist(str1, str2);
    if (distance != ERROR) {
        printf("The Levenshtein distance is: %d\n", distance);
    } else {
        printf("An error occurred while calculating the Levenshtein distance.\n");
    }
    return 0;
}