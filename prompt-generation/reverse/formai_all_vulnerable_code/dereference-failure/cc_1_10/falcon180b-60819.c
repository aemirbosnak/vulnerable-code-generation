//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate Levenshtein distance
int levenshteinDistance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** matrix = (int**)malloc(sizeof(int*) * (len1+1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2+1));
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }

    // Initialize first row and column
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = matrix[i-1][j] + 1;
            }
        }
    }

    // Free memory
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshteinDistance(str1, str2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}