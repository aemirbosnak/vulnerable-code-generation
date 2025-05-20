//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void initialize(int **arr, int n)
{
    *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        (*arr)[i] = 0;
    }
}

void insert(int **arr, int n, int data)
{
    if (*arr == NULL)
    {
        initialize(arr, n);
    }

    (*arr)[n] = data;
}

void search(int **arr, int n, int data)
{
    for (int i = 0; i < n; i++)
    {
        if ((*arr)[i] == data)
        {
            printf("Data found at index %d\n", i);
            return;
        }
    }

    printf("Data not found\n");
}

int main()
{
    int **arr = NULL;
    int n = 10;

    insert(arr, n, 10);
    insert(arr, n, 20);
    insert(arr, n, 30);
    insert(arr, n, 40);

    search(arr, n, 20);
    search(arr, n, 50);

    return 0;
}