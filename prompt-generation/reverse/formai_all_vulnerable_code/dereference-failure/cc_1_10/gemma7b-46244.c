//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **a = NULL;
    int **b = NULL;
    int r, c, i, j;

    a = malloc(10 * sizeof(char *));
    for(i = 0; i < 10; i++)
    {
        a[i] = malloc(20 * sizeof(char));
    }

    b = malloc(20 * sizeof(int *));
    for(i = 0; i < 20; i++)
    {
        b[i] = malloc(10 * sizeof(int));
    }

    r = 5;
    c = 10;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            a[i][j] = 'a' + i + j;
            b[i][j] = i + j;
        }
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            free(b[i][j]);
        }
        free(a[i]);
    }

    free(b);
    free(a);

    return 0;
}