//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *str1, int len1, char *str2, int len2) {
    int **matrix = malloc(sizeof(int*) * (len1+1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc(sizeof(int) * (len2+1));
    }

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost;
            if (str1[i-1] == str2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = minimum(matrix[i-1][j] + 1, // deletion
                                    matrix[i][j-1] + 1, // insertion
                                    matrix[i-1][j-1] + cost); // substitution
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
    char *str1 = "hello";
    char *str2 = "world";
    int distance = levenshtein_distance(str1, strlen(str1), str2, strlen(str2));
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}