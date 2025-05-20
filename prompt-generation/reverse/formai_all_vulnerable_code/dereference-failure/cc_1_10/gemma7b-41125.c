//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCS 5
#define NUM_PILES 3

typedef struct Disc {
  int number;
  struct Disc* next;
} Disc;

void move_disc(Disc* from, Disc* to) {
  if (from && to) {
    from->next = to;
    to->number = from->number;
    free(from);
  }
}

int main() {
  Disc* pile1 = NULL;
  Disc* pile2 = NULL;
  Disc* pile3 = NULL;

  // Create the initial discs
  for (int i = 0; i < MAX_DISCS; i++) {
    Disc* new_disc = malloc(sizeof(Disc));
    new_disc->number = i + 1;
    new_disc->next = NULL;

    if (pile1 == NULL) {
      pile1 = new_disc;
    } else {
      pile2 = new_disc;
    }
  }

  // Play the game
  int game_over = 0;
  while (!game_over) {
    // Get the player's move
    int move = 0;
    printf("Enter your move (1-3): ");
    scanf("%d", &move);

    // Validate the move
    if (move < 1 || move > NUM_PILES) {
      printf("Invalid move.\n");
      continue;
    }

    // Move the disc
    Disc* from = NULL;
    Disc* to = NULL;
    switch (move) {
      case 1:
        from = pile1;
        to = pile2;
        break;
      case 2:
        from = pile2;
        to = pile3;
        break;
      case 3:
        from = pile3;
        to = pile1;
        break;
    }

    move_disc(from, to);

    // Check if the game is over
    if (pile1 == NULL) {
      game_over = 1;
      printf("Congratulations! You won!\n");
    } else {
      printf("Next move.\n");
    }
  }

  return 0;
}