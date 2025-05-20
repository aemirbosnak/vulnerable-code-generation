//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawBoard(int **board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", board[i][j] == 'X' ? 'X' : 'O');
    }
    printf("\n");
  }
}

int main() {
  int **board = (int **)malloc(3 * sizeof(int *));
  for (int i = 0; i < 3; i++) {
    board[i] = (int *)malloc(3 * sizeof(int));
  }

  int player = 1;
  int gameWon = 0;
  char winner = '\0';

  drawBoard(board);

  while (!gameWon) {
    int row, column;

    printf("Enter row (1-3): ");
    scanf("%d", &row);

    printf("Enter column (1-3): ");
    scanf("%d", &column);

    if (board[row - 1][column - 1] == ' ' && player == 1) {
      board[row - 1][column - 1] = 'X';
      player = 2;
    } else if (board[row - 1][column - 1] == ' ' && player == 2) {
      board[row - 1][column - 1] = 'O';
      player = 1;
    } else {
      printf("Invalid move!\n");
    }

    drawBoard(board);

    // Check if the player won
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
        board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
        board[2][0] == board[2][1] && board[2][0] == board[2][2] ||
        board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
        board[0][1] == board[1][1] && board[0][1] == board[2][1] ||
        board[0][2] == board[1][2] && board[0][2] == board[2][2] ||
        board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
      gameWon = 1;
      winner = 'X';
    } else if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] == 'O' ||
        board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] == 'O' ||
        board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] == 'O') {
      gameWon = 1;
      winner = 'O';
    } else if (board[0][0] == ' ' && board[0][1] == ' ' && board[0][2] == ' ' && board[1][0] == ' ' && board[1][1] == ' ' && board[1][2] == ' ' && board[2][0] == ' ' && board[2][1] == ' ' && board[2][2] == ' ') {
      gameWon = 1;
      winner = 'N';
    }
  }

  drawBoard(board);

  printf("Game over! The winner is: %c\n", winner);

  free(board);

  return 0;
}