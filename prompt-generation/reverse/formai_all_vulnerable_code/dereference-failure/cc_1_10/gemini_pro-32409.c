//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Define the number of balls to draw
#define NUM_BALLS 75

// Define the bingo card data structure
typedef struct {
  int numbers[CARD_WIDTH * CARD_HEIGHT];
  int marked[CARD_WIDTH * CARD_HEIGHT];
} bingo_card;

// Create a new bingo card
bingo_card* create_card() {
  bingo_card* card = malloc(sizeof(bingo_card));
  for (int i = 0; i < CARD_WIDTH * CARD_HEIGHT; i++) {
    card->numbers[i] = 0;
    card->marked[i] = 0;
  }
  return card;
}

// Free a bingo card
void free_card(bingo_card* card) {
  free(card);
}

// Print a bingo card
void print_card(bingo_card* card) {
  for (int i = 0; i < CARD_WIDTH * CARD_HEIGHT; i++) {
    if (i % CARD_WIDTH == 0) {
      printf("\n");
    }
    printf("%2d ", card->numbers[i]);
  }
  printf("\n");
}

// Mark a number on a bingo card
void mark_number(bingo_card* card, int number) {
  for (int i = 0; i < CARD_WIDTH * CARD_HEIGHT; i++) {
    if (card->numbers[i] == number) {
      card->marked[i] = 1;
    }
  }
}

// Check if a bingo card has won
int check_win(bingo_card* card) {
  // Check rows
  for (int i = 0; i < CARD_HEIGHT; i++) {
    int count = 0;
    for (int j = 0; j < CARD_WIDTH; j++) {
      if (card->marked[i * CARD_WIDTH + j] == 1) {
        count++;
      }
    }
    if (count == CARD_WIDTH) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < CARD_WIDTH; i++) {
    int count = 0;
    for (int j = 0; j < CARD_HEIGHT; j++) {
      if (card->marked[j * CARD_WIDTH + i] == 1) {
        count++;
      }
    }
    if (count == CARD_HEIGHT) {
      return 1;
    }
  }

  // Check diagonals
  int count1 = 0;
  for (int i = 0; i < CARD_WIDTH * CARD_HEIGHT; i += CARD_WIDTH + 1) {
    if (card->marked[i] == 1) {
      count1++;
    }
  }
  if (count1 == CARD_WIDTH) {
    return 1;
  }

  int count2 = 0;
  for (int i = CARD_WIDTH - 1; i < CARD_WIDTH * CARD_HEIGHT - 1; i += CARD_WIDTH - 1) {
    if (card->marked[i] == 1) {
      count2++;
    }
  }
  if (count2 == CARD_WIDTH) {
    return 1;
  }

  return 0;
}

// Play a game of bingo
void play_bingo() {
  // Create a new bingo card
  bingo_card* card = create_card();

  // Generate a random number between 1 and 75
  srand(time(NULL));
  for (int i = 0; i < NUM_BALLS; i++) {
    int number = rand() % 75 + 1;
    printf("Ball drawn: %d\n", number);
    
    // Mark the number on the bingo card
    mark_number(card, number);
    
    // Check if the bingo card has won
    if (check_win(card)) {
      printf("Bingo!\n");
      print_card(card);
      break;
    }
  }

  // Free the bingo card
  free_card(card);
}

int main() {
  // Play a game of bingo
  play_bingo();
  
  return 0;
}