//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, bingo_num, count = 0;
    char **bingo_card = NULL;

    // Allocate memory for the bingo card
    bingo_card = (char **)malloc(10 * sizeof(char *));
    for(i = 0; i < 10; i++)
    {
        bingo_card[i] = (char *)malloc(5 * sizeof(char));
    }

    // Generate bingo numbers
    for(k = 0; k < 10; k++)
    {
        bingo_num = rand() % 25 + 1;
        for(l = 0; l < 10; l++)
        {
            if(bingo_card[l][bingo_num] == 'B')
            {
                bingo_card[l][bingo_num] = 'X';
            }
        }
    }

    // Check for bingo
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(bingo_card[i][j] == 'X' && count == 0)
            {
                count = 1;
                printf("Bingo!\n");
            }
        }
    }

    // Free memory
    for(i = 0; i < 10; i++)
    {
        free(bingo_card[i]);
    }
    free(bingo_card);

    return 0;
}