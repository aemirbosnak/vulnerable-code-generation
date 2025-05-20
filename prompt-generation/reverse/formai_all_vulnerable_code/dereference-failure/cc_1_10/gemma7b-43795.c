//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **arr, int n)
{
    int i, j, count = 1, flag = 0, prev = arr[0], prev_count = 1;

    for (i = 1; i < n; i++)
    {
        if (prev == arr[i])
        {
            count++;
        }
        else
        {
            if (flag)
            {
                arr[j++] = prev_count;
                prev_count = count;
            }
            prev = arr[i];
            count = 1;
            flag = 1;
        }
    }

    if (flag)
    {
        arr[j++] = prev_count;
    }

    *arr = realloc(*arr, j);
}

int main()
{
    char *arr = NULL;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = malloc(n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%c", &arr[i]);
    }

    compress(&arr, n);

    printf("Compressed array: ");
    for (i = 0; i < *arr; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}