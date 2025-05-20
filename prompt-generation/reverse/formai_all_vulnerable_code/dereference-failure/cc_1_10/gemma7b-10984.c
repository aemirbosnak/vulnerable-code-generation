//Gemma-7B DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data mining function
int data_mining(int **arr, int n, int m)
{
    // Calculate the mean of each column
    int i, j, k, sum = 0, avg = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum = 0;
            for (k = 0; k < m; k++)
            {
                sum += arr[i][k];
            }
            avg = sum / m;
            arr[i][j] = avg;
        }
    }

    return 0;
}

int main()
{
    // Create a 2D array
    int **arr = NULL;
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Get the data
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    // Calculate the mean of each column
    data_mining(arr, n, m);

    // Print the output
    printf("The mean of each column is: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}