//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int i, j, k, l, m, n;
    char ***c = NULL;
    long long int q, r, t;

    a = (int **)malloc(sizeof(int *) * 10);
    for(i = 0; i < 10; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * 10);
    }

    c = (char ***)malloc(sizeof(char ***) * 10);
    for(i = 0; i < 10; i++)
    {
        c[i] = (char **)malloc(sizeof(char *) * 10);
        for(j = 0; j < 10; j++)
        {
            c[i][j] = (char *)malloc(sizeof(char) * 10);
        }
    }

    q = 123;
    r = 456;
    t = 789;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            a[i][j] = q + r * i + t * j;
        }
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(c);

    return 0;
}