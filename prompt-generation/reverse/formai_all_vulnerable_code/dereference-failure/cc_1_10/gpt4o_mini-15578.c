//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return -1;
    }

    // Initialize matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            return -1;
        }
    }

    // Fill the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;  // Cost of deletions
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;  // Cost of insertions
    }

    // Compute Levenshtein distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(
                matrix[i - 1][j] + 1,    // Deletion
                matrix[i][j - 1] + 1,    // Insertion
                matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    int distance = matrix[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Main function to demonstrate the usage of the Levenshtein distance function
int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove trailing newline

    int distance = levenshtein_distance(str1, str2);

    if (distance != -1) {
        printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    }

    return 0;
}