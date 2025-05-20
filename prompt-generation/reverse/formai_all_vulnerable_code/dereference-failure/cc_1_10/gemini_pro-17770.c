//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// Structure to represent a card
typedef struct {
  char *front;
  char *back;
  int is_matched;
} card_t;

// Function to create a new card
card_t *create_card(char *front, char *back) {
  card_t *card = malloc(sizeof(card_t));
  card->front = strdup(front);
  card->back = strdup(back);
  card->is_matched = 0;
  return card;
}

// Function to free a card
void free_card(card_t *card) {
  free(card->front);
  free(card->back);
  free(card);
}

// Function to create a new game board
card_t **create_game_board() {
  card_t **board = malloc(sizeof(card_t *) * BOARD_SIZE * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    board[i] = NULL;
  }
  return board;
}

// Function to free a game board
void free_game_board(card_t **board) {
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    if (board[i] != NULL) {
      free_card(board[i]);
    }
  }
  free(board);
}

// Function to shuffle the game board
void shuffle_game_board(card_t **board) {
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    int j = rand() % (BOARD_SIZE * BOARD_SIZE);
    card_t *temp = board[i];
    board[i] = board[j];
    board[j] = temp;
  }
}

// Function to print the game board
void print_game_board(card_t **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i * BOARD_SIZE + j] == NULL) {
        printf("    ");
      } else if (board[i * BOARD_SIZE + j]->is_matched) {
        printf("  %s", board[i * BOARD_SIZE + j]->front);
      } else {
        printf("  ##");
      }
    }
    printf("\n");
  }
}

// Function to get a player's move
int get_player_move() {
  int move;
  printf("Enter your move (1-%d): ", BOARD_SIZE * BOARD_SIZE);
  scanf("%d", &move);
  return move - 1;
}

// Function to check if two cards match
int cards_match(card_t *card1, card_t *card2) {
  return strcmp(card1->front, card2->front) == 0;
}

// Function to play the game
void play_game(card_t **board) {
  int moves = 0;
  int matched_pairs = 0;

  while (matched_pairs < NUM_PAIRS) {
    // Print the game board
    print_game_board(board);

    // Get the player's first move
    int move1 = get_player_move();

    // Get the player's second move
    int move2 = get_player_move();

    // Check if the cards match
    if (cards_match(board[move1], board[move2])) {
      // The cards match, so mark them as matched
      board[move1]->is_matched = 1;
      board[move2]->is_matched = 1;
      matched_pairs++;
    }

    // Increment the number of moves
    moves++;
  }

  // Print the final game board
  print_game_board(board);

  // Print the number of moves it took to find all the pairs
  printf("You found all the pairs in %d moves!\n", moves);
}

// Main function
int main() {
  // Create a new game board
  card_t **board = create_game_board();

  // Create the cards
  card_t *cards[] = {
    create_card("A", "1"),
    create_card("B", "2"),
    create_card("C", "3"),
    create_card("D", "4"),
    create_card("A", "1"),
    create_card("B", "2"),
    create_card("C", "3"),
    create_card("D", "4")
  };

  // Shuffle the cards
  shuffle_game_board(board);

  // Play the game
  play_game(board);

  // Free the game board
  free_game_board(board);

  return 0;
}