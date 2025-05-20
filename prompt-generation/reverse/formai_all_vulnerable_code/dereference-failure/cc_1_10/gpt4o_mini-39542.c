//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a distance matrix
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deleting all characters
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Inserting all characters
    }

    // Compute the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the Levenshtein distance
    int levenshteinDist = distance[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return levenshteinDist;
}

// Main function to take user input and display the distance
int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove the newline character

    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove the newline character

    int distance = levenshteinDistance(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", s1, s2, distance);

    return 0;
}