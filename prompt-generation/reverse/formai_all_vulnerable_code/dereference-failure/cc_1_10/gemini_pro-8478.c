//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

// Card struct
typedef struct card {
  int rank;
  int suit;
} card;

// Player struct
typedef struct player {
  card hand[NUM_CARDS];
  int hand_size;
} player;

// Game struct
typedef struct game {
  player players[NUM_PLAYERS];
  card deck[NUM_CARDS];
  int deck_size;
} game;

// Function to create a new game
game* new_game() {
  game* g = malloc(sizeof(game));
  for (int i = 0; i < NUM_CARDS; i++) {
    g->deck[i].rank = i % NUM_RANKS;
    g->deck[i].suit = i / NUM_RANKS;
  }
  g->deck_size = NUM_CARDS;
  return g;
}

// Function to shuffle the deck
void shuffle_deck(game* g) {
  for (int i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;
    card temp = g->deck[i];
    g->deck[i] = g->deck[j];
    g->deck[j] = temp;
  }
}

// Function to deal cards to players
void deal_cards(game* g) {
  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < NUM_CARDS; j++) {
      g->players[i].hand[j] = g->deck[j];
      g->deck_size--;
    }
  }
}

// Function to print the game state
void print_game(game* g) {
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d:\n", i);
    for (int j = 0; j < NUM_CARDS; j++) {
      printf("%d %d\n", g->players[i].hand[j].rank, g->players[i].hand[j].suit);
    }
  }
}

// Main function
int main() {
  srand(time(NULL));

  // Create a new game
  game* g = new_game();

  // Shuffle the deck
  shuffle_deck(g);

  // Deal cards to players
  deal_cards(g);

  // Print the game state
  print_game(g);

  return 0;
}