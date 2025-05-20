//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include<stdlib.h>
#include<stdio.h>

#define BOARD_SIZE 3

typedef enum { EMPTY, CROSS, CIRCLE } SquareState;

typedef struct {
  SquareState board[BOARD_SIZE][BOARD_SIZE];
  SquareState currentPlayer;
} TicTacToe;

typedef struct {
  int row;
  int col;
} Position;

Position findBestMove(SquareState board[BOARD_SIZE][BOARD_SIZE], SquareState player);

TicTacToe createGame() {
  TicTacToe game;
  int row, col;
  for (row = 0; row < BOARD_SIZE; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      game.board[row][col] = EMPTY;
    }
  }
  game.currentPlayer = CROSS;
  return game;
}

void printBoard(SquareState board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;
  for (row = 0; row < BOARD_SIZE; row++) {
    for (col = 0; col < BOARD_SIZE; col++) {
      switch (board[row][col]) {
        case CROSS:
          printf("X");
          break;
        case CIRCLE:
          printf("O");
          break;
        case EMPTY:
          printf("-");
          break;
      }
    }
    printf("\n");
  }
}

SquareState checkWinner(SquareState board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col, i;
  SquareState winner;

  // Check rows
  for (row = 0; row < BOARD_SIZE; row++) {
    winner = board[row][0];
    for (col = 1; col < BOARD_SIZE; col++) {
      if (board[row][col] != winner) {
        winner = EMPTY;
        break;
      }
    }
    if (winner != EMPTY) {
      return winner;
    }
  }

  // Check columns
  for (col = 0; col < BOARD_SIZE; col++) {
    winner = board[0][col];
    for (row = 1; row < BOARD_SIZE; row++) {
      if (board[row][col] != winner) {
        winner = EMPTY;
        break;
      }
    }
    if (winner != EMPTY) {
      return winner;
    }
  }

  // Check diagonals
  winner = board[0][0];
  for (i = 1; i < BOARD_SIZE; i++) {
    if (board[i][i] != winner) {
      winner = EMPTY;
      break;
    }
  }
  if (winner != EMPTY) {
    return winner;
  }

  winner = board[0][BOARD_SIZE - 1];
  for (i = 1; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - i - 1] != winner) {
      winner = EMPTY;
      break;
    }
  }
  if (winner != EMPTY) {
    return winner;
  }

  return EMPTY;
}

Position getPlayerMove(SquareState board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;
  do {
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
  } while (board[row][col] != EMPTY);
  Position move = { row, col };
  return move;
}

Position getComputerMove(SquareState board[BOARD_SIZE][BOARD_SIZE], SquareState player) {
  return findBestMove(board, player);
}

Position findBestMove(SquareState board[BOARD_SIZE][BOARD_SIZE], SquareState player) {
  // TODO: implement a decentralized algorithm to find the best move
  return getPlayerMove(board);
}

void playGame() {
  TicTacToe game = createGame();
  SquareState winner = EMPTY;
  Position move;

  while (winner == EMPTY) {
    printf("\nCurrent board:\n");
    printBoard(game.board);

    if (game.currentPlayer == CROSS) {
      printf("\nCross's turn.\n");
      move = getPlayerMove(game.board);
    }
    else {
      printf("\nCircle's turn.\n");
      move = getComputerMove(game.board, CIRCLE);
    }
    game.board[move.row][move.col] = game.currentPlayer;

    winner = checkWinner(game.board);
    if (winner != EMPTY) {
      printf("\nCurrent board:\n");
      printBoard(game.board);
      printf("\n%s won!\n", winner == CROSS ? "Cross" : "Circle");
    }
    else {
      game.currentPlayer = game.currentPlayer == CROSS ? CIRCLE : CROSS;
    }
  }
}

int main() {
  playGame();
  return 0;
}