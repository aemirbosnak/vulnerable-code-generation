//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define X 1
#define O 2
#define TIE 3
#define NEITHER 0

typedef struct {
  int player;
  int** board;
} state_t;

int make_move(state_t* state, int player, int x, int y) {
  if (state->board[x][y] != NEITHER) {
    return 0;
  }
  state->board[x][y] = player;
  return 1;
}

int check_winner(state_t* state) {
  int i, j;

  // Check rows
  for (i = 0; i < 3; i++) {
    if (state->board[i][0] == state->board[i][1] &&
        state->board[i][0] == state->board[i][2] &&
        state->board[i][0] != NEITHER) {
      return state->board[i][0];
    }
  }

  // Check columns
  for (i = 0; i < 3; i++) {
    if (state->board[0][i] == state->board[1][i] &&
        state->board[0][i] == state->board[2][i] &&
        state->board[0][i] != NEITHER) {
      return state->board[0][i];
    }
  }

  // Check diagonals
  if (state->board[0][0] == state->board[1][1] &&
      state->board[0][0] == state->board[2][2] &&
      state->board[0][0] != NEITHER) {
    return state->board[0][0];
  }
  if (state->board[0][2] == state->board[1][1] &&
      state->board[0][2] == state->board[2][0] &&
      state->board[0][2] != NEITHER) {
    return state->board[0][2];
  }

  // Check tie
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (state->board[i][j] == NEITHER) {
        return NEITHER;
      }
    }
  }

  return TIE;
}

void print_board(state_t* state) {
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (state->board[i][j] == X) {
        printf("X");
      } else if (state->board[i][j] == O) {
        printf("O");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main(int argc, char** argv) {
  state_t state;
  int player = X;
  int winner;
  int x, y;

  // Initialize board
  state.board = malloc(3 * sizeof(int*));
  for (int i = 0; i < 3; i++) {
    state.board[i] = malloc(3 * sizeof(int));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      state.board[i][j] = NEITHER;
    }
  }

  // Run game
  while (1) {
    // Print board
    print_board(&state);

    // Get player move
    if (player == X) {
      printf("Player X, enter your move (row, column): ");
    } else {
      printf("Player O, enter your move (row, column): ");
    }
    scanf("%d %d", &x, &y);

    // Make move
    if (!make_move(&state, player, x, y)) {
      printf("Invalid move!\n");
      continue;
    }

    // Check winner
    winner = check_winner(&state);
    if (winner == TIE) {
      printf("Tie!\n");
      break;
    } else if (winner == X) {
      printf("Player X wins!\n");
      break;
    } else if (winner == O) {
      printf("Player O wins!\n");
      break;
    }

    // Switch player
    player = 3 - player;
  }

  // Free board
  for (int i = 0; i < 3; i++) {
    free(state.board[i]);
  }
  free(state.board);

  return 0;
}