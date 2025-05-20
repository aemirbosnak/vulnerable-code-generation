//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    int d = 0;
    int **distance = (int **)malloc((n + 1) * sizeof(int *) + m + 1);

    for (int i = 0; i <= n; i++)
    {
        distance[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++)
    {
        distance[i][0] = i;
    }

    for (int j = 0; j <= m; j++)
    {
        distance[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            distance[i][j] = 1 + distance[i - 1][j - 1] - (a[i - 1] == b[j - 1] ? 0 : 1);
        }
    }

    d = distance[n][m];

    free(distance);

    return d;
}

int main()
{
    char *a = "abc";
    char *b = "bcd";

    int distance = levenshtein(a, b);

    printf("The Levenshtein distance between %s and %s is: %d\n", a, b, distance);

    return 0;
}