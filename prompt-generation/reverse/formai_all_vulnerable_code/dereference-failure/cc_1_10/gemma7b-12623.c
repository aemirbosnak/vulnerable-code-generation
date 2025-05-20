//Gemma-7B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  system("clear");
  srand(time(NULL));

  int n = rand() % 10 + 1;
  printf("Number of players: %d\n", n);

  int **board = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    board[i] = (int*)malloc(n * sizeof(int));
  }

  int turn = 0;
  int game_over = 0;
  while (!game_over) {
    system("clear");
    printf("Turn: %d\n", turn);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    int row = rand() % n;
    int column = rand() % n;
    board[row][column] = 1;

    turn++;
    game_over = check_game_over(board, n);
  }

  system("clear");
  printf("Game Over!\n");

  free(board);
  return;
}

int check_game_over(int **board, int n) {
  for (int i = 0; i < n; i++) {
    if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
      return 1;
    }
  }

  for (int j = 0; j < n; j++) {
    if (board[j][0] == 1 && board[j][1] == 1 && board[j][2] == 1) {
      return 1;
    }
  }

  if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
    return 1;
  }

  return 0;
}