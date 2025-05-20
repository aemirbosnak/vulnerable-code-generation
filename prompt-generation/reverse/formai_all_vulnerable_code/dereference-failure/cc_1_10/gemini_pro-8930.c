//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define GRID_SIZE 4

// Define the number of cards in the game
#define NUM_CARDS (GRID_SIZE * GRID_SIZE / 2)

// Define the states of a card
typedef enum {
  CARD_HIDDEN,
  CARD_SHOWN,
  CARD_MATCHED
} CardState;

// Define a card
typedef struct {
  char value;
  CardState state;
} Card;

// Create a new game board
Card** create_game_board() {
  // Allocate memory for the game board
  Card** game_board = malloc(sizeof(Card*) * GRID_SIZE);
  for (int i = 0; i < GRID_SIZE; i++) {
    game_board[i] = malloc(sizeof(Card) * GRID_SIZE);
  }

  // Initialize the game board with hidden cards
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      game_board[i][j].value = ' ';
      game_board[i][j].state = CARD_HIDDEN;
    }
  }

  // Return the game board
  return game_board;
}

// Free the memory allocated for the game board
void free_game_board(Card** game_board) {
  // Free the memory allocated for each row of the game board
  for (int i = 0; i < GRID_SIZE; i++) {
    free(game_board[i]);
  }

  // Free the memory allocated for the game board itself
  free(game_board);
}

// Shuffle the cards on the game board
void shuffle_cards(Card** game_board) {
  // Create an array of the values of the cards
  char values[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    values[i] = 'A' + i;
  }

  // Shuffle the array of values
  for (int i = 0; i < NUM_CARDS; i++) {
    int r = rand() % NUM_CARDS;
    char temp = values[i];
    values[i] = values[r];
    values[r] = temp;
  }

  // Assign the shuffled values to the cards on the game board
  int index = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      game_board[i][j].value = values[index++];
    }
  }
}

// Print the game board to the console
void print_game_board(Card** game_board) {
  // Print the top border of the game board
  printf("  ");
  for (int i = 0; i < GRID_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Print the rows of the game board
  for (int i = 0; i < GRID_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < GRID_SIZE; j++) {
      // Print the value of the card if it is shown
      if (game_board[i][j].state == CARD_SHOWN) {
        printf("%c ", game_board[i][j].value);
      }
      // Print a blank space if the card is hidden
      else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

// Get the input from the user
int get_input(char* prompt) {
  int input;

  // Prompt the user for input
  printf("%s", prompt);

  // Get the input from the user
  scanf("%d", &input);

  // Return the input
  return input;
}

// Check if the game is over
int is_game_over(Card** game_board) {
  // Check if all of the cards are matched
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (game_board[i][j].state != CARD_MATCHED) {
        return 0;
      }
    }
  }

  // Return 1 if the game is over
  return 1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the game board
  Card** game_board = create_game_board();

  // Shuffle the cards on the game board
  shuffle_cards(game_board);

  // Print the game board to the console
  print_game_board(game_board);

  // Get the input from the user
  int row1, col1, row2, col2;
  row1 = get_input("Enter the row of the first card: ");
  col1 = get_input("Enter the column of the first card: ");
  row2 = get_input("Enter the row of the second card: ");
  col2 = get_input("Enter the column of the second card: ");

  // Check if the cards match
  if (game_board[row1][col1].value == game_board[row2][col2].value) {
    // The cards match, so set their states to MATCHED
    game_board[row1][col1].state = CARD_MATCHED;
    game_board[row2][col2].state = CARD_MATCHED;
  }

  // Print the game board to the console
  print_game_board(game_board);

  // Check if the game is over
  if (is_game_over(game_board)) {
    // The game is over, so print a message to the console
    printf("Congratulations! You won the game.\n");
  }

  // Free the memory allocated for the game board
  free_game_board(game_board);

  return 0;
}