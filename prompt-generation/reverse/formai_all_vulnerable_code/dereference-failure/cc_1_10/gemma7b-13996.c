//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_DISTANCE 10

int levenshtein_distance(char *a, char *b)
{
    int i, j, d, min_dist = MAX_DISTANCE;
    int **distance = (int **)malloc(sizeof(int *) * (strlen(a) + 1) * (strlen(b) + 1));

    for (i = 0; i <= strlen(a); i++)
    {
        for (j = 0; j <= strlen(b); j++)
        {
            distance[i][j] = MAX_DISTANCE;
        }
    }

    distance[0][0] = 0;

    for (i = 0; i <= strlen(a); i++)
    {
        distance[i][0] = i;
    }

    for (j = 0; j <= strlen(b); j++)
    {
        distance[0][j] = j;
    }

    for (i = 1; i <= strlen(a); i++)
    {
        for (j = 1; j <= strlen(b); j++)
        {
            d = abs(distance[i - 1][j] - distance[i - 1][0]) + abs(distance[0][j - 1] - distance[0][0]) + 1;
            distance[i][j] = d < distance[i][j] ? d : distance[i][j];
        }
    }

    min_dist = distance[strlen(a)][strlen(b)];

    free(distance);

    return min_dist;
}

int main()
{
    char *a = "abc";
    char *b = "bcd";

    int distance = levenshtein_distance(a, b);

    printf("The Levenshtein distance between %s and %s is %d.\n", a, b, distance);

    return 0;
}