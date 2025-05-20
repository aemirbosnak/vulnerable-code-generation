//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levDist(char *str1, int len1, char *str2, int len2) {
    int i, j, cost, **matrix;

    // Allocate memory for the matrix
    matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++)
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));

    // Initialize the first row and column
    for (i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for (j = 0; j <= len2; j++)
        matrix[0][j] = j;

    // Populate the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    // Get the Levenshtein Distance
    int distance = matrix[len1][len2];

    // Free the memory
    for (i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return distance;
}

int main() {
    char str1[100], str2[100];

    // Get the two strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Compute the Levenshtein Distance and display it to the user
    int distance = levDist(str1, strlen(str1), str2, strlen(str2));
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}