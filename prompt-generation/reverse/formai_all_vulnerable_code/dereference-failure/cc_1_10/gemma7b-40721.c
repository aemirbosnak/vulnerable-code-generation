//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void reshape(int **arr, int n, int m)
{
    int i, j, k = 0;
    int **new_arr = (int **)malloc(n * m * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        new_arr[i] = (int *)malloc(m * sizeof(int));
        for(j = 0; j < m; j++)
        {
            new_arr[i][j] = arr[k];
            k++;
        }
    }
    free(arr);
    arr = new_arr;
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);
    int **arr = (int **)malloc(n * m * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Read the data
    printf("Enter the data: ");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    // Reshape the array
    reshape(arr, n, m);

    // Print the reshaped array
    printf("The reshaped array is:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}