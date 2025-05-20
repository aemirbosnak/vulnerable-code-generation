//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players.
#define MAX_PLAYERS 4

// Define the maximum number of cards in a hand.
#define MAX_HAND_SIZE 13

// Define the number of suits in a deck of cards.
#define NUM_SUITS 4

// Define the number of ranks in a deck of cards.
#define NUM_RANKS 13

// Define the suits of a deck of cards.
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Define the ranks of a deck of cards.
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

// Define the structure of a card.
typedef struct card {
  int suit;
  int rank;
} card;

// Define the structure of a player.
typedef struct player {
  char name[20];
  card hand[MAX_HAND_SIZE];
  int hand_size;
} player;

// Define the structure of a game.
typedef struct game {
  player players[MAX_PLAYERS];
  int num_players;
  card deck[NUM_SUITS * NUM_RANKS];
  int deck_size;
} game;

// Create a new game.
game *create_game() {
  game *g = malloc(sizeof(game));
  g->num_players = 0;
  g->deck_size = NUM_SUITS * NUM_RANKS;
  for (int i = 0; i < NUM_SUITS; i++) {
    for (int j = 0; j < NUM_RANKS; j++) {
      g->deck[i * NUM_RANKS + j].suit = i;
      g->deck[i * NUM_RANKS + j].rank = j;
    }
  }
  return g;
}

// Add a player to the game.
void add_player(game *g, char *name) {
  if (g->num_players == MAX_PLAYERS) {
    return;
  }
  strcpy(g->players[g->num_players].name, name);
  g->players[g->num_players].hand_size = 0;
  g->num_players++;
}

// Shuffle the deck.
void shuffle_deck(game *g) {
  for (int i = 0; i < g->deck_size; i++) {
    int j = rand() % g->deck_size;
    card temp = g->deck[i];
    g->deck[i] = g->deck[j];
    g->deck[j] = temp;
  }
}

// Deal the cards.
void deal_cards(game *g) {
  for (int i = 0; i < g->num_players; i++) {
    for (int j = 0; j < MAX_HAND_SIZE; j++) {
      g->players[i].hand[j] = g->deck[g->deck_size - 1];
      g->deck_size--;
    }
  }
}

// Sort the cards in a player's hand.
void sort_hand(player *p) {
  for (int i = 0; i < p->hand_size - 1; i++) {
    for (int j = i + 1; j < p->hand_size; j++) {
      if (p->hand[j].rank < p->hand[i].rank) {
        card temp = p->hand[i];
        p->hand[i] = p->hand[j];
        p->hand[j] = temp;
      }
    }
  }
}

// Print the cards in a player's hand.
void print_hand(player *p) {
  for (int i = 0; i < p->hand_size; i++) {
    printf("%s of %s\n", ranks[p->hand[i].rank], suits[p->hand[i].suit]);
  }
}

// Get the winning player.
player *get_winning_player(game *g) {
  player *winner = NULL;
  int highest_rank = -1;
  for (int i = 0; i < g->num_players; i++) {
    if (g->players[i].hand[0].rank > highest_rank) {
      winner = &g->players[i];
      highest_rank = g->players[i].hand[0].rank;
    }
  }
  return winner;
}

// Play the game.
void play_game(game *g) {
  // Shuffle the deck.
  shuffle_deck(g);

  // Deal the cards.
  deal_cards(g);

  // Sort the cards in each player's hand.
  for (int i = 0; i < g->num_players; i++) {
    sort_hand(&g->players[i]);
  }

  // Print the cards in each player's hand.
  for (int i = 0; i < g->num_players; i++) {
    printf("%s's hand:\n", g->players[i].name);
    print_hand(&g->players[i]);
    printf("\n");
  }

  // Get the winning player.
  player *winner = get_winning_player(g);

  // Print the winning player.
  printf("The winner is %s!\n", winner->name);
}

// Free the game.
void free_game(game *g) {
  free(g);
}

// Main function.
int main() {
  // Create a new game.
  game *g = create_game();

  // Add players to the game.
  add_player(g, "Player 1");
  add_player(g, "Player 2");
  add_player(g, "Player 3");
  add_player(g, "Player 4");

  // Play the game.
  play_game(g);

  // Free the game.
  free_game(g);

  return 0;
}