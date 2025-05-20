//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }
    return min;
}

int levenshtein_distance(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    int **dp = (int **)malloc((s_len + 1) * sizeof(int *));
    for (int i = 0; i <= s_len; i++) {
        dp[i] = (int *)malloc((t_len + 1) * sizeof(int));
    }

    for (int i = 0; i <= s_len; i++) {
        dp[i][0] = i;
    }

    for (int i = 0; i <= t_len; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= s_len; i++) {
        for (int j = 1; j <= t_len; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    int result = dp[s_len][t_len];

    for (int i = 0; i <= s_len; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    
    int result = levenshtein_distance(s1, s2);

    printf("The levenshtein distance between %s and %s is: %d\n", s1, s2, result);

    return 0;
}