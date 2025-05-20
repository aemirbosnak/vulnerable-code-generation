//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if(len1 == 0)
        return len2;
    if(len2 == 0)
        return len1;

    int** dp = (int**)malloc(sizeof(int*) * (len1+1));
    for(int i=0; i<=len1; i++)
        dp[i] = (int*)malloc(sizeof(int) * (len2+1));

    for(int i=0; i<=len1; i++)
        dp[i][0] = i;
    for(int j=1; j<=len2; j++)
        dp[0][j] = j;

    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            int cost = word1[i-1]==word2[j-1] ? 0 : 1;

            dp[i][j] = min(
                    dp[i-1][j] + 1, // deletion
                    dp[i][j-1] + 1, // insertion
                    dp[i-1][j-1] + cost // substitution
                    );
        }
    }

    int distance = dp[len1][len2];

    for(int i=0; i<=len1; i++)
        free(dp[i]);
    free(dp);

    return distance;
}

int main()
{
    char word1[] = "hello";
    char word2[] = "holla";

    int distance = levenshtein_distance(word1, word2);

    printf("The Levenshtein Distance between %s and %s is %d\n", word1, word2, distance);

    return 0;
}