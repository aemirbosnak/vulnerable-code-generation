//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 255

void arnold(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = (i + j) % n;
            a[i][j] = a[k][(k + n) % n];
        }
    }
}

void quantize(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (a[i][j] + MAX) / MAX;
        }
    }
}

void embed(int **a, int **w, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = (i + j) % n;
            w[k][(k + n) % n] = a[i][j] & 0x0F;
        }
    }
}

void extract(int **a, int **w, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = (i + j) % n;
            a[i][j] = (w[k][(k + n) % n] & 0x0F) ^ 0x0F;
        }
    }
}

int main()
{
    int n = 8;
    int **a = (int **)malloc(n * n * sizeof(int));
    int **w = (int **)malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % MAX;
            w[i][j] = 0;
        }
    }

    arnold(a, n);
    quantize(a, n);
    embed(a, w, n);

    extract(a, w, n);
    arnold(a, n);
    quantize(a, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != w[i][j])
            {
                printf("Error!\n");
            }
        }
    }

    free(a);
    free(w);

    return 0;
}