//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

typedef struct Game {
  Node** board;
  int turn;
  struct Game* next;
} Game;

Game* createGame() {
  Game* game = malloc(sizeof(Game));
  game->board = malloc(sizeof(Node*) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    game->board[i] = malloc(sizeof(Node));
    game->board[i]->x = i;
    game->board[i]->y = -1;
    game->board[i]->next = NULL;
  }
  game->turn = 0;
  game->next = NULL;
  return game;
}

void playGame(Game* game) {
  int move = rand() % 9;
  while (game->board[move]->y != -1) {
    move = rand() % 9;
  }
  game->board[move]->y = game->turn;
  game->turn = (game->turn + 1) % 2;
}

void printBoard(Game* game) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", game->board[i]->y == -1 ? ' ' : (char)('X' + game->board[i]->y));
    }
    printf("\n");
  }
}

int main() {
  Game* game = createGame();
  while (!game->next) {
    playGame(game);
    printBoard(game);
  }
  return 0;
}