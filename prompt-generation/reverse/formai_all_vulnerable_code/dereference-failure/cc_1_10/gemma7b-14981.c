//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **arr = (int **)malloc(HEIGHT * sizeof(int *)), i, j, x, y;
    for(i = 0; i < HEIGHT; i++)
    {
        arr[i] = (int *)malloc(WIDTH * sizeof(int));
        for(j = 0; j < WIDTH; j++)
        {
            arr[i][j] = 0;
        }
    }

    x = WIDTH / 2;
    y = HEIGHT / 2;

    // Percolation Simulation
    for(i = 0; i < 1000; i++)
    {
        // Randomly choose a cell
        int row = rand() % HEIGHT;
        int column = rand() % WIDTH;

        // If the cell is not saturated and the sum of its neighbors is greater than the threshold, saturate the cell
        if(arr[row][column] == 0 && (arr[row - 1][column] + arr[row + 1][column] + arr[row][column - 1] + arr[row][column + 1] > 3))
        {
            arr[row][column] = 1;
        }
    }

    // Display the result
    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(i = 0; i < HEIGHT; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}