//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int min(int a, int b) {
    return (a < b)? a : b;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc(sizeof(int) * (len2 + 1));
        generate_matrix(matrix[i], len2 + 1, len1 + 1);
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
                matrix[i][j] = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
            }
        }
    }
    int distance = matrix[len1][len2];
    free(matrix[0]);
    free(matrix);
    return distance;
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    printf("Enter first string: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance: %d\n", distance);
    return 0;
}