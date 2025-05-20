//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein(char *str1, char *str2) {
    // Create a matrix to store the distances.
    int **matrix = malloc(sizeof(int *) * (strlen(str1) + 1));
    for (int i = 0; i < strlen(str1) + 1; i++) {
        matrix[i] = malloc(sizeof(int) * (strlen(str2) + 1));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < strlen(str1) + 1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < strlen(str2) + 1; j++) {
        matrix[0][j] = j;
    }

    // Calculate the distances.
    for (int i = 1; i < strlen(str1) + 1; i++) {
        for (int j = 1; j < strlen(str2) + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
            }
        }
    }

    // Return the distance.
    return matrix[strlen(str1)][strlen(str2)];
}

int main() {
    // Get the two strings from the user.
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance.
    int distance = levenshtein(str1, str2);

    // Print the distance.
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}