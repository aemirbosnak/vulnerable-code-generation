//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_PAIRS 8
#define BOARD_SIZE (NUM_PAIRS * 2)

// Define the card struct
typedef struct card {
  int value;
  bool revealed;
} card;

// Function to create a new deck of cards
card *create_deck() {
  // Allocate memory for the deck
  card *deck = malloc(sizeof(card) * BOARD_SIZE);
  
  // Initialize the deck with pairs of values
  int value = 1;
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    deck[i].value = value;
    deck[i + 1].value = value;
    value++;
  }

  return deck;
}

// Function to shuffle the deck of cards
void shuffle_deck(card *deck) {
  // Use the Fisher-Yates shuffle algorithm
  for (int i = 0; i < BOARD_SIZE; i++) {
    int j = rand() % BOARD_SIZE;
    card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

// Function to print the game board
void print_board(card *deck) {
  // Clear the screen
  system("clear");

  // Print the header
  printf("Memory Game\n");
  printf("------------\n");

  // Print the cards
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (deck[i].revealed) {
      printf("[%d] ", deck[i].value);
    } else {
      printf("[ ] ");
    }

    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }
}

// Function to get the player's guess
int get_guess() {
  int guess;
  printf("Enter your guess (1-%d): ", BOARD_SIZE);
  scanf("%d", &guess);
  return guess - 1;
}

// Function to check if the player's guess is correct
bool is_correct_guess(card *deck, int guess1, int guess2) {
  return deck[guess1].value == deck[guess2].value;
}

// Function to play the game
void play_game() {
  // Create the deck of cards
  card *deck = create_deck();

  // Shuffle the deck
  shuffle_deck(deck);

  // Initialize the game variables
  int guesses = 0;
  int matches = 0;

  // Game loop
  while (matches < NUM_PAIRS) {
    // Print the game board
    print_board(deck);

    // Get the player's first guess
    int guess1 = get_guess();

    // Reveal the first card
    deck[guess1].revealed = true;

    // Print the game board
    print_board(deck);

    // Get the player's second guess
    int guess2 = get_guess();

    // Reveal the second card
    deck[guess2].revealed = true;

    // Check if the player's guess is correct
    if (is_correct_guess(deck, guess1, guess2)) {
      printf("Correct guess!\n");
      matches++;
    } else {
      printf("Incorrect guess!\n");
      // Hide the cards
      deck[guess1].revealed = false;
      deck[guess2].revealed = false;
    }

    // Increment the number of guesses
    guesses++;
  }

  // Print the game results
  printf("Congratulations! You won the game in %d guesses.\n", guesses);

  // Free the deck of cards
  free(deck);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}