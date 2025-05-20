//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int** matrix = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
        }
    }
    int distance = matrix[len1][len2];
    for (int i = len1 - 1; i >= 0; i--) {
        if (matrix[i][len2] == distance) {
            return distance;
        }
    }
    return -1;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    if (distance!= -1) {
        printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);
    } else {
        printf("Error: Strings are too long.\n");
    }
    return 0;
}