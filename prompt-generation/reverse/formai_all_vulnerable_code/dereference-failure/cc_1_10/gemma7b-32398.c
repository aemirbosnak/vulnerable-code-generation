//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein(char *a, char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    int d = n + m;
    int **distance = (int **)malloc(d * sizeof(int *));
    for (int i = 0; i < d; i++)
    {
        distance[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < n + 1; i++)
    {
        distance[0][i] = i;
    }

    for (int i = 0; i < m + 1; i++)
    {
        distance[i][0] = i;
    }

    for (int i = 1; i < d; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            distance[i][j] = distance[i - 1][j - 1] + 1;
            if (a[j - 1] == b[i - 1])
            {
                distance[i][j] = distance[i - 1][j - 1] - 1;
            }
        }
    }

    int result = distance[d - 1][n];
    free(distance);
    return result;
}

int main()
{
    char *a = "abc";
    char *b = "bcd";

    int distance = levenshtein(a, b);

    printf("The Levenshtein distance between %s and %s is %d.", a, b, distance);

    return 0;
}