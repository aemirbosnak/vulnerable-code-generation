//FormAI DATASET v1.0 Category: Memory management ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int** arr; // declare a double pointer
    int n_rows, n_cols; // declare the number of rows and columns

    printf("Enter the number of rows: ");
    scanf("%d", &n_rows);

    printf("Enter the number of columns: ");
    scanf("%d", &n_cols);

    // allocate memory for the rows
    arr = (int**)malloc(n_rows * sizeof(int*));

    // check if allocation was successful
    if (arr == NULL) 
    {
        printf("Memory allocation failed!");
        return 0;
    }

    // allocate memory for the columns
    for (int i = 0; i < n_rows; i++)
    {
        arr[i] = (int*)malloc(n_cols * sizeof(int));

        // check if allocation was successful
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed!");
            return 0;
        }
    }
    
    // assign some values to the array
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            arr[i][j] = i+j;
        }
    }

    // print the array
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // free the memory allocated for the rows
    for (int i = 0; i < n_rows; i++)
    {
        free(arr[i]);
    }

    // free the memory allocated for the columns
    free(arr);

    return 0;
}