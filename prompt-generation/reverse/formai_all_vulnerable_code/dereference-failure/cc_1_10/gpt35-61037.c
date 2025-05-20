//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate unique random numbers */
int* generateRandomNumbers(int count)
{
    int* numbers = malloc(count * sizeof(int));
    for(int i=0; i<count; i++)
    {
        numbers[i] = rand() % 75 + 1;
        for(int j=0; j<i; j++)
        {
            if(numbers[j] == numbers[i])
            {
                i--;
                break;
            }
        }
    }
    return numbers;
}

int main()
{
    srand(time(NULL));
    
    /* Generate unique random numbers for the Bingo board */
    int bingoBoard[5][5];
    for(int row=0; row<5; row++)
    {
        int* numbers = generateRandomNumbers(5);
        for(int col=0; col<5; col++)
        {
            /* Assign generated numbers to the Bingo board */
            bingoBoard[row][col] = numbers[col];
        }
        free(numbers);
    }
    
    printf("Welcome to the Bingo Simulator!\n");
    printf("Let's start the game!\n");
    
    int callCount = 0;
    
    /* Generate random Bingo calls until a player wins */
    while(1)
    {
        /* Generate a random number between 1 and 75 for the Bingo call */
        int callNumber = rand() % 75 + 1;

        /* Check if the call number matches any number on the Bingo board */
        for(int row=0; row<5; row++)
        {
            for(int col=0; col<5; col++)
            {
                if(bingoBoard[row][col] == callNumber)
                {
                    /* Mark the matching number as called */
                    bingoBoard[row][col] = -1;
                    callCount++;

                    printf("Bingo call number %d!\n", callNumber);
                    
                    /* Check if any player has won */
                    int rowMatch = 0, colMatch = 0, diag1Match = 0, diag2Match = 0;
                    for(int i=0; i<5; i++)
                    {
                        if(bingoBoard[row][i] == -1)
                        {
                            colMatch++;
                        }
                        if(bingoBoard[i][col] == -1)
                        {
                            rowMatch++;
                        }
                        if(bingoBoard[i][i] == -1)
                        {
                            diag1Match++;
                        }
                        if(bingoBoard[i][4-i] == -1)
                        {
                            diag2Match++;
                        }

                        if(colMatch == 5 || rowMatch == 5 || diag1Match == 5 || diag2Match == 5)
                        {
                            printf("Bingo!\n");
                            printf("Total calls: %d\n", callCount);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}