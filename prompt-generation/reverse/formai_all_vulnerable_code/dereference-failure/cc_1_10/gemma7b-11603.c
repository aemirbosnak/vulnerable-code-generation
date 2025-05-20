//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s, char *t)
{
    int m = strlen(s) + 1;
    int n = strlen(t) + 1;
    int d = 0;

    int **distance = (int *)malloc(m * n * sizeof(int));
    distance[0] = 0;
    distance[1] = 1;

    for (int i = 0; i < n; i++)
    {
        distance[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        distance[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distance[i] > distance[j])
            {
                distance[i] = distance[j] + 1;
            }
        }
    }

    d = distance[m - 1][n - 1];
    free(distance);

    return d;
}

int main()
{
    char *s = "Romeo";
    char *t = "Juliet";

    int distance = levenshtein_distance(s, t);

    printf("The Levenshtein distance between %s and %s is %d.\n", s, t, distance);

    return 0;
}