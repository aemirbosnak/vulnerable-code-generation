//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int levenshteinDistance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];
    int i, j, k;
    int *diff = (int*)malloc(sizeof(int) * len1 * len2);

    for (i = 0; i <= len1; i++)
    {
        dp[i][0] = i;
        diff[i] = i;
    }

    for (j = 1; j <= len2; j++)
    {
        dp[0][j] = j;
        diff[0] = j;
    }

    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + (diff[i-1] < diff[i]? diff[i-1] : diff[i]);
            }

            diff[i] = dp[i][j] + 1;
        }
    }

    free(diff);
    return dp[len1][len2];
}

int main()
{
    char s1[] = "kitten";
    char s2[] = "sitting";

    int distance = levenshteinDistance(s1, s2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}