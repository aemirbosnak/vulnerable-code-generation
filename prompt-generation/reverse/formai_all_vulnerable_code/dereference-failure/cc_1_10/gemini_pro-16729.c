//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board.
#define BOARD_SIZE 4

// Define the number of cards in the game.
#define NUM_CARDS 8

// Define the states of a card.
#define CARD_STATE_HIDDEN 0
#define CARD_STATE_SHOWN 1
#define CARD_STATE_MATCHED 2

// Define the types of cards.
typedef enum {
  CARD_TYPE_A,
  CARD_TYPE_B,
  CARD_TYPE_C,
  CARD_TYPE_D
} CardType;

// Define a card.
typedef struct {
  CardType type;
  int state;
} Card;

// Create a new game board.
Card** create_board() {
  // Allocate memory for the game board.
  Card** board = malloc(BOARD_SIZE * sizeof(Card*));

  // Allocate memory for each row in the game board.
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = malloc(BOARD_SIZE * sizeof(Card));
  }

  // Initialize the game board.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j].type = rand() % NUM_CARDS;
      board[i][j].state = CARD_STATE_HIDDEN;
    }
  }

  // Return the game board.
  return board;
}

// Free the memory allocated for the game board.
void free_board(Card** board) {
  // Free the memory allocated for each row in the game board.
  for (int i = 0; i < BOARD_SIZE; i++) {
    free(board[i]);
  }

  // Free the memory allocated for the game board.
  free(board);
}

// Print the game board.
void print_board(Card** board) {
  // Print the top border of the game board.
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Print each row of the game board.
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j].state == CARD_STATE_HIDDEN) {
        printf("[] ");
      } else if (board[i][j].state == CARD_STATE_SHOWN) {
        printf("%c  ", board[i][j].type + 'A');
      } else if (board[i][j].state == CARD_STATE_MATCHED) {
        printf("** ");
      }
    }
    printf("\n");
  }
}

// Get the input from the player.
int get_input(char* prompt) {
  int input;

  // Print the prompt.
  printf("%s", prompt);

  // Get the input from the player.
  scanf("%d", &input);

  // Return the input.
  return input;
}

// Check if the game is over.
int is_game_over(Card** board) {
  // Loop through the game board.
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      // If a card is not matched, the game is not over.
      if (board[i][j].state != CARD_STATE_MATCHED) {
        return 0;
      }
    }
  }

  // If all cards are matched, the game is over.
  return 1;
}

// Main game loop.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Create the game board.
  Card** board = create_board();

  // Print the game board.
  print_board(board);

  // Main game loop.
  while (!is_game_over(board)) {
    // Get the input from the player.
    int row1 = get_input("Enter the row of the first card: ");
    int col1 = get_input("Enter the column of the first card: ");
    int row2 = get_input("Enter the row of the second card: ");
    int col2 = get_input("Enter the column of the second card: ");

    // Check if the cards match.
    if (board[row1][col1].type == board[row2][col2].type) {
      // The cards match.
      board[row1][col1].state = CARD_STATE_MATCHED;
      board[row2][col2].state = CARD_STATE_MATCHED;
    } else {
      // The cards do not match.
      board[row1][col1].state = CARD_STATE_HIDDEN;
      board[row2][col2].state = CARD_STATE_HIDDEN;
    }

    // Print the game board.
    print_board(board);
  }

  // The game is over.
  printf("Congratulations! You won the game!\n");

  // Free the memory allocated for the game board.
  free_board(board);

  // Return 0 to indicate that the program ran successfully.
  return 0;
}