//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Calculate the Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2, int len1, int len2) {
    // Create a matrix to store the distances
    int **matrix = (int **)malloc((len1+1)*sizeof(int *));
    for (int i=0; i<=len1; i++) {
        matrix[i] = (int *)malloc((len2+1)*sizeof(int));
    }

    // Initialize the matrix
    for (int i=0; i<=len1; i++) {
        matrix[i][0] = i;
    }
    for (int j=0; j<=len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the distances
    for (int j=1; j<=len2; j++) {
        for (int i=1; i<=len1; i++) {
            if (s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            }
        }
    }

    // Get the distance from the last element in the matrix
    int distance = matrix[len1][len2];

    // Free the memory allocated for the matrix
    for (int i=0; i<=len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // Return the distance
    return distance;
}

int main(void) {
    // Get the strings to compare from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance between the strings
    int distance = levenshteinDistance(s1, s2, strlen(s1), strlen(s2));

    // Print the result
    printf("The Levenshtein distance between %s and %s is %d.\n", s1, s2, distance);

    return 0;
}