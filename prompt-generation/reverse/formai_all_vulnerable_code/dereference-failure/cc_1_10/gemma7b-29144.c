//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Donald Knuth
#include <stdio.h>

void draw_board(int **board) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int board[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

  int player = 1;
  int game_over = 0;

  while (!game_over) {
    draw_board(board);

    int move_row, move_col;
    printf("Enter move (row, column): ");
    scanf("%d %d", &move_row, &move_col);

    if (board[move_row][move_col] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    board[move_row][move_col] = player;

    if (check_win(board, player) || check_draw(board)) {
      game_over = 1;
    }

    player *= -1;
  }

  draw_board(board);

  printf("Game over! The winner is: ");
  if (board[0][0] == player) {
    printf("Player 1\n");
  } else if (board[2][2] == player) {
    printf("Player 2\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}

int check_win(int **board, int player) {
  // Check rows
  for (int r = 0; r < 3; r++) {
    if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < 3; c++) {
    if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player) {
    return 1;
  }

  // Check draw
  if (board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[2][0] != 0 && board[2][1] != 0 && board[2][2] != 0) {
    return 1;
  }

  return 0;
}

int check_draw(int **board) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] == 0) {
        return 0;
      }
    }
  }

  return 1;
}