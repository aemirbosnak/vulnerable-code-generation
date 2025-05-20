//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int** matrix = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    int distance = matrix[len1][len2];
    for (int i = len1 - 1; i >= 0; i--) {
        if (matrix[i][len2] == distance) {
            return distance;
        }
    }
    for (int j = len2 - 1; j >= 0; j--) {
        if (matrix[len1][j] == distance) {
            return distance;
        }
    }
    return -1;
}

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int distance = levenshtein_distance(s1, s2);
    if (distance == -1) {
        printf("Error: Strings are too long.\n");
    } else {
        printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);
    }
    return 0;
}