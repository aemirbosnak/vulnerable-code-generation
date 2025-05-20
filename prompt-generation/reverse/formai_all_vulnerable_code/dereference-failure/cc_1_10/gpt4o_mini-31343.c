//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c; // Return the minimum of a, b, c
    }
    return b < c ? b : c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = malloc((len1 + 1) * sizeof(int *)); // Allocate memory for distance matrix

    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int)); // Allocate memory for each row
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) d[i][0] = i; // Deleting all characters from s1
    for (int j = 0; j <= len2; j++) d[0][j] = j; // Inserting all characters from s2

    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Compute cost of substitution
            d[i][j] = min(d[i - 1][j] + 1,          // Deletion
                          d[i][j - 1] + 1,          // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len1][len2]; // The distance is in the bottom-right cell

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance; // Return the calculated distance
}

int main() {
    char str1[256], str2[256]; // Buffers to hold the input strings

    // Get user input
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline

    // Calculate the Levenshtein distance
    int distance = levenshtein(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}