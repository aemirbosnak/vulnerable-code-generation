//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int levenshtein(char *a, char *b)
{
    int m, n, d, i, j, cost;
    m = strlen(a);
    n = strlen(b);
    d = m + n - 2;
    int **distance = (int **)malloc(d * sizeof(int *));
    distance = (int *)malloc(d * m * sizeof(int));

    for (i = 0; i < d; i++)
    {
        distance[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < m; i++)
    {
        distance[0][i] = i;
    }

    for (j = 0; j < n; j++)
    {
        distance[j][0] = j;
    }

    for (i = 1; i < d; i++)
    {
        for (j = 1; j < m; j++)
        {
            cost = abs(distance[j - 1][i - 1] - distance[j - 1][i]) + 1;
            distance[i][j] = distance[i - 1][j] < cost ? distance[i - 1][j] : cost;
        }
    }

    return distance[d][m];
}

int main()
{
    char a[] = "abc";
    char b[] = "bcd";

    int distance = levenshtein(a, b);

    printf("The Levenshtein distance between %s and %s is %d.\n", a, b, distance);

    return 0;
}