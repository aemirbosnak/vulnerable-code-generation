//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int levenshtein_distance(char* s1, char* s2, int m, int n) {
    if (!s1 || !s2) return -1;

    int** dp = (int**) malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*) malloc((n + 1) * sizeof(int));
        memset(dp[i], 0, (n + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char* str1 = "sunday";
    char* str2 = "saturday";

    int m = strlen(str1);
    int n = strlen(str2);

    int dist = levenshtein_distance(str1, str2, m, n);

    printf("The levenshtein distance between %s and %s is: %d\n", str1, str2, dist);

    return 0;
}