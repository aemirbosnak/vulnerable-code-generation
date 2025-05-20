//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings.
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the Levenshtein distances.
    int **matrix = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances for the rest of the matrix.
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance.
    return matrix[strlen(s1)][strlen(s2)];
}

// Print a usage message and exit.
void usage() {
    printf("Usage: levenshtein <string1> <string2>\n");
    exit(1);
}

// Main function.
int main(int argc, char *argv[]) {
    // Check the number of arguments.
    if (argc != 3) {
        usage();
    }

    // Calculate the Levenshtein distance.
    int distance = levenshtein(argv[1], argv[2]);

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", argv[1], argv[2], distance);

    return 0;
}