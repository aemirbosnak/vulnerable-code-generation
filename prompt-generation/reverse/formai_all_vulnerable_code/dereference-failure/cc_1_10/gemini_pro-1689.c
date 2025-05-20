//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 10

// Define the range of numbers for the bingo cards
#define MIN_NUM 1
#define MAX_NUM 75

// Create a bingo card
int** create_card() {
  // Allocate memory for the card
  int** card = malloc(CARD_SIZE * sizeof(int*));
  for (int i = 0; i < CARD_SIZE; i++) {
    card[i] = malloc(CARD_SIZE * sizeof(int));
  }

  // Generate random numbers for the card
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card[i][j] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    }
  }

  return card;
}

// Print a bingo card
void print_card(int** card) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }
}

// Check if a number is on a bingo card
int check_number(int** card, int number) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card[i][j] == number) {
        return 1;
      }
    }
  }

  return 0;
}

// Check if a bingo card has won
int check_win(int** card) {
  // Check rows
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card[i][j] == 0) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card[j][i] == 0) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card[i][i] == 0) {
      count1++;
    }
    if (card[i][CARD_SIZE - i - 1] == 0) {
      count2++;
    }
  }
  if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
    return 1;
  }

  return 0;
}

// Generate a random number
int generate_number() {
  return (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}

// Play a round of bingo
void play_round(int** cards[][CARD_SIZE]) {
  // Generate a random number
  int number = generate_number();

  // Print the number
  printf("The number is: %d\n", number);

  // Check each card for the number
  for (int i = 0; i < NUM_CARDS; i++) {
    if (check_number(cards[i], number)) {
      // Mark the number on the card
      for (int j = 0; j < CARD_SIZE; j++) {
        for (int k = 0; k < CARD_SIZE; k++) {
          if (cards[i][j][k] == number) {
            cards[i][j][k] = 0;
          }
        }
      }

      // Check if the card has won
      if (check_win(cards[i])) {
        // Print the winning card
        printf("Card %d has won!\n", i + 1);
        print_card(cards[i]);
        return;
      }
    }
  }

  // No cards have won, so continue playing
  printf("No cards have won.\n\n");
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create the bingo cards
  int*** cards = malloc(NUM_CARDS * sizeof(int**));
  for (int i = 0; i < NUM_CARDS; i++) {
    cards[i] = create_card();
  }

  // Print the bingo cards
  for (int i = 0; i < NUM_CARDS; i++) {
    printf("Card %d:\n", i + 1);
    print_card(cards[i]);
    printf("\n");
  }

  // Play the bingo game
  while (1) {
    play_round(cards);
  }

  return 0;
}