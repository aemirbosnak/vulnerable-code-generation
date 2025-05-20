//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int **matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2, strlen(str1), strlen(str2));

    // Print result
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}