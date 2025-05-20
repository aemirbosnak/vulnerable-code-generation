//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to return the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a distance matrix
    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *) malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;

    // Calculate distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // Check for similarity
            dp[i][j] = min(dp[i - 1][j] + 1,      // Deletion
                           dp[i][j - 1] + 1,      // Insertion
                           dp[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Store the distance result
    int distance = dp[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return distance;
}

// Main function to interact with users
int main() {
    char str1[100], str2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character

    // Calculate the Levenshtein Distance
    int distance = levenshtein_distance(str1, str2);
    
    // Present results to the user
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
  
    // Giving a brief notion about the importance of the distance
    if (distance == 0) {
        printf("These strings are identical!\n");
    } else if (distance <= 2) {
        printf("The strings are quite similar.\n");
    } else {
        printf("The strings are quite different.\n");
    }

    printf("Thank you for using the Levenshtein Distance Calculator.\n");
    return 0;
}