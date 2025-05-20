//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define NUM_ROWS 5
#define NUM_COLS 5

// Define the maximum number of balls to be drawn
#define MAX_NUM_BALLS 75

// Define the number of balls to be drawn per round
#define NUM_BALLS_PER_ROUND 5

// Define the bingo card structure
typedef struct {
  int numbers[CARD_SIZE][CARD_SIZE];
  int marked[CARD_SIZE][CARD_SIZE];
} BingoCard;

// Define the bingo game structure
typedef struct {
  BingoCard cards[4];
  int balls[MAX_NUM_BALLS];
  int num_balls_drawn;
} BingoGame;

// Create a new bingo card
BingoCard* create_card() {
  BingoCard* card = malloc(sizeof(BingoCard));
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card->numbers[i][j] = 0;
      card->marked[i][j] = 0;
    }
  }
  return card;
}

// Destroy a bingo card
void destroy_card(BingoCard* card) {
  free(card);
}

// Create a new bingo game
BingoGame* create_game() {
  BingoGame* game = malloc(sizeof(BingoGame));
  for (int i = 0; i < 4; i++) {
    game->cards[i] = *create_card();
  }
  for (int i = 0; i < MAX_NUM_BALLS; i++) {
    game->balls[i] = 0;
  }
  game->num_balls_drawn = 0;
  return game;
}

// Destroy a bingo game
void destroy_game(BingoGame* game) {
  for (int i = 0; i < 4; i++) {
    destroy_card(&game->cards[i]);
  }
  free(game);
}

// Generate a random number between 1 and 75
int generate_random_number() {
  return (rand() % 75) + 1;
}

// Draw a ball from the bingo game
int draw_ball(BingoGame* game) {
  int ball = generate_random_number();
  while (game->balls[ball - 1] != 0) {
    ball = generate_random_number();
  }
  game->balls[ball - 1] = 1;
  game->num_balls_drawn++;
  return ball;
}

// Mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->numbers[i][j] == number) {
        card->marked[i][j] = 1;
      }
    }
  }
}

// Check if a bingo card has won
int check_for_win(BingoCard* card) {
  // Check for horizontal wins
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->marked[i][j] == 1) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < CARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
      if (card->marked[i][j] == 1) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][i] == 1) {
      count++;
    }
  }
  if (count == CARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][CARD_SIZE - 1 - i] == 1) {
      count++;
    }
  }
  if (count == CARD_SIZE) {
    return 1;
  }

  // No win
  return 0;
}

// Play a round of bingo
void play_round(BingoGame* game) {
  // Draw a ball
  int ball = draw_ball(game);

  // Mark the ball on each card
  for (int i = 0; i < 4; i++) {
    mark_number(&game->cards[i], ball);
  }

  // Check for wins
  for (int i = 0; i < 4; i++) {
    if (check_for_win(&game->cards[i])) {
      printf("Player %d wins!\n", i + 1);
      return;
    }
  }
}

// Play a bingo game
void play_game() {
  // Create a new bingo game
  BingoGame* game = create_game();

  // Play rounds until someone wins
  while (game->num_balls_drawn < MAX_NUM_BALLS) {
    play_round(game);
  }

  // No winner
  printf("No winner.\n");

  // Destroy the bingo game
  destroy_game(game);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play a bingo game
  play_game();

  return 0;
}