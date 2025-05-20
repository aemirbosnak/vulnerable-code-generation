//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a 2D array to store distances
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++)
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));

    // Initialize the first column and the first row of the DP table
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i; // Deletion cost
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j; // Insertion cost

    // Fill the DP table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // Match cost
            dp[i][j] = min(dp[i - 1][j] + 1,  // Deletion
                           dp[i][j - 1] + 1,  // Insertion
                           dp[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Store the result, clean up and return
    int distance = dp[len1][len2];
    for (int i = 0; i <= len1; i++)
        free(dp[i]); // Free each row
    free(dp); // Free the row pointers
    return distance;
}

// Function to read a string from user input
void read_string(char *buffer, int size) {
    printf("Input: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Strip newline character
}

// Main function to execute the program
int main() {
    const int max_length = 100; // Define max string length
    char str1[max_length];
    char str2[max_length];

    // Reading the first string
    printf("Enter the first string (max %d characters): ", max_length - 1);
    read_string(str1, max_length);

    // Reading the second string
    printf("Enter the second string (max %d characters): ", max_length - 1);
    read_string(str2, max_length);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0; // Return success
}