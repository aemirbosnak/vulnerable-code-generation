//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void calculate_total(int **arr, int n);

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(10 * sizeof(int));
    }

    // Populate the array with sample data
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    // Calculate the total of each row
    calculate_total(arr, n);

    // Print the total of each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}

void calculate_total(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = 0; j < 10; j++)
        {
            total += arr[i][j];
        }
        arr[i][10] = total;
    }
}