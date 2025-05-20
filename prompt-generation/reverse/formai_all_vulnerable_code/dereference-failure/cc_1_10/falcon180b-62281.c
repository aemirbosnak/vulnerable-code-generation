//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum suffix of a string which is also a prefix
int maxSuffixPrefix(char *str) {
    int n = strlen(str);
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (str[i]!= str[j]) {
            return j - i;
        }
        i++;
        j--;
    }
    return n;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize the matrix with all 0s
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(m * sizeof(int));
        memset(dp[i], 0, m * sizeof(int));
    }

    // Fill the matrix with the maximum suffix of each row which is also a prefix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = 'a' + i;
            int k = maxSuffixPrefix(&c);
            dp[i][j] = k;
        }
    }

    // Build the LCS string
    char *lcs = (char *)malloc((n + m - 1) * sizeof(char));
    int lcsLen = 0;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0) {
        if (dp[i][j] > 0) {
            lcs[lcsLen++] = 'a' + i;
            i--;
            j--;
        } else if (dp[i][j] == 0) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS string
    printf("Longest Common Substring: ");
    for (int k = lcsLen - 1; k >= 0; k--) {
        printf("%c", lcs[k]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(lcs);

    return 0;
}