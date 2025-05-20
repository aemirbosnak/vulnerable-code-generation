//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int calculateLevenshteinDistance(const char* str1, const char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Create a table to store the distance between two substrings
    int** dp = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    
    // Fill in the table
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            dp[i][j] = dp[i][j] < (dp[i - 1][j] + 1)? dp[i][j] : dp[i - 1][j];
        }
    }
    
    // Return the distance
    return dp[m][n];
}

// Function to get user input
void getInput() {
    printf("Enter the first string: ");
    char str1[100];
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Enter the second string: ");
    char str2[100];
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    // Call the function to calculate the distance
    int distance = calculateLevenshteinDistance(str1, str2);
    
    // Print the result
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);
}

// Main function
int main() {
    getInput();
    return 0;
}