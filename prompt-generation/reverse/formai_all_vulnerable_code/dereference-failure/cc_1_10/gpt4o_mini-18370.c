//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int min(int a, int b, int c);
int levenshtein_distance(const char *s1, const char *s2);

int main() {
    // Welcome to the Levenshtein Distance Calculator!
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("===============================================\n");

    // Initialize two strings for comparison
    char str1[100], str2[100];

    // Ask user to enter the first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    // Ask user to enter the second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("Thank you for using the distance calculator! Goodbye!\n");

    return 0;
}

// Function to find minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a distance matrix
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion
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

    int result = distance[len1][len2];

    // Free memory
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}