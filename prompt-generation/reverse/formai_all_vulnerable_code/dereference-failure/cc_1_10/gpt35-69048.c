//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshtein_distance(char *s1, char *s2, int len1, int len2) {
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for(int i = 0; i <= len1; i++)
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));

    for(int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for(int j = 0; j <= len2; j++)
        dp[0][j] = j;

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }

    int res = dp[len1][len2];

    for(int i = 0; i <= len1; i++)
        free(dp[i]);
    free(dp);

    return res;
}

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];

    printf("Enter first string: ");
    fgets(str1, MAX_STR_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, MAX_STR_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance between %s and %s is: %d\n", str1, str2, distance);

    return 0;
}