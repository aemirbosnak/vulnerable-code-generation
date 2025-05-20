//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

int levenshtein(char *s, char *t)
{
    int l = strlen(s) + 1;
    int m = strlen(t) + 1;
    int d = 0;

    int **distance = (int *)malloc(l * m * sizeof(int));
    distance = memset(distance, 0, l * m * sizeof(int));

    distance[0] = m;
    distance[m] = l;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
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

    d = distance[l - 1][m - 1];

    free(distance);

    return d;
}

int main()
{
    char *s = "abc";
    char *t = "bcd";

    int distance = levenshtein(s, t);

    printf("The distance between %s and %s is %d.\n", s, t, distance);

    return 0;
}