//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1, *str2;
    int len1, len2;
    int **matrix;
    int i, j;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    matrix = (int **)malloc(sizeof(int *) * (len1 + 1));

    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    // Initialize the first row and column of the matrix
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill the remaining cells of the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 +
                    fmin(matrix[i - 1][j - 1],
                        fmin(matrix[i][j - 1], matrix[i - 1][j]));
            }
        }
    }

    // Print the Levenshtein distance
    printf("Levenshtein distance: %d\n", matrix[len1][len2]);

    // Free the memory allocated for the matrix
    for (i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}