//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *str1, char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }
    for (int i = 0; i <= len_str1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len_str2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = minimum(matrix[i - 1][j] + 1, 
                                    matrix[i][j - 1] + 1, 
                                    matrix[i - 1][j - 1] + cost);
        }
    }
    int distance = matrix[len_str1][len_str2];
    for (int i = 0; i <= len_str1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char string1[100] = "cat";
    char string2[100] = "can";

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", 
            string1, string2, levenshtein_distance(string1, string2));
    return 0;
}