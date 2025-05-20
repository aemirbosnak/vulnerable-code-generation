//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **arr, int n, int **dest)
{
    int i, j, k = 0, count = 1, run = 1;
    *dest = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n && arr[i] == arr[j]; j++)
        {
            count++;
            run = 0;
        }

        if (run)
        {
            dest[k++] = arr[i];
        }
        else
        {
            dest[k++] = arr[i] - count * MAX;
            count = 1;
        }
    }

    *dest = realloc(*dest, k * sizeof(int));
}

int main()
{
    int **arr = NULL, n, **dest = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    compress(arr, n, &dest);

    printf("Compressed elements: ");
    for (int i = 0; i < dest[0]; i++)
    {
        printf("%d ", dest[i + 1]);
    }

    printf("\n");

    return 0;
}