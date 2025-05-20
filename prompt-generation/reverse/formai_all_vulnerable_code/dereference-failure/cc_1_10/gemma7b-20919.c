//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void watermark(int **a, int n, int m, char *w)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < strlen(w); k++)
            {
                if (a[i][j] == w[k])
                {
                    a[i][j] ^= 0x33;
                }
            }
        }
    }
}

int main()
{
    int **a = NULL;
    int n, m, i, j;
    char *w = "HELLO";

    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("Enter the pixel value: ", &a[i][j]);
        }
    }

    watermark(a, n, m, w);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Pixel value: %d ", a[i][j]);
        }
    }

    return 0;
}