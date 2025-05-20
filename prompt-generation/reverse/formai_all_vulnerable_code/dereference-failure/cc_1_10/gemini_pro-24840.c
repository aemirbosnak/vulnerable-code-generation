//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Initialize the matrix
    int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Populate the first row and column
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        matrix[0][j] = j;
    }

    // Populate the rest of the matrix
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(matrix[i - 1][j - 1], fmin(matrix[i][j - 1], matrix[i - 1][j])) + 1;
            }
        }
    }

    // Return the value in the bottom-right corner of the matrix
    int result = matrix[strlen(s1)][strlen(s2)];

    // Free the matrix
    for (int i = 0; i < strlen(s1) + 1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

// Main function
int main() {
    // Get the two strings from the user
    char s1[BUFSIZ], s2[BUFSIZ];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(s1, s2);

    // Print the result
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}