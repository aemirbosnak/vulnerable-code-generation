//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a metric for measuring the difference between two strings.
// It is commonly used to find the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into another.

// This function calculates the Levenshtein distance between two strings.
int levenshtein_distance(const char *s1, const char *s2)
{
    // Create a matrix to store the Levenshtein distances.
    int **d = malloc((strlen(s1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(s1); i++) {
        d[i] = malloc((strlen(s2) + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i <= strlen(s1); i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= strlen(s2); j++) {
        d[0][j] = j;
    }

    // Calculate the Levenshtein distances.
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1]));
            }
        }
    }
    return d[strlen(s1)][strlen(s2)];
}

// This function returns the minimum of three integers.
int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main()
{
    // Get the two strings from the user.
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the two strings.
     int distance = levenshtein_distance(s1, s2);

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}