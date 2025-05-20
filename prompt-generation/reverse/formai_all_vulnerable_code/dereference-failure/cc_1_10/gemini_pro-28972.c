//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to find the minimum of three values
int min(int a, int b, int c) {
    return fmin(fmin(a, b), c);
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the Levenshtein distances
    int **d = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(s1); i++) {
        d[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= strlen(s1); i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        d[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
            }
        }
    }

    // Return the Levenshtein distance
    return d[strlen(s1)][strlen(s2)];
}

// Function to test the Levenshtein distance calculator
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
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}