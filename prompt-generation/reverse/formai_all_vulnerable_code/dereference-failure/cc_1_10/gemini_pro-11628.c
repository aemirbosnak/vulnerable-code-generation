//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TOWERS 3
#define MAX_DISKS  10

typedef struct Tower {
  int num_disks;
  int disks[MAX_DISKS];
} Tower;

typedef struct Game {
  Tower towers[MAX_TOWERS];
  int num_moves;
} Game;

// Initialize a new game with the given number of disks.
Game* new_game(int num_disks) {
  Game* game = malloc(sizeof(Game));
  game->num_moves = 0;

  for (int i = 0; i < MAX_TOWERS; i++) {
    game->towers[i].num_disks = 0;
  }

  // Place all disks on the first tower.
  for (int i = num_disks - 1; i >= 0; i--) {
    game->towers[0].disks[game->towers[0].num_disks++] = i;
  }

  return game;
}

// Free the memory allocated for the game.
void free_game(Game* game) {
  free(game);
}

// Print the current state of the game.
void print_game(Game* game) {
  for (int i = 0; i < MAX_TOWERS; i++) {
    printf("Tower %d: ", i + 1);
    for (int j = 0; j < game->towers[i].num_disks; j++) {
      printf("%d ", game->towers[i].disks[j]);
    }
    printf("\n");
  }
}

// Move a disk from one tower to another.
bool move_disk(Game* game, int from_tower, int to_tower) {
  // Check if the move is valid.
  if (game->towers[from_tower].num_disks == 0 ||
      (game->towers[to_tower].num_disks > 0 &&
       game->towers[from_tower].disks[game->towers[from_tower].num_disks - 1] >
         game->towers[to_tower].disks[game->towers[to_tower].num_disks - 1])) {
    return false;
  }

  // Move the disk.
  game->towers[to_tower].disks[game->towers[to_tower].num_disks++] =
    game->towers[from_tower].disks[--game->towers[from_tower].num_disks];
  game->num_moves++;

  return true;
}

// Solve the Tower of Hanoi problem.
bool solve_tower_of_hanoi(Game* game, int num_disks, int from_tower, int to_tower, int via_tower) {
  // If there are no disks left, we are done.
  if (num_disks == 0) {
    return true;
  }

  // Move the top disk from the from_tower to the via_tower.
  if (!move_disk(game, from_tower, via_tower)) {
    return false;
  }

  // Recursively solve the problem for the remaining disks.
  if (!solve_tower_of_hanoi(game, num_disks - 1, from_tower, to_tower, via_tower)) {
    return false;
  }

  // Move the top disk from the via_tower to the to_tower.
  if (!move_disk(game, via_tower, to_tower)) {
    return false;
  }

  // Recursively solve the problem for the remaining disks.
  if (!solve_tower_of_hanoi(game, num_disks - 1, via_tower, to_tower, from_tower)) {
    return false;
  }

  return true;
}

int main() {
  // Get the number of disks from the user.
  int num_disks;
  printf("Enter the number of disks: ");
  scanf("%d", &num_disks);

  // Create a new game.
  Game* game = new_game(num_disks);

  // Print the initial state of the game.
  printf("Initial state:\n");
  print_game(game);

  // Solve the Tower of Hanoi problem.
  if (solve_tower_of_hanoi(game, num_disks, 0, 2, 1)) {
    // Print the final state of the game.
    printf("Final state:\n");
    print_game(game);

    // Print the number of moves.
    printf("Number of moves: %d\n", game->num_moves);
  } else {
    printf("Error: Could not solve the Tower of Hanoi problem.\n");
  }

  // Free the memory allocated for the game.
  free_game(game);

  return 0;
}