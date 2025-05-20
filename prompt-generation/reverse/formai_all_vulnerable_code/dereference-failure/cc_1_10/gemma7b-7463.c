//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void percolat(int **arr, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = 2;
                if (i > 0)
                    arr[i - 1][j] = 2;
                if (j > 0)
                    arr[i][j - 1] = 2;
            }
        }
    }
}

int main()
{
    int **arr;
    arr = (int **)malloc(MAX_ROWS * sizeof(int *));
    for (int i = 0; i < MAX_ROWS; i++)
    {
        arr[i] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("Enter the number of occupied cells: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int row, col;
        printf("Enter the row number: ");
        scanf("%d", &row);
        printf("Enter the column number: ");
        scanf("%d", &col);

        arr[row][col] = 1;
    }

    percolat(arr, r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}