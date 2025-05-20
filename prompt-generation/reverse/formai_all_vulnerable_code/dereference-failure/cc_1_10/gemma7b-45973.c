//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void table(int n)
{
    int i, j, k, l, m, a = 0, b = 0;
    char **p = NULL;
    p = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        p[i] = (char *)malloc(n * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            p[i][j] = ' ';
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a == 0)
            {
                p[i][j] = 'H';
                a++;
            }
            else if (b == 0)
            {
                p[i][j] = 'O';
                b++;
            }
            else
            {
                p[i][j] = 'A' + k;
                k++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", p[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(p[i]);
    }
    free(p);
}

int main()
{
    table(5);
    return 0;
}