//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void display_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    int player1_move = 0, player2_move = 0, game_over = 0;

    display_board(board);

    while (!game_over)
    {
        int move;
        printf("Enter your move (1-10): ");
        scanf("%d", &move);

        if (board[move][move] != 0)
        {
            printf("Invalid move!\n");
            continue;
        }

        board[move][move] = player1_move;

        display_board(board);

        player1_move++;

        if (board[move][move] == player1_move)
        {
            game_over = 1;
            printf("Player 1 won!\n");
        }
    }

    display_board(board);

    printf("Game over!\n");

    free(board);

    return 0;
}