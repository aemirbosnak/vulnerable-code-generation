//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    return ((a < b)? ((a < c)? a : c) : ((b < c)? b : c));
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int** matrix = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = matrix[i-1][j] + 1;
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
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}