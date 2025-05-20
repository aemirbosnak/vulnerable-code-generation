//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

#define MAX_BOARD_SIZE 3

typedef struct Node {
  int row;
  int col;
  struct Node* next;
} Node;

void makeMove(Node** board, int player, int row, int col) {
  Node* newNode = malloc(sizeof(Node));
  newNode->row = row;
  newNode->col = col;
  newNode->next = NULL;

  if (*board == NULL) {
    *board = newNode;
  } else {
    (*board)->next = newNode;
    *board = newNode;
  }

  board = &((*board)->next);
}

int checkWin(Node* board, int player) {
  // Check rows
  for (int r = 0; r < MAX_BOARD_SIZE; r++) {
    if (board->row == r && board->col == 0) {
      Node* current = board;
      int win = 1;
      while (current) {
        if (current->row != r || current->col != 0) {
          win = 0;
        }
        current = current->next;
      }
      if (win) {
        return 1;
      }
    }
  }

  // Check columns
  for (int c = 0; c < MAX_BOARD_SIZE; c++) {
    if (board->col == c && board->row == 0) {
      Node* current = board;
      int win = 1;
      while (current) {
        if (current->row != 0 || current->col != c) {
          win = 0;
        }
        current = current->next;
      }
      if (win) {
        return 1;
      }
    }
  }

  // Check diagonals
  if (board->row == board->col) {
    Node* current = board;
    int win = 1;
    while (current) {
      if (current->row != current->col) {
        win = 0;
      }
      current = current->next;
    }
    if (win) {
      return 1;
    }
  }

  return 0;
}

int main() {
  Node* board = NULL;
  int player = 1;
  int move = 0;

  // Game loop
  while (!checkWin(board, player) && move < MAX_BOARD_SIZE * MAX_BOARD_SIZE) {
    // Get move from user
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    // Make move
    makeMove(&board, player, row, col);

    // Switch player
    player *= -1;
    move++;
  }

  // Check if player won or it's a draw
  if (checkWin(board, player)) {
    printf("Winner: Player %d\n", player);
  } else {
    printf("Draw!\n");
  }

  return 0;
}