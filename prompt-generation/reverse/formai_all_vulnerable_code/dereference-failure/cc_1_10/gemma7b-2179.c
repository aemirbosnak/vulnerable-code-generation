//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int levenshtein_distance(char *str1, char *str2)
{
    int i, j, d, **distance = NULL;

    distance = (int **)malloc(sizeof(int *) * MAX);
    for (i = 0; i < MAX; i++)
    {
        distance[i] = (int *)malloc(sizeof(int) * MAX);
        for (j = 0; j < MAX; j++)
        {
            distance[i][j] = 0;
        }
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                distance[i][j] = 0;
            }
            else
            {
                distance[i][j] = 1 + distance[i-1][j]
                                 + distance[i][j-1];
            }
        }
    }

    free(distance);

    return distance[MAX-1][MAX-1];
}

int main()
{
    char str1[] = "abcde";
    char str2[] = "abced";

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein Distance between %s and %s is: %d", str1, str2, distance);

    return 0;
}