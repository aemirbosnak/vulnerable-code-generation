//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    int cost;
    int prev;
} cell;

void calculateLevenshteinDistance(char *str1, char *str2, int m, int n) {
    int i, j, temp;
    cell **dp;

    dp = (cell **)calloc((m + 1), sizeof(cell *));
    for (i = 0; i <= m; i++) {
        dp[i] = (cell *)calloc((n + 1), sizeof(cell));
    }

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j].cost = j;
            }
            if (j == 0) {
                dp[i][j].cost = i;
            }
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j].cost = dp[i - 1][j - 1].cost;
            } else {
                dp[i][j].cost = 1 + min(dp[i - 1][j].cost, dp[i][j - 1].cost, dp[i - 1][j - 1].cost);
            }
            dp[i][j].prev = (str1[i - 1] == str2[j - 1]) ? dp[i - 1][j - 1].prev :
                           ((dp[i - 1][j].cost < dp[i][j - 1].cost) ? i - 1 : j - 1);
        }
    }

    printf("Levenshtein Distance: %d\n", dp[m][n].cost);

    for (i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    calculateLevenshteinDistance(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));
    return 0;
}