//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_board(int **board);
int check_board(int **board);
void make_move(int **board, int player);

int main()
{
    int **board = NULL;
    int player = 1;
    int game_over = 0;

    // Allocate memory for the board
    board = (int **)malloc(6 * sizeof(int *));
    for (int i = 0; i < 6; i++)
    {
        board[i] = (int *)malloc(7 * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = 0;
        }
    }

    // Start the game loop
    while (!game_over)
    {
        // Draw the board
        draw_board(board);

        // Make the move
        make_move(board, player);

        // Check if the game is over
        game_over = check_board(board);

        // Switch players
        player *= -1;
    }

    // Draw the board one last time
    draw_board(board);

    // Free the memory
    for (int i = 0; i < 6; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

void draw_board(int **board)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_board(int **board)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] != 0)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 7; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] == board[3][j] && board[0][j] != 0)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] != 0)
    {
        return 1;
    }

    // If all checks fail, the game is not over
    return 0;
}

void make_move(int **board, int player)
{
    int move = -1;

    // Get the move from the player
    printf("Enter your move (1-7): ");
    scanf("%d", &move);

    // Validate the move
    if (move < 1 || move > 7)
    {
        printf("Invalid move.\n");
        return;
    }

    // Make the move
    board[move - 1][0] = player;
}