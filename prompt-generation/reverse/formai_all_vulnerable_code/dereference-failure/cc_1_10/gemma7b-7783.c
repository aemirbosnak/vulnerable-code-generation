//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <string.h>

int levenshtein(char *str1, char *str2)
{
    int i, j, d, min;
    int **distance = (int **)malloc(sizeof(int *) * (strlen(str1) + 1) * (strlen(str2) + 1));

    for (i = 0; i <= strlen(str1); i++)
    {
        distance[i] = (int *)malloc(sizeof(int) * (strlen(str2) + 1));
        for (j = 0; j <= strlen(str2); j++)
        {
            distance[i][j] = 999;
        }
    }

    distance[0][0] = 0;

    for (i = 0; i < strlen(str1); i++)
    {
        for (j = 0; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j])
            {
                distance[i + 1][j + 1] = distance[i][j];
            }
            else
            {
                d = 1 + distance[i][j];
                distance[i + 1][j + 1] = distance[i][j] < d ? distance[i][j] : d;
            }
        }
    }

    min = distance[strlen(str1)][strlen(str2)];

    free(distance);

    return min;
}

int main()
{
    char str1[] = "banana";
    char str2[] = "apple";

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, distance);

    return 0;
}