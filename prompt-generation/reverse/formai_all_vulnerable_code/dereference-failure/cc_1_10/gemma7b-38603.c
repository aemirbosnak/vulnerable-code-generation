//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levshtein(const char *a, const char *b)
{
    int l = strlen(a);
    int m = strlen(b);
    int d = (l + m) / 2;
    int **distance = (int **)malloc(sizeof(int *) * d);
    for (int i = 0; i < d; i++)
    {
        distance[i] = (int *)malloc(sizeof(int) * (l + 1));
        for (int j = 0; j <= l; j++)
        {
            distance[i][j] = -1;
        }
    }

    distance[0][0] = 0;
    for (int i = 0; i < m; i++)
    {
        distance[0][i] = i;
    }
    for (int i = 0; i < l; i++)
    {
        distance[i][0] = i;
    }

    for (int i = 1; i < d; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                distance[i][j] = distance[i - 1][k] + 1;
                if (a[j - 1] == b[k - 1])
                {
                    distance[i][j] = distance[i - 1][k] - 1;
                }
            }
        }
    }

    int result = distance[d - 1][l];
    free(distance);
    return result;
}

int main()
{
    const char *a = "abc";
    const char *b = "bcd";

    int distance = levshtein(a, b);

    printf("The Levenshtein distance between %s and %s is %d.\n", a, b, distance);

    return 0;
}