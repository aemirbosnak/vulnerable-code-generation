//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the possible numbers on the bingo card
#define NUMBERS 75

// Define the number of turns in the game
#define TURNS 100

// Define the number of players in the game
#define PLAYERS 4

// Define the data structure for a bingo card
typedef struct bingo_card {
  int numbers[CARD_SIZE][CARD_SIZE];
  int marked[CARD_SIZE][CARD_SIZE];
} bingo_card;

// Define the data structure for a player
typedef struct player {
  bingo_card card;
  int score;
} player;

// Create a new bingo card
bingo_card *create_card() {
  bingo_card *card = malloc(sizeof(bingo_card));
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card->numbers[i][j] = rand() % NUMBERS + 1;
      card->marked[i][j] = 0;
    }
  }
  return card;
}

// Print a bingo card
void print_card(bingo_card *card) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      printf("%2d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

// Mark a number on a bingo card
void mark_number(bingo_card *card, int number) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->numbers[i][j] == number) {
        card->marked[i][j] = 1;
      }
    }
  }
}

// Check if a bingo card has won
int check_win(bingo_card *card) {
  // Check rows
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < CARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][i]) {
      count1++;
    }
  }
  if (count1 == CARD_SIZE) {
    return 1;
  }

  int count2 = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][CARD_SIZE - i - 1]) {
      count2++;
    }
  }
  if (count2 == CARD_SIZE) {
    return 1;
  }

  // No win yet
  return 0;
}

// Get the score of a bingo card
int get_score(bingo_card *card) {
  int score = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (!card->marked[i][j]) {
        score += card->numbers[i][j];
      }
    }
  }
  return score;
}

// Play a round of bingo
void play_round(player *players, int numbers[]) {
  // Draw a number
  int number = numbers[rand() % NUMBERS];

  // Mark the number on each player's card
  for (int i = 0; i < PLAYERS; i++) {
    mark_number(&players[i].card, number);
  }

  // Check if any player has won
  for (int i = 0; i < PLAYERS; i++) {
    if (check_win(&players[i].card)) {
      // Player has won!
      players[i].score = get_score(&players[i].card);
      printf("Player %d has won!\n", i + 1);
      printf("Score: %d\n", players[i].score);
      return;
    }
  }
}

// Play a game of bingo
void play_game() {
  // Create the players
  player players[PLAYERS];
  for (int i = 0; i < PLAYERS; i++) {
    players[i].card = *create_card();
    players[i].score = 0;
  }

  // Create the array of numbers
  int numbers[NUMBERS];
  for (int i = 0; i < NUMBERS; i++) {
    numbers[i] = i + 1;
  }

  // Play the rounds of bingo
  for (int i = 0; i < TURNS; i++) {
    play_round(players, numbers);
  }

  // Find the player with the highest score
  int highest_score = 0;
  int winner = -1;
  for (int i = 0; i < PLAYERS; i++) {
    if (players[i].score > highest_score) {
      highest_score = players[i].score;
      winner = i;
    }
  }

  // Print the winner
  if (winner != -1) {
    printf("Player %d has won the game!\n", winner + 1);
    printf("Score: %d\n", highest_score);
  } else {
    printf("No one has won the game.\n");
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}