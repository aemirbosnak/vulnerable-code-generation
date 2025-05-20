//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_BALLS 75

typedef struct {
  char name[20];
  int numbers[5];
} Player;

typedef struct {
  Player players[MAX_PLAYERS];
  int balls[MAX_BALLS];
  int drawn_balls[MAX_BALLS];
  int num_drawn_balls;
} BingoGame;

BingoGame game;

void init_game() {
  // Initialize the game players
  for (int i = 0; i < MAX_PLAYERS; i++) {
    strcpy(game.players[i].name, "Player");
    char num[3];
    sprintf(num, "%d", i + 1);
    strcat(game.players[i].name, num);

    // Initialize the player's numbers
    for (int j = 0; j < 5; j++) {
      game.players[i].numbers[j] = rand() % MAX_BALLS + 1;
    }
  }

  // Initialize the game balls
  for (int i = 0; i < MAX_BALLS; i++) {
    game.balls[i] = i + 1;
  }
}

void draw_ball() {
  // Get a random index in the balls array
  int index = rand() % (MAX_BALLS - game.num_drawn_balls);

  // Get the ball at the random index
  int ball = game.balls[index];

  // Move the last ball to the current index
  game.balls[index] = game.balls[MAX_BALLS - game.num_drawn_balls - 1];

  // Add the ball to the drawn balls array
  game.drawn_balls[game.num_drawn_balls++] = ball;
}

int check_winning_line(Player player) {
  // Check if the player has a horizontal line
  for (int i = 0; i < 5; i++) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
      if (player.numbers[j] == game.drawn_balls[i]) {
        count++;
      }
    }
    if (count == 5) {
      return 1;
    }
  }

  // Check if the player has a vertical line
  for (int i = 0; i < 5; i++) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
      if (player.numbers[i] == game.drawn_balls[j]) {
        count++;
      }
    }
    if (count == 5) {
      return 1;
    }
  }

  // Check if the player has a diagonal line
  int count_diagonal_1 = 0;
  for (int i = 0; i < 5; i++) {
    if (player.numbers[i] == game.drawn_balls[i]) {
      count_diagonal_1++;
    }
  }
  if (count_diagonal_1 == 5) {
    return 1;
  }

  int count_diagonal_2 = 0;
  for (int i = 0; i < 5; i++) {
    if (player.numbers[i] == game.drawn_balls[4 - i]) {
      count_diagonal_2++;
    }
  }
  if (count_diagonal_2 == 5) {
    return 1;
  }

  // The player does not have a winning line
  return 0;
}

void print_result() {
  // Check if any of the players has won
  for (int i = 0; i < MAX_PLAYERS; i++) {
    Player player = game.players[i];
    if (check_winning_line(player)) {
      printf("Player %s has won!\n", player.name);
      return;
    }
  }

  // No players have won
  printf("No winners this time!\n");
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the game
  init_game();

  // Draw balls until someone wins
  while (game.num_drawn_balls < MAX_BALLS) {
    draw_ball();

    // Check if any of the players has won
    for (int i = 0; i < MAX_PLAYERS; i++) {
      Player player = game.players[i];
      if (check_winning_line(player)) {
        print_result();
        return 0;
      }
    }
  }

  // No players have won
  print_result();

  return 0;
}