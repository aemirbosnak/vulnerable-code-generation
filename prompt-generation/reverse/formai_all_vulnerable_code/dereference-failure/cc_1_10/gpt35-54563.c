//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int **dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;

    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    int result = dp[len1][len2];

    for (int i = 0; i <= len1; i++)
    {
        free(dp[i]);
    }

    free(dp);

    return result;
}

int main()
{
    char s1[100], s2[100];

    printf("Enter string 1: ");
    fgets(s1, 100, stdin);
    s1[strlen(s1) - 1] = '\0';

    printf("Enter string 2: ");
    fgets(s2, 100, stdin);
    s2[strlen(s2) - 1] = '\0';

    int result = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s' is %d", s1, s2, result);
    
    return 0;
}