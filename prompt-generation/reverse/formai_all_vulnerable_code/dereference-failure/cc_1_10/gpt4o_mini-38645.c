//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
int min(int a, int b, int c);
int levenshtein_distance(const char *s1, const char *s2);

// Main function
int main() {
    char str1[100], str2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    
    // Prompt user for inputs
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate and display the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a matrix to store distances
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertion cost
    }

    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Substitution cost
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                           d[i][j - 1] + 1,      // Insertion
                           d[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Store the final distance
    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}