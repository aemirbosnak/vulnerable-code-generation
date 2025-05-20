//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
//Welcome to the Checkers Game!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Initialize the board
    char **board = (char **)malloc(8 * sizeof(char *));
    for(int i = 0; i < 8; i++)
    {
        board[i] = (char *)malloc(8 * sizeof(char));
        memset(board[i], ' ', 8 * sizeof(char));
    }

    //Add the pieces to the board
    for(int i = 0; i < 8; i += 2)
    {
        board[0][i + 1] = 'O';
        board[1][i] = 'O';
        board[2][i + 1] = 'O';

        board[5][i] = 'X';
        board[6][i + 1] = 'X';
        board[7][i] = 'X';
    }

    printf("Welcome to Checkers! Let's play!\n");
    printf("To move, enter the row (1-8) and column (1-8) of the piece you want to move, followed by the row and column of the space you want to move to.\n");

    //Print the board
    for(int i = 0; i < 8; i++)
    {
        printf(" ");
        for(int j = 0; j < 8; j++)
        {
            printf("+---");
        }
        printf("+\n");

        printf("%d", i + 1);
        for(int j = 0; j < 8; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }

    printf(" ");
    for(int j = 0; j < 8; j++)
    {
        printf("+---");
    }
    printf("+\n");

    //Game loop
    int turn = 0;
    int gameover = 0;
    while(!gameover)
    {
        char player;
        if(turn % 2 == 0)
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }

        printf("Player %c, enter your move:\n", player);

        //Get the user's move
        int row1, col1, row2, col2;
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        //Check if the move is valid
        if((player == 'O' && (row2 > row1 && (row2 - row1 == 1) && (col2 == col1 - 1 || col2 == col1 + 1))) || (player == 'X' && (row2 < row1 && (row1 - row2 == 1) && (col2 == col1 - 1 || col2 == col1 + 1))))
        {
            //Move the piece
            board[row2 - 1][col2 - 1] = player;
            board[row1 - 1][col1 - 1] = ' ';

            //Print the updated board
            for(int i = 0; i < 8; i++)
            {
                printf(" ");
                for(int j = 0; j < 8; j++)
                {
                    printf("+---");
                }
                printf("+\n");

                printf("%d", i + 1);
                for(int j = 0; j < 8; j++)
                {
                    printf("| %c ", board[i][j]);
                }
                printf("|\n");
            }

            printf(" ");
            for(int j = 0; j < 8; j++)
            {
                printf("+---");
            }
            printf("+\n");

            //Check for a winner
            int winner = 0;
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(board[i][j] != player && board[i][j] != ' ')
                    {
                        winner = 1;
                    }
                }
            }

            if(!winner)
            {
                gameover = 1;
                printf("Player %c wins!\n", player);
            }

            //Increment the turn counter
            turn++;
        }
        else
        {
            printf("Invalid move. Try again.\n");
        }
    }

    //Free the memory allocated for the board
    for(int i = 0; i < 8; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}