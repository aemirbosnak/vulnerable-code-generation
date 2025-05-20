//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int levenshtein(char *a, char *b)
{
    int i, j, d, min;
    int **distance = (int **)malloc((strlen(a) + 1) * sizeof(int *) + (strlen(b) + 1) * sizeof(int));

    for (i = 0; i <= strlen(a); i++)
    {
        distance[i] = (int *)malloc((strlen(b) + 1) * sizeof(int));
    }

    for (i = 0; i < strlen(a) + 1; i++)
    {
        for (j = 0; j < strlen(b) + 1; j++)
        {
            distance[i][j] = 99;
        }
    }

    distance[0][0] = 0;

    for (i = 0; i < strlen(a) + 1; i++)
    {
        distance[i][0] = i;
    }

    for (j = 0; j < strlen(b) + 1; j++)
    {
        distance[0][j] = j;
    }

    for (i = 1; i <= strlen(a); i++)
    {
        for (j = 1; j <= strlen(b); j++)
        {
            d = abs(distance[i - 1][j] - distance[i - 1][0]) + abs(distance[0][j - 1] - distance[0][0]) + 1;
            distance[i][j] = d;
            if (distance[i][j] < distance[i - 1][j])
            {
                distance[i][j] = distance[i - 1][j];
            }
            if (distance[i][j] < distance[i][j - 1])
            {
                distance[i][j] = distance[i][j - 1];
            }
        }
    }

    min = distance[strlen(a)][strlen(b)];

    free(distance);

    return min;
}

int main()
{
    char a[] = "hello";
    char b[] = "world";

    int distance = levenshtein(a, b);

    printf("The Levenshtein distance between %s and %s is %d.\n", a, b, distance);

    return 0;
}