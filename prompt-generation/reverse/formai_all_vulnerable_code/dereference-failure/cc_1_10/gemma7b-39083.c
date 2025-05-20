//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64

void initializeBoard(int **board);
void displayBoard(int **board);
int movePiece(int **board, int piece_position, int target_position);
int checkMoveValidity(int **board, int piece_position, int target_position);

int main()
{
  int **board = (int **)malloc(sizeof(int *) * BOARD_SIZE);
  initializeBoard(board);

  displayBoard(board);

  movePiece(board, 1, 16);
  movePiece(board, 16, 32);

  displayBoard(board);

  free(board);
  return 0;
}

void initializeBoard(int **board)
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    board[i] = 0;
  }
}

void displayBoard(int **board)
{
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    printf("%d ", board[i]);
  }
  printf("\n");
}

int movePiece(int **board, int piece_position, int target_position)
{
  if (!checkMoveValidity(board, piece_position, target_position))
  {
    return 0;
  }

  board[target_position] = board[piece_position];
  board[piece_position] = 0;

  return 1;
}

int checkMoveValidity(int **board, int piece_position, int target_position)
{
  // Valid move if the target position is empty and the piece is not on the opposite side of the board
  return (board[target_position] == 0) && (piece_position < BOARD_SIZE / 2) ^ (target_position > BOARD_SIZE / 2);
}