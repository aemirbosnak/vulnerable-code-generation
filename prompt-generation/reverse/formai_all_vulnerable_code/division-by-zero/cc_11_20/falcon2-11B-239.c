//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k, l;
    int board[100][100];
    int visited[100][100];
    int occupied;
    int counter;
    int size;

    printf("Enter the size of the board: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    occupied = 0;
    counter = 0;
    size = n * n;

    for (k = 0; k < size; k++)
    {
        l = rand() % (size - 1);
        if (board[l / n][l % n] == 0 && visited[l / n][l % n] == 0)
        {
            counter++;
            board[l / n][l % n] = 1;
            visited[l / n][l % n] = 1;

            if (counter == n * n / 2)
            {
                break;
            }

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (board[i][j] == 1 && visited[i][j] == 0)
                    {
                        counter++;
                        board[i][j] = 1;
                        visited[i][j] = 1;

                        if (counter == n * n / 2)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("Percolation simulation finished.\n");
    printf("Occupied sites: %d\n", occupied);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}