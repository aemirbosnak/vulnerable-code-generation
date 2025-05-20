//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PAIRS 8
#define NUM_CARDS 2 * NUM_PAIRS

// Structure to represent a card
typedef struct {
  int value;
  int is_matched;
  int is_flipped;
} Card;

// Create a deck of cards
Card* create_deck() {
  // Allocate memory for the deck
  Card* deck = malloc(sizeof(Card) * NUM_CARDS);

  // Initialize the deck with unique values
  for (int i = 0; i < NUM_PAIRS; i++) {
    deck[2 * i].value = i + 1;
    deck[2 * i + 1].value = i + 1;
  }

  // Shuffle the deck
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int r = rand() % NUM_CARDS;
    Card temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
  }

  // Return the deck
  return deck;
}

// Print the game board
void print_board(Card* deck) {
  printf("  ");
  for (int i = 0; i < NUM_PAIRS; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < NUM_PAIRS; i++) {
    printf("%2d", i + 1);
    for (int j = 0; j < NUM_PAIRS; j++) {
      if (deck[i * NUM_PAIRS + j].is_flipped) {
        printf(" %2d", deck[i * NUM_PAIRS + j].value);
      } else {
        printf("  .");
      }
    }
    printf("\n");
  }
}

// Get the user's input
void get_input(int* row, int* col) {
  printf("Enter the row (1-%d): ", NUM_PAIRS);
  scanf("%d", row);

  printf("Enter the column (1-%d): ", NUM_PAIRS);
  scanf("%d", col);
}

// Check if the game is won
int is_game_won(Card* deck) {
  for (int i = 0; i < NUM_CARDS; i++) {
    if (!deck[i].is_matched) {
      return 0;
    }
  }
  return 1;
}

// Main game loop
int main() {
  // Create the deck of cards
  Card* deck = create_deck();

  // Main game loop
  while (!is_game_won(deck)) {
    // Print the game board
    print_board(deck);

    // Get the user's input
    int row1, col1, row2, col2;
    get_input(&row1, &col1);
    get_input(&row2, &col2);

    // Flip the first card
    deck[(row1 - 1) * NUM_PAIRS + (col1 - 1)].is_flipped = 1;

    // Flip the second card
    deck[(row2 - 1) * NUM_PAIRS + (col2 - 1)].is_flipped = 1;

    // Check if the cards match
    if (deck[(row1 - 1) * NUM_PAIRS + (col1 - 1)].value == deck[(row2 - 1) * NUM_PAIRS + (col2 - 1)].value) {
      // The cards match, so mark them as matched
      deck[(row1 - 1) * NUM_PAIRS + (col1 - 1)].is_matched = 1;
      deck[(row2 - 1) * NUM_PAIRS + (col2 - 1)].is_matched = 1;
    } else {
      // The cards don't match, so flip them back over
      deck[(row1 - 1) * NUM_PAIRS + (col1 - 1)].is_flipped = 0;
      deck[(row2 - 1) * NUM_PAIRS + (col2 - 1)].is_flipped = 0;
    }
  }

  // Print the winning message
  printf("Congratulations! You won the game!\n");

  // Free the memory allocated for the deck
  free(deck);

  return 0;
}