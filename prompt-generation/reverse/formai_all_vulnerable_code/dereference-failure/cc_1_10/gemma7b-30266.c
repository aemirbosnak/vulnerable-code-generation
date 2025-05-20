//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int levenshtein_distance(char *a, char *b)
{
    int i, j, d, **distance = NULL;

    distance = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        distance[i] = (int *)malloc(MAX * sizeof(int));
        for (j = 0; j < MAX; j++)
        {
            distance[i][j] = -1;
        }
    }

    d = levenshtein_distance_rec(a, b, distance);

    for (i = 0; i < MAX; i++)
    {
        free(distance[i]);
    }
    free(distance);

    return d;
}

int levenshtein_distance_rec(char *a, char *b, int **distance)
{
    int l, m, d, min, **matrix = NULL;

    l = strlen(a);
    m = strlen(b);

    matrix = (int *)malloc((l + 1) * (m + 1) * sizeof(int));
    for (d = 0; d <= l + m; d++)
    {
        matrix[0][d] = d;
    }
    for (d = 0; d <= l; d++)
    {
        matrix[d][0] = d;
    }

    for (d = 1; d <= l; d++)
    {
        for (min = 1; min <= m; min++)
        {
            matrix[d][min] = min + (a[d - 1] == b[min - 1] ? 0 : 1);
        }
    }

    distance[0][0] = matrix[l][m];

    free(matrix);

    return distance[0][0];
}

int main()
{
    char *a = "abc";
    char *b = "bcd";

    int d = levenshtein_distance(a, b);

    printf("Levenshtein distance between %s and %s is %d.\n", a, b, d);

    return 0;
}