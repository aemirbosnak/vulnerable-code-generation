//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the two strings from the user.
    char *str1 = NULL;
    size_t len1 = 0;
    printf("Enter the first string: ");
    getline(&str1, &len1, stdin);

    char *str2 = NULL;
    size_t len2 = 0;
    printf("Enter the second string: ");
    getline(&str2, &len2, stdin);

    // Create a matrix to store the Levenshtein distances.
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances.
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = str1[i - 1] == str2[j - 1] ? 0 : 1;
            matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, matrix[len1][len2]);

    // Free the memory allocated for the matrix.
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Free the memory allocated for the strings.
    free(str1);
    free(str2);

    return 0;
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}