//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))

int levenshteinDistance(char *s1, char *s2)
{
    int i, j, len1 = strlen(s1), len2 = strlen(s2);
    int cost = 0;
    int *prev = (int *)malloc(sizeof(int)*(len2+1));
    int *curr = (int *)malloc(sizeof(int)*(len2+1));

    for (i = 0; i <= len2; i++) 
        prev[i] = i;

    for (i = 0; i < len1; i++) 
    {
        curr[0] = i + 1;
        for (j = 0; j < len2; j++) 
        {
            cost = (s1[i] != s2[j]);

            curr[j+1] = max(max(curr[j], prev[j+1]) + 1, prev[j] + cost);
        }

        memcpy(prev, curr, sizeof(int)*(len2+1));
    }

    cost = curr[len2];

    free(prev);
    free(curr);

    return cost;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("The minimum number of edits (Levenshtein distance) required to convert \"%s\" to \"%s\" is: %d\n", str1, str2, levenshteinDistance(str1, str2));
  
    return 0;
}