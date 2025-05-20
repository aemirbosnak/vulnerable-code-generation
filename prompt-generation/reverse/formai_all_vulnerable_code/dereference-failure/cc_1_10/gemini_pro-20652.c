//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16
#define NUM_ROWS 4
#define NUM_COLS 4

// Card struct
typedef struct card {
  int id;
  int state; // 0 = hidden, 1 = revealed
} card;

// Game struct
typedef struct game {
  card deck[NUM_CARDS];
  int board[NUM_ROWS][NUM_COLS];
} game;

// Function to create a new game
game* new_game() {
  game* g = malloc(sizeof(game));

  // Create the deck of cards
  for (int i = 0; i < NUM_CARDS; i++) {
    g->deck[i].id = i / 2;
    g->deck[i].state = 0;
  }

  // Shuffle the deck
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;
    card temp = g->deck[i];
    g->deck[i] = g->deck[j];
    g->deck[j] = temp;
  }

  // Create the board
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      g->board[i][j] = -1;
    }
  }

  return g;
}

// Function to print the game board
void print_board(game* g) {
  printf("  ");
  for (int i = 0; i < NUM_COLS; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  for (int i = 0; i < NUM_ROWS; i++) {
    printf("%2d ", i);
    for (int j = 0; j < NUM_COLS; j++) {
      if (g->board[i][j] == -1) {
        printf("## ");
      } else {
        printf("%2d ", g->deck[g->board[i][j]].id);
      }
    }
    printf("\n");
  }
}

// Function to get a valid move from the player
int get_move(game* g) {
  int row, col;

  do {
    printf("Enter the row and column of the card you want to reveal (e.g. 0 3): ");
    scanf("%d %d", &row, &col);
  } while (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || g->board[row][col] != -1);

  return row * NUM_COLS + col;
}

// Function to check if the game is over
int game_over(game* g) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (g->board[i][j] == -1) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to play the game
void play_game(game* g) {
  int move1, move2;
  int score = 0;

  while (!game_over(g)) {
    // Get the first move
    move1 = get_move(g);

    // Reveal the first card
    g->board[move1 / NUM_COLS][move1 % NUM_COLS] = move1;

    // Print the board
    print_board(g);

    // Get the second move
    move2 = get_move(g);

    // Reveal the second card
    g->board[move2 / NUM_COLS][move2 % NUM_COLS] = move2;

    // Print the board
    print_board(g);

    // Check if the cards match
    if (g->deck[move1].id == g->deck[move2].id) {
      printf("Match!\n");
      score++;
    } else {
      printf("No match.\n");
    }

    // Hide the cards
    g->board[move1 / NUM_COLS][move1 % NUM_COLS] = -1;
    g->board[move2 / NUM_COLS][move2 % NUM_COLS] = -1;
  }

  printf("Game over! Your score is %d.\n", score);
}

// Main function
int main() {
  // Create a new game
  game* g = new_game();

  // Print the board
  print_board(g);

  // Play the game
  play_game(g);

  // Free the game memory
  free(g);

  return 0;
}