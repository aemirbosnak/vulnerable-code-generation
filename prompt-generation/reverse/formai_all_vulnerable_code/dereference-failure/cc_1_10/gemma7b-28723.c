//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **a = NULL;
    char **b = NULL;
    int i, j, k, l = 0;

    a = (char **)malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        a[i] = (char *)malloc(10 * sizeof(char));
    }

    b = (char **)malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        b[i] = (char *)malloc(10 * sizeof(char));
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            a[i][j] = 'a' + l;
            b[i][j] = 'a' + l;
            l++;
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}