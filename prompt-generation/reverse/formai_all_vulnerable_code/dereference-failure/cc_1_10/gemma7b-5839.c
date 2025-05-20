//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void percol_sim(int **arr, int n, int r, int c)
{
    if (r >= n || c >= n)
    {
        return;
    }

    int rand_num = rand() % MAX;

    if (arr[r][c] == 0 && rand_num < 5)
    {
        arr[r][c] = 1;
        percol_sim(arr, n, r + 1, c);
        percol_sim(arr, n, r, c + 1);
    }
}

int main()
{
    int n, r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int **arr = (int **)malloc(n * sizeof(int *) + 1);
    for (r = 0; r < n; r++)
    {
        arr[r] = (int *)malloc(c * sizeof(int) + 1);
    }

    percol_sim(arr, n, 0, 0);

    printf("The percolated array is:\n");
    for (r = 0; r < n; r++)
    {
        for (c = 0; c < c; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    return 0;
}