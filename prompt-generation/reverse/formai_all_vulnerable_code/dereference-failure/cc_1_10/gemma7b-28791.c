//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3

typedef struct Board {
  char **board;
  int size;
  int turn;
} Board;

Board *createBoard(int size) {
  Board *board = malloc(sizeof(Board));
  board->board = malloc(size * size * sizeof(char));
  board->size = size;
  board->turn = 0;
  return board;
}

void printBoard(Board *board) {
  for (int i = 0; i < board->size; i++) {
    for (int j = 0; j < board->size; j++) {
      printf("%c ", board->board[i][j]);
    }
    printf("\n");
  }
}

void placeMove(Board *board, int x, int y) {
  if (board->board[x][y] == ' ' && board->turn % 2 == 0) {
    board->board[x][y] = 'O';
    board->turn++;
  }
}

int checkWin(Board *board) {
  // Check rows
  for (int i = 0; i < board->size; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != ' ') {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < board->size; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != ' ') {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
    return 1;
  }

  // If all moves are made and there is no winner, it's a draw
  return 2;
}

int main() {
  Board *board = createBoard(MAX_SIZE);
  printBoard(board);

  // Play the game
  placeMove(board, 1, 1);
  printBoard(board);

  placeMove(board, 0, 0);
  printBoard(board);

  int winner = checkWin(board);
  switch (winner) {
    case 1:
      printf("Player 2 won!\n");
      break;
    case 2:
      printf("It's a draw.\n");
      break;
  }

  free(board);
  return 0;
}