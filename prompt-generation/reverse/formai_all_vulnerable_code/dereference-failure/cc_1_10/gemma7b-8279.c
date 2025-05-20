//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1024

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % MAX;
        }
    }

    clock_t start, end;
    start = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += a[i][k] * a[k][j];
            }
            a[i][j] = sum;
        }
    }

    end = clock();

    printf("Time taken: %.2lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}