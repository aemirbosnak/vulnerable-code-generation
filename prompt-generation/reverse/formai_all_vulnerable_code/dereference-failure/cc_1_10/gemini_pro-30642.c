//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the game board
#define BOARD_WIDTH 4
#define BOARD_HEIGHT 4

// Define the number of pairs of cards
#define NUM_PAIRS 8

// Define the states of a card
#define CARD_HIDDEN 0
#define CARD_SHOWN 1
#define CARD_MATCHED 2

// Define the structure of a card
typedef struct {
  int value;
  int state;
} Card;

// Define the structure of the game board
typedef struct {
  Card cards[BOARD_WIDTH][BOARD_HEIGHT];
} Board;

// Create a new game board
Board* create_board() {
  Board* board = (Board*)malloc(sizeof(Board));

  // Initialize the cards on the board
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      board->cards[i][j].value = -1;
      board->cards[i][j].state = CARD_HIDDEN;
    }
  }

  // Generate the pairs of cards
  int values[NUM_PAIRS * 2];
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    values[i] = i / 2;
  }

  // Shuffle the values
  srand(time(NULL));
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    int r = rand() % (NUM_PAIRS * 2);
    int temp = values[i];
    values[i] = values[r];
    values[r] = temp;
  }

  // Assign the values to the cards on the board
  int index = 0;
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      board->cards[i][j].value = values[index];
      index++;
    }
  }

  return board;
}

// Free the memory allocated for the game board
void free_board(Board* board) {
  free(board);
}

// Print the game board to the console
void print_board(Board* board) {
  printf("  ");
  for (int i = 0; i < BOARD_WIDTH; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    printf("%2d ", i);
    for (int j = 0; j < BOARD_WIDTH; j++) {
      if (board->cards[i][j].state == CARD_HIDDEN) {
        printf("[_] ");
      } else if (board->cards[i][j].state == CARD_SHOWN) {
        printf("[%2d] ", board->cards[i][j].value);
      } else if (board->cards[i][j].state == CARD_MATCHED) {
        printf("[XX] ");
      }
    }
    printf("\n");
  }
}

// Get the user's input
void get_input(Board* board, int* row1, int* col1, int* row2, int* col2) {
  printf("Enter the coordinates of the first card (row, column): ");
  scanf("%d %d", row1, col1);

  printf("Enter the coordinates of the second card (row, column): ");
  scanf("%d %d", row2, col2);
}

// Check if the two cards match
int check_match(Board* board, int row1, int col1, int row2, int col2) {
  if (board->cards[row1][col1].value == board->cards[row2][col2].value) {
    return 1;
  } else {
    return 0;
  }
}

// Update the state of the two cards
void update_cards(Board* board, int row1, int col1, int row2, int col2) {
  board->cards[row1][col1].state = CARD_MATCHED;
  board->cards[row2][col2].state = CARD_MATCHED;
}

// Check if the game is over
int check_game_over(Board* board) {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      if (board->cards[i][j].state != CARD_MATCHED) {
        return 0;
      }
    }
  }
  return 1;
}

// Play the game
void play_game() {
  // Create the game board
  Board* board = create_board();

  // Print the game board to the console
  print_board(board);

  // Get the user's input
  int row1, col1, row2, col2;
  get_input(board, &row1, &col1, &row2, &col2);

  // Show the two cards
  board->cards[row1][col1].state = CARD_SHOWN;
  board->cards[row2][col2].state = CARD_SHOWN;

  // Print the game board to the console
  print_board(board);

  // Check if the two cards match
  int match = check_match(board, row1, col1, row2, col2);

  // If the two cards match, update their state
  if (match) {
    update_cards(board, row1, col1, row2, col2);
  }

  // Check if the game is over
  int game_over = check_game_over(board);

  // Print the game board to the console
  print_board(board);

  // If the game is over, print a message to the console
  if (game_over) {
    printf("Congratulations! You won the game.\n");
  }

  // Free the memory allocated for the game board
  free_board(board);
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}