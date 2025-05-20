//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    int i, j, k, l, n, m;
    char **arr = NULL;
    char **brr = NULL;
    char **csr = NULL;

    n = 5;
    m = 3;

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    brr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        brr[i] = (char *)malloc(m * sizeof(char));
    }

    csr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        csr[i] = (char *)malloc(m * sizeof(char));
    }

    // Populate the arrays
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 'a' + i + j;
            brr[i][j] = 'A' + i + j;
            csr[i][j] = '!' + i + j;
        }
    }

    // Analyze the arrays
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
            printf("%c ", brr[i][j]);
            printf("%c ", csr[i][j]);
            printf("\n");
        }
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
        free(brr[i]);
        free(csr[i]);
    }
    free(arr);
    free(brr);
    free(csr);

    return 0;
}