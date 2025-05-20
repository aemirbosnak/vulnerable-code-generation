//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **a = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        a[i] = (int *)malloc(5 * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[0][4] = 5;

    a[1][0] = 6;
    a[1][1] = 7;
    a[1][2] = 8;
    a[1][3] = 9;
    a[1][4] = 10;

    a[2][0] = 11;
    a[2][1] = 12;
    a[2][2] = 13;
    a[2][3] = 14;
    a[2][4] = 15;

    a[3][0] = 16;
    a[3][1] = 17;
    a[3][2] = 18;
    a[3][3] = 19;
    a[3][4] = 20;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < 4; i++)
    {
        free(a[i]);
    }

    free(a);
}