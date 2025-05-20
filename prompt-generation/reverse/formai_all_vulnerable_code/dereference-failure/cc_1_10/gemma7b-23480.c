//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int levenshtein(char *s, char *t)
{
    int m = strlen(s) + 1;
    int n = strlen(t) + 1;
    int d = 0;
    int **distance = (int **)malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        distance[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                distance[i][j] = 0;
            }
            else if (i == 0)
            {
                distance[i][j] = j;
            }
            else if (j == 0)
            {
                distance[i][j] = i;
            }
            else
            {
                distance[i][j] = distance[i - 1][j] + 1;
                if (s[i - 1] == t[j - 1])
                {
                    distance[i][j] = distance[i - 1][j - 1];
                }
            }
        }
    }

    d = distance[m - 1][n - 1];
    free(distance);

    return d;
}

int main()
{
    char *s = "abc";
    char *t = "bcd";

    int distance = levenshtein(s, t);

    printf("The Levenshtein distance between %s and %s is: %d\n", s, t, distance);

    return 0;
}