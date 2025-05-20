//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = malloc(sizeof(int *) * 3);
    for(int i = 0; i < 3; i++)
    {
        board[i] = malloc(sizeof(int) * 3);
    }

    int game_state = 0;
    int player_turn = 0;
    char player_symbol = 'X';

    draw_board(board);

    while(game_state == 0)
    {
        int row, column;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &column);

        if(board[row][column] == 0 && player_turn == player_symbol - 'X')
        {
            board[row][column] = player_symbol;
            player_turn = (player_turn == 'X') ? 'O' : 'X';
        }
        else
        {
            printf("Invalid move.\n");
        }

        draw_board(board);
    }

    printf("Game over! The winner is: %c", board[0][0] == player_symbol ? player_symbol : 'O');

    free(board);
    return 0;
}