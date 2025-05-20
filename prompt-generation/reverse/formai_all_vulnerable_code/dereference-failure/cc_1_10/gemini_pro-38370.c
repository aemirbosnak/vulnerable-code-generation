//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

// Define the player's starting position
#define PLAYER_START_X 0
#define PLAYER_START_Y 0

// Define the goal position
#define GOAL_X 9
#define GOAL_Y 9

// Define the obstacles
#define NUM_OBSTACLES 5
int obstacles[NUM_OBSTACLES][2] = {
  {2, 2},
  {4, 4},
  {6, 6},
  {8, 8},
  {4, 6}
};

// Define the player's movement keys
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

// Define the game states
#define STATE_PLAYING 0
#define STATE_WON 1
#define STATE_LOST 2

// Function to initialize the game board
void init_board(char board[BOARD_WIDTH][BOARD_HEIGHT]) {
  // Set all cells to empty
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the player at the starting position
  board[PLAYER_START_X][PLAYER_START_Y] = 'P';

  // Place the goal at the goal position
  board[GOAL_X][GOAL_Y] = 'G';

  // Place the obstacles
  for (int i = 0; i < NUM_OBSTACLES; i++) {
    int x = obstacles[i][0];
    int y = obstacles[i][1];
    board[x][y] = 'O';
  }
}

// Function to print the game board
void print_board(char board[BOARD_WIDTH][BOARD_HEIGHT]) {
  // Print the top border
  printf("+");
  for (int i = 0; i < BOARD_WIDTH; i++) {
    printf("-");
  }
  printf("+\n");

  // Print each row of the board
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    printf("|");
    for (int j = 0; j < BOARD_WIDTH; j++) {
      printf("%c", board[j][i]);
    }
    printf("|\n");
  }

  // Print the bottom border
  printf("+");
  for (int i = 0; i < BOARD_WIDTH; i++) {
    printf("-");
  }
  printf("+\n");
}

// Function to get the player's input
char get_input() {
  // Get a character from the user
  char c = getchar();

  // Convert the character to lowercase
  c = tolower(c);

  // Return the character
  return c;
}

// Function to move the player
void move_player(char board[BOARD_WIDTH][BOARD_HEIGHT], int *x, int *y, char input) {
  // Get the player's current position
  int old_x = *x;
  int old_y = *y;

  // Move the player in the specified direction
  switch (input) {
    case KEY_UP:
      *y -= 1;
      break;
    case KEY_DOWN:
      *y += 1;
      break;
    case KEY_LEFT:
      *x -= 1;
      break;
    case KEY_RIGHT:
      *x += 1;
      break;
  }

  // Check if the player has moved into an obstacle
  if (board[*x][*y] == 'O') {
    // Move the player back to their previous position
    *x = old_x;
    *y = old_y;
  }
}

// Function to check if the player has won
int check_win(int x, int y) {
  // Check if the player is at the goal position
  return x == GOAL_X && y == GOAL_Y;
}

// Function to check if the player has lost
int check_lost(int x, int y) {
  // Check if the player has moved outside of the game board
  return x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT;
}

// Main game loop
int main() {
  // Initialize the game board
  char board[BOARD_WIDTH][BOARD_HEIGHT];
  init_board(board);

  // Get the player's starting position
  int player_x = PLAYER_START_X;
  int player_y = PLAYER_START_Y;

  // Set the game state to playing
  int game_state = STATE_PLAYING;

  // Main game loop
  while (game_state == STATE_PLAYING) {
    // Print the game board
    print_board(board);

    // Get the player's input
    char input = get_input();

    // Move the player
    move_player(board, &player_x, &player_y, input);

    // Check if the player has won
    if (check_win(player_x, player_y)) {
      game_state = STATE_WON;
    }

    // Check if the player has lost
    if (check_lost(player_x, player_y)) {
      game_state = STATE_LOST;
    }
  }

  // Print the game over message
  if (game_state == STATE_WON) {
    printf("You win!\n");
  } else if (game_state == STATE_LOST) {
    printf("You lose!\n");
  }

  return 0;
}