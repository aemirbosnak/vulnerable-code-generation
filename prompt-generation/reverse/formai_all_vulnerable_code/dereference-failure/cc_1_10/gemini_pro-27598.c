//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the edit distances.
    int **matrix = malloc(sizeof(int *) * (strlen(s1) + 1));
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i] = malloc(sizeof(int) * (strlen(s2) + 1));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i <= strlen(s1); i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix.
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, // Deletion
                                matrix[i][j - 1] + 1, // Insertion
                                matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Return the edit distance.
    int distance = matrix[strlen(s1)][strlen(s2)];

    // Free the matrix.
    for (int i = 0; i <= strlen(s1); i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Find the minimum of three integers.
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

// Print the Levenshtein distance between two strings.
void print_levenshtein_distance(const char *s1, const char *s2) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, levenshtein(s1, s2));
}

int main() {
    // Print the Levenshtein distance between some sample strings.
    print_levenshtein_distance("hello", "world");
    print_levenshtein_distance("kitten", "sitting");
    print_levenshtein_distance("frog", "toad");

    return 0;
}