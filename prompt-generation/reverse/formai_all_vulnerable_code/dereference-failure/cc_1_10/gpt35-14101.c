//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshteinDistance(char *s, char *t) {

    int sLength = strlen(s);
    int tLength = strlen(t);

    int **dp = (int **) malloc((sLength + 1) * sizeof(int *));
    for (int i = 0; i < sLength + 1; i++) {
        dp[i] = (int *) malloc((tLength + 1) * sizeof(int));
    }

    for (int i = 0; i < sLength + 1; i++) {
        dp[i][0] = i;
    }

    for (int i = 0; i < tLength + 1; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i < sLength + 1; i++) {
        for (int j = 1; j < tLength + 1; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    int distance = dp[sLength][tLength];

    for (int i = 0; i < sLength + 1; i++) {
        free(dp[i]);
    }
    free(dp);

    return distance;
}

int main() {
    char str1[100], str2[100];

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int dist = levenshteinDistance(str1, str2);

    printf("Levenshtein Distance between %s and %s is %d", str1, str2, dist);

    return 0;
}