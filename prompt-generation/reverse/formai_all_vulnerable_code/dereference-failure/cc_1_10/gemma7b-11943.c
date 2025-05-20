//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

int levenshtein(const char *a, const char *b)
{
    int m = strlen(a) + 1;
    int n = strlen(b) + 1;
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
                distance[i][j] = distance[i - 1][j] + distance[i][j - 1] + 1;
            }
        }
    }

    free(distance);

    return distance[m - 1][n - 1];
}

int main()
{
    const char *a = "Romeo";
    const char *b = "Juliet";

    int distance = levenshtein(a, b);

    printf("The Levenshtein distance between %s and %s is %d.\n", a, b, distance);

    return 0;
}