//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void print_matrix(int** matrix, int len1, int len2) {
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
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
    char* str1 = "kitten";
    char* str2 = "sitting";

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}