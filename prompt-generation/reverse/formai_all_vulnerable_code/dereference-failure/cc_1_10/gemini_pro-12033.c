//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

typedef struct {
  int row, col;
} Position;

typedef struct {
  Position pos;
  int value;
} Card;

Card *cards;
int *board;

void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%2d ", board[i * BOARD_SIZE + j]);
    }
    printf("\n");
  }
}

void shuffle_cards() {
  srand(time(NULL));
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    int j = rand() % (NUM_PAIRS * 2);
    int tmp = cards[i].value;
    cards[i].value = cards[j].value;
    cards[j].value = tmp;
  }
}

void place_cards() {
  int num_placed = 0;
  while (num_placed < NUM_PAIRS * 2) {
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;
    if (board[row * BOARD_SIZE + col] == 0) {
      board[row * BOARD_SIZE + col] = cards[num_placed].value;
      num_placed++;
    }
  }
}

int get_card_value(int row, int col) {
  return board[row * BOARD_SIZE + col];
}

void flip_card(int row, int col) {
  board[row * BOARD_SIZE + col] *= -1;
}

int check_match(int row1, int col1, int row2, int col2) {
  return board[row1 * BOARD_SIZE + col1] == -board[row2 * BOARD_SIZE + col2];
}

int main() {
  // Allocate memory for cards and board
  cards = malloc(sizeof(Card) * NUM_PAIRS * 2);
  board = malloc(sizeof(int) * BOARD_SIZE * BOARD_SIZE);

  // Initialize cards
  for (int i = 0; i < NUM_PAIRS; i++) {
    cards[i].value = i + 1;
    cards[i + NUM_PAIRS].value = i + 1;
  }

  // Shuffle cards
  shuffle_cards();

  // Place cards on board
  place_cards();

  // Print initial board
  print_board();

  // Get user input
  int row1, col1, row2, col2;
  while (1) {
    printf("Enter first card (row, col): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter second card (row, col): ");
    scanf("%d %d", &row2, &col2);

    // Flip cards
    flip_card(row1, col1);
    flip_card(row2, col2);

    // Print board
    print_board();

    // Check if cards match
    if (check_match(row1, col1, row2, col2)) {
      printf("Match!\n");
    } else {
      printf("No match.\n");
    }

    // Check if game is over
    int num_matched = 0;
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
      if (board[i] == 0) {
        num_matched++;
      }
    }
    if (num_matched == BOARD_SIZE * BOARD_SIZE) {
      printf("Game over!\n");
      break;
    }
  }

  // Free memory
  free(cards);
  free(board);

  return 0;
}