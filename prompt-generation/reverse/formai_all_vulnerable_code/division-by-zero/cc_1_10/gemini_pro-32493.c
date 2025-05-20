//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the game board size
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

// Define the player and enemy types
typedef enum {
  PLAYER,
  ENEMY
} EntityType;

// Define the entity struct
typedef struct {
  EntityType type;
  int x;
  int y;
} Entity;

// Define the game board
char board[BOARD_WIDTH][BOARD_HEIGHT];

// Define the player and enemy entities
Entity player;
Entity enemy;

// Define the game state
bool game_over = false;

// Function to initialize the game board
void init_board() {
  // Initialize the board with empty spaces
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      board[i][j] = ' ';
    }
  }

  // Place the player in the center of the board
  player.x = BOARD_WIDTH / 2;
  player.y = BOARD_HEIGHT / 2;
  board[player.x][player.y] = '@';

  // Place the enemy in a random location on the board
  srand(time(NULL));
  enemy.x = rand() % BOARD_WIDTH;
  enemy.y = rand() % BOARD_HEIGHT;
  board[enemy.x][enemy.y] = 'E';
}

// Function to print the game board
void print_board() {
  // Print the top border of the board
  printf("  +---+---+---+---+---+---+---+---+---+---+\n");

  // Print each row of the board
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    printf("%d ", i + 1);  // Print the row number
    for (int j = 0; j < BOARD_WIDTH; j++) {
      printf("| %c ", board[j][i]);  // Print the cell
    }
    printf("|\n");  // Print the end of the row
  }

  // Print the bottom border of the board
  printf("  +---+---+---+---+---+---+---+---+---+---+\n");
}

// Function to handle player input
void handle_input() {
  // Get the player's input
  char input = getchar();

  // Move the player based on the input
  switch (input) {
    case 'w':
      player.y--;
      break;
    case 's':
      player.y++;
      break;
    case 'a':
      player.x--;
      break;
    case 'd':
      player.x++;
      break;
  }

  // Keep the player within the bounds of the board
  if (player.x < 0) {
    player.x = 0;
  } else if (player.x >= BOARD_WIDTH) {
    player.x = BOARD_WIDTH - 1;
  }
  if (player.y < 0) {
    player.y = 0;
  } else if (player.y >= BOARD_HEIGHT) {
    player.y = BOARD_HEIGHT - 1;
  }

  // Update the game board
  board[player.x][player.y] = '@';
}

// Function to move the enemy
void move_enemy() {
  // Get the direction to the player
  int dx = player.x - enemy.x;
  int dy = player.y - enemy.y;

  // Move the enemy in that direction
  enemy.x += dx / abs(dx);
  enemy.y += dy / abs(dy);

  // Keep the enemy within the bounds of the board
  if (enemy.x < 0) {
    enemy.x = 0;
  } else if (enemy.x >= BOARD_WIDTH) {
    enemy.x = BOARD_WIDTH - 1;
  }
  if (enemy.y < 0) {
    enemy.y = 0;
  } else if (enemy.y >= BOARD_HEIGHT) {
    enemy.y = BOARD_HEIGHT - 1;
  }

  // Update the game board
  board[enemy.x][enemy.y] = 'E';
}

// Function to check for collisions
void check_collisions() {
  // Check if the player and enemy have collided
  if (player.x == enemy.x && player.y == enemy.y) {
    game_over = true;
  }
}

// Function to play the game
void play_game() {
  // Initialize the game board
  init_board();

  // Main game loop
  while (!game_over) {
    // Print the game board
    print_board();

    // Handle player input
    handle_input();

    // Move the enemy
    move_enemy();

    // Check for collisions
    check_collisions();
  }
}

// Main function
int main() {
  // Play the game
  play_game();

  return 0;
}