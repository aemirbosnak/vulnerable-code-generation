//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the minimum of three integers
#define MIN(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **matrix = (int **)malloc(sizeof(int *) * (strlen(s1) + 1));
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (strlen(s2) + 1));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = MIN(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[strlen(s1)][strlen(s2)];
}

int main() {
    // Get the two strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}