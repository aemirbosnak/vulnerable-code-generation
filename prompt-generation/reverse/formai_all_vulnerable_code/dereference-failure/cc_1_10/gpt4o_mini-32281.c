//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the Levenshtein Distance between two strings
int levenshteinDistance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a matrix to hold the distances
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (size_t i = 0; i <= len1; i++) {
        d[i][0] = i; // Deletion
    }

    for (size_t j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertion
    }

    // Compute the distance
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len1][len2];

    // Free the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main() {
    char str1[100], str2[100];

    // Prompt user for input
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    // Calculate Levenshtein Distance
    int distance = levenshteinDistance(str1, str2);

    // Display the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}