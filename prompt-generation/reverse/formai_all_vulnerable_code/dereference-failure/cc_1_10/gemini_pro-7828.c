//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance function
int levenshtein(char *s1, char *s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    // Create a matrix to store the Levenshtein distances
    int matrix[s1len + 1][s2len + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= s1len; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= s2len; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i <= s1len; i++) {
        for (int j = 1; j <= s2len; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int deletion = matrix[i - 1][j] + 1;
                int insertion = matrix[i][j - 1] + 1;
                int substitution = matrix[i - 1][j - 1] + 1;

                matrix[i][j] = fmin(deletion, fmin(insertion, substitution));
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[s1len][s2len];
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided two strings
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Get the two strings from the user
    char *s1 = argv[1];
    char *s2 = argv[2];

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}