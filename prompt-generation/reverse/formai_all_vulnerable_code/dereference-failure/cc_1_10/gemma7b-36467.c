//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lev_dist(char *a, char *b)
{
    int m = strlen(a);
    int n = strlen(b);
    int d = (m + n) * 2;

    int **dist = (int **)malloc(d * sizeof(int *));
    for (int i = 0; i < d; i++)
    {
        dist[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
        }
    }

    dist[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        dist[0][i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        dist[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = dist[i - 1][j - 1] + 1;
            if (a[i - 1] == b[j - 1])
            {
                dist[i][j] = dist[i - 1][j - 1] - 1;
            }
        }
    }

    int min_dist = dist[m][n];

    free(dist);

    return min_dist;
}

int main()
{
    char *a = "abc";
    char *b = "bcd";

    int dist = lev_dist(a, b);

    printf("The Levenshtein distance between %s and %s is: %d\n", a, b, dist);

    return 0;
}