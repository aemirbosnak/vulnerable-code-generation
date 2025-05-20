//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

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
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
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
    char* s1 = "kitten";
    char* s2 = "sitting";

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}