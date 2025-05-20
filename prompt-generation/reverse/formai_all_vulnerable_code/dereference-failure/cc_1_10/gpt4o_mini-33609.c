//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a distance matrix
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Compute the Levenshtein Distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,      // Deletion
                             dist[i][j - 1] + 1,      // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Main function to get user input and display the result
int main() {
    printf("🎉 Welcome to the Levenshtein Distance Calculator! 🎉\n");
    
    char str1[100];
    char str2[100];

    printf("Please enter the first string (max 100 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Please enter the second string (max 100 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("✨ Thank you for using our Levenshtein Distance Calculator! ✨\n");

    return 0;
}