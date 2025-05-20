//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void draw_board(int **board, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n, i, j, player1_move, player2_move;
  int **board;
  char winner;

  printf("Enter the number of players: ");
  scanf("%d", &n);

  board = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    board[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }

  draw_board(board, n);

  player1_move = 1;
  player2_move = 2;

  while (!winner) {
    printf("Enter the row and column of your move (e.g. 1 2): ");
    scanf("%d %d", &i, &j);

    if (board[i][j] != 0) {
      printf("That move is already taken.\n");
      continue;
    }

    board[i][j] = player1_move;

    draw_board(board, n);

    winner = board[i][j] == player1_move ? 'P' : 'N';

    player1_move++;
    player2_move++;
  }

  draw_board(board, n);

  printf("The winner is: %c\n", winner);

  return 0;
}