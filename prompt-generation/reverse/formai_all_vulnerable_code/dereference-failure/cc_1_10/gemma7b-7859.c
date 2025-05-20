//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node** createBoard() {
  Node** board = (Node**)malloc(sizeof(Node*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = (Node*)malloc(sizeof(Node));
    board[i]->x = -1;
    board[i]->y = -1;
    board[i]->next = NULL;
  }
  return board;
}

int isBoardFull(Node** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i]->x == -1) {
      return 0;
    }
  }
  return 1;
}

int checkWin(Node** board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i]->x == player && board[i]->y == board[i+1]->y && board[i+2]->y == board[i+2]->y) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j]->x == player && board[j+1]->x == player && board[j+2]->x == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0]->x == player && board[4]->x == player && board[8]->x == player) {
    return 1;
  }

  if (board[2]->x == player && board[4]->x == player && board[6]->x == player) {
    return 1;
  }

  return 0;
}

int main() {
  srand(time(NULL));

  Node** board = createBoard();

  int player = 1;
  int computer_move = 0;

  // Game loop
  while (!isBoardFull(board) && !checkWin(board, player)) {
    // Get the computer's move
    computer_move = rand() % 9;

    // Place the computer's move
    board[computer_move]->x = player;
    board[computer_move]->y = player;

    // Switch player
    player = (player == 1) ? 2 : 1;
  }

  // Check if the player won or if the board is full
  if (checkWin(board, player) == 1) {
    printf("You won!");
  } else if (isBoardFull(board) == 1) {
    printf("It's a draw!");
  } else {
    printf("The computer won!");
  }

  return 0;
}