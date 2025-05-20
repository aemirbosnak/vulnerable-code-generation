//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
int min(int a, int b, int c);
int levenshtein_distance(const char *s1, const char *s2);

int main() {
    char str1[100], str2[100];

    // User input for the first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove trailing newline

    // User input for the second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove trailing newline

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    // Memory allocation for the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // Deletions
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertions
    }

    // Compute the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Replacement
            d[i][j] = min(d[i - 1][j] + 1,    // Deletion
                          d[i][j - 1] + 1,    // Insertion
                          d[i - 1][j - 1] + cost); // Replacement
        }
    }

    // Get the distance
    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}