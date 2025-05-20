//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 4

// Define the number of cards in the game
#define NUM_CARDS 8

// Define the states of a card
typedef enum {
  CARD_HIDDEN,
  CARD_SHOWN,
  CARD_MATCHED
} card_state_t;

// Define the structure of a card
typedef struct {
  int value;
  card_state_t state;
} card_t;

// Define the structure of the game board
typedef struct {
  card_t cards[BOARD_SIZE][BOARD_SIZE];
} game_board_t;

// Create a new game board
game_board_t *create_game_board() {
  // Allocate memory for the game board
  game_board_t *board = malloc(sizeof(game_board_t));

  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board->cards[i][j].value = -1;
      board->cards[i][j].state = CARD_HIDDEN;
    }
  }

  // Return the game board
  return board;
}

// Destroy a game board
void destroy_game_board(game_board_t *board) {
  // Free the memory allocated for the game board
  free(board);
}

// Initialize a game board with cards
void initialize_game_board(game_board_t *board) {
  // Create an array of card values
  int values[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    values[i] = i + 1;
  }

  // Shuffle the array of card values
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int r = rand() % NUM_CARDS;
    int temp = values[i];
    values[i] = values[r];
    values[r] = temp;
  }

  // Place the card values on the game board
  int index = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board->cards[i][j].value = values[index];
      index++;
    }
  }
}

// Print the game board
void print_game_board(game_board_t *board) {
  // Print the top border of the game board
  printf("+---+---+---+---+\n");

  // Print the rows of the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    // Print the left border of the row
    printf("| ");

    // Print the cards in the row
    for (int j = 0; j < BOARD_SIZE; j++) {
      // Print the card value or a placeholder
      if (board->cards[i][j].state == CARD_HIDDEN) {
        printf("  ");
      } else {
        printf("%2d", board->cards[i][j].value);
      }

      // Print the right border of the card
      printf(" | ");
    }

    // Print the right border of the row
    printf("|\n");

    // Print the bottom border of the row
    printf("+---+---+---+---+\n");
  }
}

// Get a card from the game board
card_t *get_card(game_board_t *board, int row, int col) {
  // Check if the row and column are valid
  if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
    return NULL;
  }

  // Return the card at the specified row and column
  return &board->cards[row][col];
}

// Flip a card over
void flip_card(game_board_t *board, int row, int col) {
  // Get the card at the specified row and column
  card_t *card = get_card(board, row, col);

  // Check if the card is already shown or matched
  if (card->state == CARD_SHOWN || card->state == CARD_MATCHED) {
    return;
  }

  // Flip the card over
  card->state = CARD_SHOWN;
}

// Check if two cards match
int cards_match(card_t *card1, card_t *card2) {
  // Check if the card values are the same
  return card1->value == card2->value;
}

// Check if the game is over
int game_over(game_board_t *board) {
  // Check if all of the cards have been matched
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->cards[i][j].state != CARD_MATCHED) {
        return 0;
      }
    }
  }

  // All of the cards have been matched, so the game is over
  return 1;
}

// Play the memory game
void play_game(game_board_t *board) {
  // Initialize the game
  initialize_game_board(board);

  // Print the game board
  print_game_board(board);

  // Get the first card
  int row1, col1;
  printf("Enter the row and column of the first card: ");
  scanf("%d %d", &row1, &col1);

  // Flip the first card over
  flip_card(board, row1, col1);

  // Get the second card
  int row2, col2;
  printf("Enter the row and column of the second card: ");
  scanf("%d %d", &row2, &col2);

  // Flip the second card over
  flip_card(board, row2, col2);

  // Check if the two cards match
  if (cards_match(get_card(board, row1, col1), get_card(board, row2, col2))) {
    // The cards match, so mark them as matched
    get_card(board, row1, col1)->state = CARD_MATCHED;
    get_card(board, row2, col2)->state = CARD_MATCHED;
  } else {
    // The cards do not match, so flip them back over
    flip_card(board, row1, col1);
    flip_card(board, row2, col2);
  }

  // Print the game board
  print_game_board(board);

  // Check if the game is over
  if (game_over(board)) {
    printf("Congratulations! You win!\n");
  } else {
    // The game is not over, so get the player's next move
    play_game(board);
  }
}

// Main function
int main() {
  // Create a new game board
  game_board_t *board = create_game_board();

  // Play the memory game
  play_game(board);

  // Destroy the game board
  destroy_game_board(board);

  return 0;
}