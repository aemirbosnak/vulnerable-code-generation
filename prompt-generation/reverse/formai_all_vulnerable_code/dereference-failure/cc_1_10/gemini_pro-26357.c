//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *name;
  int score;
} player_t;

typedef struct {
  char *board[4][4];
  int matches;
} game_t;

game_t game;

void init_game() {
  int i, j, k;
  char *symbols[] = {"A", "B", "C", "D", "E", "F", "G", "H"};

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      k = rand() % 8;
      game.board[i][j] = malloc(2);
      strcpy(game.board[i][j], symbols[k]);
    }
  }

  game.matches = 0;
}

void print_game() {
  int i, j;

  printf("  1 2 3 4\n");
  for (i = 0; i < 4; i++) {
    printf("%d ", i + 1);
    for (j = 0; j < 4; j++) {
      printf("%s ", game.board[i][j]);
    }
    printf("\n");
  }
}

int get_input() {
  int row, col;

  printf("Enter row and column (e.g. 1 2): ");
  scanf("%d %d", &row, &col);

  return row * 4 + col;
}

int check_match(int i1, int j1, int i2, int j2) {
  return strcmp(game.board[i1][j1], game.board[i2][j2]) == 0;
}

void play_game() {
  int i1, j1, i2, j2;

  while (game.matches < 8) {
    print_game();

    i1 = get_input();
    i1 /= 4;
    j1 = get_input() % 4;

    i2 = get_input();
    i2 /= 4;
    j2 = get_input() % 4;

    if (check_match(i1, j1, i2, j2)) {
      printf("Match found!\n");
      game.matches++;
    } else {
      printf("No match found.\n");
    }
  }
}

void free_game() {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      free(game.board[i][j]);
    }
  }
}

int main() {
  srand(time(NULL));

  init_game();
  play_game();
  free_game();

  return 0;
}