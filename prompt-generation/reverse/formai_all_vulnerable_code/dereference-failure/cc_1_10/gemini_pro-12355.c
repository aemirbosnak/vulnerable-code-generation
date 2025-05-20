//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Colors for the cards
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Symbols for the cards
#define HEART "\u2665"
#define DIAMOND "\u2666"
#define CLUB "\u2663"
#define SPADE "\u2660"

// Function to create a new deck of cards
int* createDeck() {
  int* deck = malloc(52 * sizeof(int));

  // Initialize the deck with all the cards
  for (int i = 0; i < 52; i++) {
    deck[i] = i;
  }

  return deck;
}

// Function to shuffle the deck of cards
void shuffleDeck(int* deck) {
  // Seed the random number generator
  srand(time(NULL));

  // Shuffle the deck
  for (int i = 0; i < 52; i++) {
    int r = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
  }
}

// Function to deal a hand of cards to a player
int* dealHand(int* deck) {
  // Allocate memory for the hand
  int* hand = malloc(5 * sizeof(int));

  // Deal the cards to the hand
  for (int i = 0; i < 5; i++) {
    hand[i] = deck[i];
  }

  return hand;
}

// Function to print a card
void printCard(int card) {
  // Get the color and symbol of the card
  int color = card / 13;
  int symbol = card % 13;

  // Print the card
  switch (color) {
    case 0:
      printf("%s", RED);
      break;
    case 1:
      printf("%s", GREEN);
      break;
    case 2:
      printf("%s", YELLOW);
      break;
    case 3:
      printf("%s", BLUE);
      break;
  }

  switch (symbol) {
    case 0:
      printf("%s", HEART);
      break;
    case 1:
      printf("%s", DIAMOND);
      break;
    case 2:
      printf("%s", CLUB);
      break;
    case 3:
      printf("%s", SPADE);
      break;
  }

  printf("%s", WHITE);
}

// Function to print a hand of cards
void printHand(int* hand) {
  // Print each card in the hand
  for (int i = 0; i < 5; i++) {
    printCard(hand[i]);
    printf(" ");
  }

  printf("\n");
}

// Function to check if two cards are a match
int isMatch(int card1, int card2) {
  // Check if the cards have the same color and symbol
  return (card1 / 13 == card2 / 13) && (card1 % 13 == card2 % 13);
}

// Function to play the game
void playGame() {
  // Create a new deck of cards
  int* deck = createDeck();

  // Shuffle the deck
  shuffleDeck(deck);

  // Deal a hand of cards to each player
  int* hand1 = dealHand(deck);
  int* hand2 = dealHand(deck);

  // Print the hands
  printf("Player 1's hand: ");
  printHand(hand1);
  printf("Player 2's hand: ");
  printHand(hand2);

  // Get the player's guesses
  int guess1, guess2;
  printf("Player 1, guess two cards: ");
  scanf("%d %d", &guess1, &guess2);
  printf("Player 2, guess two cards: ");
  scanf("%d %d", &guess1, &guess2);

  // Check if the guesses are a match
  int match1 = isMatch(hand1[guess1], hand1[guess2]);
  int match2 = isMatch(hand2[guess1], hand2[guess2]);

  // Print the results
  if (match1 && match2) {
    printf("Both players win!\n");
  } else if (match1) {
    printf("Player 1 wins!\n");
  } else if (match2) {
    printf("Player 2 wins!\n");
  } else {
    printf("No one wins.\n");
  }

  // Free the memory
  free(deck);
  free(hand1);
  free(hand2);
}

// Main function
int main() {
  // Play the game
  playGame();

  return 0;
}