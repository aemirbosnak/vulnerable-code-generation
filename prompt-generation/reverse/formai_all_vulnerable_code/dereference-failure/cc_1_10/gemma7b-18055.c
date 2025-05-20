//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            printf("%c ", board[r][c] ? board[r][c] : '.');
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
    char current_player = 'X';

    draw_board(board);

    while(!game_state)
    {
        int row, column;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &column);

        if(board[row][column] || row < 1 || row > 3 || column < 1 || column > 3)
        {
            printf("Invalid move.\n");
            continue;
        }

        board[row][column] = current_player;

        draw_board(board);

        if(current_player == 'X')
        {
            game_state = 1;
            printf("You won!");
        }
        else
        {
            game_state = 2;
            printf("You lost!");
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    free(board);
    return 0;
}