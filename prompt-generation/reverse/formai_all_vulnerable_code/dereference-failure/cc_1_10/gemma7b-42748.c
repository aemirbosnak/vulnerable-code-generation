//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Define the board structure
typedef struct Board
{
    int **cells;
    int turn;
} Board;

// Function to initialize the board
Board *initializeBoard()
{
    Board *board = malloc(sizeof(Board));
    board->cells = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->cells[i] = malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->cells[i][j] = 0;
        }
    }
    board->turn = 1;
    return board;
}

// Function to place a mark on the board
void placeMark(Board *board, int x, int y)
{
    if (board->cells[x][y] == 0)
    {
        board->cells[x][y] = board->turn;
    }
}

// Function to check if the player has won
int hasWon(Board *board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->cells[0][i] == player && board->cells[1][i] == player && board->cells[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->cells[j][0] == player && board->cells[j][1] == player && board->cells[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board->cells[0][0] == player && board->cells[1][1] == player && board->cells[2][2] == player)
    {
        return 1;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

// Function to get the AI's move
int getAIMove(Board *board)
{
    // Calculate the probability of each move
    int moveProbabilities[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board->cells[i][j] == 0)
            {
                moveProbabilities[i * BOARD_SIZE + j] = calculateMoveProbability(board, i, j);
            }
        }
    }

    // Choose the move with the highest probability
    int move = moveProbabilities[rand() % 9];
    return move;
}

// Function to calculate the probability of a move
int calculateMoveProbability(Board *board, int x, int y)
{
    // Calculate the number of winning moves for the player
    int numWinningMoves = calculateNumWinningMoves(board, x, y);

    // Calculate the number of moves that the player can make
    int numAvailableMoves = calculateNumAvailableMoves(board);

    // Return the probability of the move
    return numWinningMoves / numAvailableMoves;
}

// Function to calculate the number of winning moves for a player
int calculateNumWinningMoves(Board *board, int x, int y)
{
    // Check rows
    if (board->cells[0][x] == board->cells[1][x] && board->cells[0][x] == board->cells[2][x] && board->cells[0][x] == board->turn)
    {
        return 1;
    }

    // Check columns
    if (board->cells[x][0] == board->cells[x][1] && board->cells[x][0] == board->cells[x][2] && board->cells[x][0] == board->turn)
    {
        return 1;
    }

    // Check diagonals
    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] == board->turn)
    {
        return 1;
    }

    // Return 0 if there are no winning moves
    return 0;
}

// Function to calculate the number of available moves for a player
int calculateNumAvailableMoves(Board *board)
{
    // Iterate over the board and count the number of empty cells
    int numAvailableMoves = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board->cells[i][j] == 0)
            {
                numAvailableMoves++;
            }
        }
    }

    // Return the number of available moves
    return numAvailableMoves;
}

int main()
{
    Board *board = initializeBoard();

    // Play the game
    while (!hasWon(board, 2) && !hasWon(board, 1))
    {
        placeMark(board, getAIMove(board), 0);
    }

    // Print the winner or draw
    if (hasWon(board, 2))
    {
        printf("Player 2 won!");
    }
    else if (hasWon(board, 1))
    {
        printf("Player 1 won!");
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}