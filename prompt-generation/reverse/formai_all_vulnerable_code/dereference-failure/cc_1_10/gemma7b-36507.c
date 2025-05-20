//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

// Define the tic tac toe board structure
typedef struct Board
{
    int **board;
    int current_player;
    int game_status;
} Board;

// Function to initialize the tic tac toe board
void initialize_board(Board *board)
{
    board->board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->board[i] = malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->board[i][j] = 0;
        }
    }

    board->current_player = PLAYER_X;
    board->game_status = 0;
}

// Function to play a turn
void play_turn(Board *board)
{
    int row, column;

    // Get the player's move
    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &column);

    // Check if the move is valid
    if (board->board[row][column] != 0)
    {
        printf("Invalid move.\n");
        return;
    }

    // Make the move
    board->board[row][column] = board->current_player;

    // Check if the player has won
    if (check_win(board, board->current_player))
    {
        board->game_status = 1;
        printf("Congratulations! You have won!\n");
    }

    // Check if the board is full
    else if (board->board[0][0] == board->board[0][1] && board->board[0][0] == board->board[0][2] || board->board[1][0] == board->board[1][1] && board->board[1][0] == board->board[1][2] || board->board[2][0] == board->board[2][1] && board->board[2][0] == board->board[2][2])
    {
        board->game_status = 2;
        printf("It's a draw!\n");
    }

    // Switch to the next player
    board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

// Function to check if the player has won
int check_win(Board *board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->board[i][0] == player && board->board[i][1] == player && board->board[i][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->board[0][j] == player && board->board[1][j] == player && board->board[2][j] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player)
    {
        return 1;
    }

    // Check if the board is full
    if (board->board[0][0] == board->board[0][1] && board->board[0][0] == board->board[0][2] || board->board[1][0] == board->board[1][1] && board->board[1][0] == board->board[1][2] || board->board[2][0] == board->board[2][1] && board->board[2][0] == board->board[2][2])
    {
        return 2;
    }

    return 0;
}

int main()
{
    Board board;

    initialize_board(&board);

    while (!board.game_status)
    {
        play_turn(&board);
    }

    return 0;
}