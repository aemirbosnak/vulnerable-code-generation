//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <math.h>

double levenshtein_distance(char *str1, char *str2)
{
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    double **distance = (double **)malloc((n1 + 1) * sizeof(double *) + (n2 + 1) * sizeof(double));

    for (int i = 0; i <= n1; i++)
    {
        distance[i] = (double *)malloc((n2 + 1) * sizeof(double));
    }

    for (int i = 0; i <= n1; i++)
    {
        distance[i][0] = i;
    }

    for (int j = 0; j <= n2; j++)
    {
        distance[0][j] = j;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            distance[i][j] = fmin(distance[i - 1][j], distance[i][j - 1]) + 1;
        }
    }

    double min_distance = distance[n1][n2];

    free(distance);

    return min_distance;
}

int main()
{
    char str1[] = "abc";
    char str2[] = "bcd";

    double distance = levenshtein_distance(str1, str2);

    printf("The edit distance between %s and %s is %f.\n", str1, str2, distance);

    return 0;
}