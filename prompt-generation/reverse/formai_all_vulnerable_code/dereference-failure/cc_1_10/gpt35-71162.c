//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Returns the minimum of three integers */
int minimum(int a, int b, int c) {
    if(a < b && a < c)
        return a;
    if(b < c)
        return b;
    return c;
}

/* Calculates the Levenshtein distance between two strings */
int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for(int i = 0; i <= len1; i++) {
        dp[i] = (int *) malloc((len2 + 1) * sizeof(int));
        // Fill first row with increasing values
        dp[i][0] = i;
    }
    for(int j = 0; j <= len2; j++) {
        // Fill first column with increasing values
        dp[0][j] = j;
    }
    
    // Fill rest of the grid
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    int distance = dp[len1][len2];
    
    // Free memory allocated for grid
    for(int i = 0; i <= len1; i++)
        free(dp[i]);
    free(dp);
    
    return distance;
}

int main() {
    char s1[50], s2[50];
    
    printf("Enter first string:");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove newline character
    
    printf("Enter second string:");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove newline character
    
    int distance = levenshtein(s1, s2);
    printf("Levenshtein distance between %s and %s is %d.\n", s1, s2, distance);
    
    return 0;
}