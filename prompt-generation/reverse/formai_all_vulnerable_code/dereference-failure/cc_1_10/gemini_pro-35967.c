//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 5
#define NUM_BINGO_NUMBERS 75
#define NUM_BINGO_ROWS 5
#define NUM_BINGO_COLUMNS 5

// Bingo card structure
typedef struct {
  int numbers[NUM_BINGO_ROWS][NUM_BINGO_COLUMNS];
  int marked[NUM_BINGO_ROWS][NUM_BINGO_COLUMNS];
} BingoCard;

// Bingo player structure
typedef struct {
  char name[20];
  BingoCard card;
} BingoPlayer;

// Bingo game structure
typedef struct {
  BingoPlayer players[NUM_PLAYERS];
  int bingo_numbers[NUM_BINGO_NUMBERS];
  int current_number;
} BingoGame;

// Function to create a new bingo game
BingoGame* create_bingo_game() {
  BingoGame* game = malloc(sizeof(BingoGame));
  for (int i = 0; i < NUM_PLAYERS; i++) {
    sprintf(game->players[i].name, "Player %d", i + 1);
    for (int j = 0; j < NUM_BINGO_ROWS; j++) {
      for (int k = 0; k < NUM_BINGO_COLUMNS; k++) {
        game->players[i].card.numbers[j][k] = 0;
        game->players[i].card.marked[j][k] = 0;
      }
    }
  }
  for (int i = 0; i < NUM_BINGO_NUMBERS; i++) {
    game->bingo_numbers[i] = i + 1;
  }
  game->current_number = 0;
  return game;
}

// Function to destroy a bingo game
void destroy_bingo_game(BingoGame* game) {
  free(game);
}

// Function to generate a random bingo number
int generate_random_bingo_number(BingoGame* game) {
  int index = rand() % (NUM_BINGO_NUMBERS - game->current_number);
  int number = game->bingo_numbers[index];
  game->bingo_numbers[index] = game->bingo_numbers[NUM_BINGO_NUMBERS - game->current_number - 1];
  game->current_number++;
  return number;
}

// Function to check if a bingo card has won
int is_bingo(BingoCard* card) {
  // Check rows
  for (int i = 0; i < NUM_BINGO_ROWS; i++) {
    int count = 0;
    for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == NUM_BINGO_COLUMNS) {
      return 1;
    }
  }
  // Check columns
  for (int i = 0; i < NUM_BINGO_COLUMNS; i++) {
    int count = 0;
    for (int j = 0; j < NUM_BINGO_ROWS; j++) {
      if (card->marked[j][i]) {
        count++;
      }
    }
    if (count == NUM_BINGO_ROWS) {
      return 1;
    }
  }
  // Check diagonals
  int count1 = 0;
  for (int i = 0; i < NUM_BINGO_ROWS; i++) {
    if (card->marked[i][i]) {
      count1++;
    }
  }
  if (count1 == NUM_BINGO_ROWS) {
    return 1;
  }
  int count2 = 0;
  for (int i = 0; i < NUM_BINGO_ROWS; i++) {
    if (card->marked[i][NUM_BINGO_COLUMNS - i - 1]) {
      count2++;
    }
  }
  if (count2 == NUM_BINGO_ROWS) {
    return 1;
  }
  return 0;
}

// Function to play a bingo game
void play_bingo_game(BingoGame* game) {
  int number;
  while ((number = generate_random_bingo_number(game)) != 0) {
    printf("Number drawn: %d\n", number);
    for (int i = 0; i < NUM_PLAYERS; i++) {
      for (int j = 0; j < NUM_BINGO_ROWS; j++) {
        for (int k = 0; k < NUM_BINGO_COLUMNS; k++) {
          if (game->players[i].card.numbers[j][k] == number) {
            game->players[i].card.marked[j][k] = 1;
          }
        }
      }
      if (is_bingo(&game->players[i].card)) {
        printf("Player %s wins!\n", game->players[i].name);
        return;
      }
    }
  }
  printf("No winner!\n");
}

// Main function
int main() {
  srand(time(NULL));
  BingoGame* game = create_bingo_game();
  play_bingo_game(game);
  destroy_bingo_game(game);
  return 0;
}