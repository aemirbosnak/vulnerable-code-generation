//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Calculate the minimum of three parameters
int min(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

// Calculate the Levenshtein Distance
unsigned int levenshtein(char *s1, char *s2) {
    // Get the lengths of the two input strings
    unsigned int s1_len = strlen(s1);
    unsigned int s2_len = strlen(s2);

    // Create a 2D array to store the edit distances
    unsigned int **matrix = (unsigned int **) malloc((s1_len + 1) * sizeof(unsigned int *));
    for (unsigned int i = 0; i <= s1_len; i++) {
        matrix[i] = (unsigned int *) malloc((s2_len + 1) * sizeof(unsigned int));
    }

    // Initialize the first row and column
    for (unsigned int i = 0; i <= s1_len; i++) {
        matrix[i][0] = i;
    }
    for (unsigned int j = 1; j <= s2_len; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (unsigned int i = 1; i <= s1_len; i++) {
        for (unsigned int j = 1; j <= s2_len; j++) {
            unsigned int substitution_cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + substitution_cost);
        }
    }
    unsigned int result = matrix[s1_len][s2_len];

    // Free the memory allocated for the matrix
    for (unsigned int i = 0; i <= s1_len; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    unsigned int distance = levenshtein(s1, s2);
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}