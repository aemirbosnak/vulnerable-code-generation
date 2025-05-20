//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a distance matrix
    int** dist = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                             dist[i][j - 1] + 1,    // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Capture the final distance
    int distance = dist[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Main function to drive the program
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Let's calculate how different two strings are in terms of edit distance.\n\n");

    // Get the first string from user
    char str1[100];
    printf("Enter the first string (max 99 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    // Get the second string from user
    char str2[100];
    printf("Enter the second string (max 99 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    // Calculate the Levenshtein distance
    int distance = levenshteinDistance(str1, str2);

    // Display the results
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("This means that it takes a minimum of %d single-character edits to transform one string into the other.\n", distance);
    printf("Feel free to run the program again with different strings!\n");

    return 0;
}