//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int Levenshtein(char *str1, char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int i, j, cost;

    int **matrix = (int**) malloc(sizeof(int*) * (len_str1 + 1));
    for (i = 0; i < len_str1 + 1; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * (len_str2 + 1));
    }

    for (i = 0; i < len_str1 + 1; i++) { 
        matrix[i][0] = i;
    }
    for (j = 0; j < len_str2 + 1; j++) { 
        matrix[0][j] = j; 
    }

    for (i = 1; i < len_str1 + 1; i++) {
        for (j = 1; j < len_str2 + 1; j++) {
            cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + cost);
        }
    }

    int distance = matrix[len_str1][len_str2];

    for (i = 0; i < len_str1 + 1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = Levenshtein(str1, str2);

    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}