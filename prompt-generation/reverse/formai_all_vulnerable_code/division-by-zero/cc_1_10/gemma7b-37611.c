//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, r, c, b;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the number of balls: ");
    scanf("%d", &k);

    int **bingoCard = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        bingoCard[i] = (int *)malloc(m * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            bingoCard[i][j] = 0;
        }
    }

    // Generate balls
    for(l = 0; l < k; l++)
    {
        r = rand() % n;
        c = rand() % m;
        bingoCard[r][c] = 1;
    }

    // Check for bingo
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(bingoCard[i][j] == 5)
            {
                printf("Bingo! Row %d, Column %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No bingo.\n");
    return 0;
}