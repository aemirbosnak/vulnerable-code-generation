//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    }
    return (b < c) ? b : c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    int **d = malloc((len_s1 + 1) * sizeof(int *));
    
    // Allocate memory for distance matrix
    for (size_t i = 0; i <= len_s1; i++) {
        d[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize distance matrix
    for (size_t i = 0; i <= len_s1; i++) d[i][0] = i;
    for (size_t j = 0; j <= len_s2; j++) d[0][j] = j;

    // Compute the Levenshtein distance
    for (size_t i = 1; i <= len_s1; i++) {
        for (size_t j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    // Free allocated memory
    for (size_t i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Main function to demonstrate Levenshtein distance calculation
int main() {
    char str1[100], str2[100];

    // Input two strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Output the result
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    
    return 0;
}