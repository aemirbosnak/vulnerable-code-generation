//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void display(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;

    display(arr, MAX);

    int x = 0, y = 0, target = 9;
    int direction = 0;

    while (arr[x][y] != target)
    {
        switch (direction)
        {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        if (arr[x][y] == target)
        {
            printf("Target found at (%d, %d)\n", x, y);
            break;
        }

        display(arr, MAX);
    }

    return 0;
}