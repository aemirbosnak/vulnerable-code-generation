//Gemma-7B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int table[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    // Place the player's piece in the first position
    table[1][1] = 1;

    // Game loop
    while (1)
    {
        // Get the player's move
        int move = getMove();

        // Check if the move is valid
        if (isValidMove(move, table))
        {
            // Make the move
            makeMove(move, table);

            // Check if the player has won
            if (hasWon(table))
            {
                printf("You have won!");
                break;
            }
        }
        else
        {
            printf("Invalid move.");
        }
    }

    return 0;
}

int getMove()
{
    // Prompt the player for their move
    int move = 0;
    printf("Enter your move: ");
    scanf("%d", &move);

    return move;
}

int isValidMove(int move, int **table)
{
    // Check if the move is within the table bounds
    if (move < 1 || move > 6)
    {
        return 0;
    }

    // Check if the move is occupied
    if (table[move][move] != 0)
    {
        return 0;
    }

    return 1;
}

int makeMove(int move, int **table)
{
    // Place the player's piece in the move
    table[move][move] = 1;
}

int hasWon(int **table)
{
    // Check if the player has won in a row
    for (int i = 1; i <= 6; i++)
    {
        if (table[i][1] == table[i][2] && table[i][1] == table[i][3] && table[i][1] == table[i][4] && table[i][1] == table[i][5] && table[i][1] == table[i][6])
        {
            return 1;
        }
    }

    // Check if the player has won in a column
    for (int j = 1; j <= 6; j++)
    {
        if (table[1][j] == table[2][j] && table[1][j] == table[3][j] && table[1][j] == table[4][j] && table[1][j] == table[5][j] && table[1][j] == table[6][j])
        {
            return 1;
        }
    }

    // Check if the player has won in a diagonal
    if (table[1][1] == table[2][2] && table[1][1] == table[3][3] && table[1][1] == table[4][4] && table[1][1] == table[5][5] && table[1][1] == table[6][6])
    {
        return 1;
    }

    return 0;
}