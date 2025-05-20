//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int decentralizedLevenshtein(char* s, char* t, int n, int m, int** dp) {
    // check if we've already calculated the edit distance
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    
    // if the strings are empty, the edit distance is the length of the other string
    if (n == 0) {
        dp[n][m] = m;
        return m;
    }
    if (m == 0) {
        dp[n][m] = n;
        return n;
    }
    
    // if the last letters of the strings are the same, no edit is needed
    if (s[n-1] == t[m-1]) {
        dp[n][m] = decentralizedLevenshtein(s, t, n-1, m-1, dp);
        return dp[n][m];
    }
    
    // compute the edit distance recursively
    int ins = 1 + decentralizedLevenshtein(s, t, n, m-1, dp);    // insert
    int del = 1 + decentralizedLevenshtein(s, t, n-1, m, dp);    // delete
    int rep = 1 + decentralizedLevenshtein(s, t, n-1, m-1, dp);  // replace
    
    // store the minimum edit distance in the dp matrix and return it
    dp[n][m] = min(ins, del, rep);
    return dp[n][m];
}

int main() {
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);
    
    int n = strlen(s);
    int m = strlen(t);
    
    // initialize the dp matrix with -1
    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((m+1) * sizeof(int));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    
    // call the decentralizedLevenshtein function to compute the edit distance
    int dist = decentralizedLevenshtein(s, t, n, m, dp);
    
    printf("The Levenshtein distance between %s and %s is %d.\n", s, t, dist);
    
    // free the dp matrix
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return 0;
}