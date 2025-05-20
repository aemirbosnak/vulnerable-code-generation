//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the table
#define ROWS 10
#define COLS 10

// Define the different types of tiles
typedef enum {
  EMPTY,
  PLAYER,
  ENEMY,
  WALL
} TileType;

// Define the structure of a tile
typedef struct {
  TileType type;
  int value;
} Tile;

// Define the structure of the game board
typedef struct {
  Tile tiles[ROWS][COLS];
} Board;

// Define the structure of the player
typedef struct {
  int row;
  int col;
  int health;
  int attack;
} Player;

// Define the structure of the enemy
typedef struct {
  int row;
  int col;
  int health;
  int attack;
} Enemy;

// Create a new game board
Board* create_board() {
  Board* board = malloc(sizeof(Board));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board->tiles[i][j].type = EMPTY;
      board->tiles[i][j].value = 0;
    }
  }
  return board;
}

// Create a new player
Player* create_player(int row, int col) {
  Player* player = malloc(sizeof(Player));
  player->row = row;
  player->col = col;
  player->health = 100;
  player->attack = 10;
  return player;
}

// Create a new enemy
Enemy* create_enemy(int row, int col) {
  Enemy* enemy = malloc(sizeof(Enemy));
  enemy->row = row;
  enemy->col = col;
  enemy->health = 100;
  enemy->attack = 10;
  return enemy;
}

// Place the player on the game board
void place_player(Board* board, Player* player) {
  board->tiles[player->row][player->col].type = PLAYER;
}

// Place the enemy on the game board
void place_enemy(Board* board, Enemy* enemy) {
  board->tiles[enemy->row][enemy->col].type = ENEMY;
}

// Print the game board
void print_board(Board* board) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      switch (board->tiles[i][j].type) {
        case EMPTY:
          printf(" ");
          break;
        case PLAYER:
          printf("P");
          break;
        case ENEMY:
          printf("E");
          break;
        case WALL:
          printf("W");
          break;
      }
    }
    printf("\n");
  }
}

// Check if the given position is valid
int is_valid_position(Board* board, int row, int col) {
  return row >= 0 && row < ROWS && col >= 0 && col < COLS && board->tiles[row][col].type != WALL;
}

// Move the player in the given direction
void move_player(Board* board, Player* player, int direction) {
  int new_row = player->row;
  int new_col = player->col;
  switch (direction) {
    case 'w':
      new_row--;
      break;
    case 'a':
      new_col--;
      break;
    case 's':
      new_row++;
      break;
    case 'd':
      new_col++;
      break;
  }
  if (is_valid_position(board, new_row, new_col)) {
    board->tiles[player->row][player->col].type = EMPTY;
    player->row = new_row;
    player->col = new_col;
    board->tiles[player->row][player->col].type = PLAYER;
  }
}

// Attack the enemy in the given direction
void attack_enemy(Board* board, Player* player, int direction) {
  int new_row = player->row;
  int new_col = player->col;
  switch (direction) {
    case 'w':
      new_row--;
      break;
    case 'a':
      new_col--;
      break;
    case 's':
      new_row++;
      break;
    case 'd':
      new_col++;
      break;
  }
  if (is_valid_position(board, new_row, new_col) && board->tiles[new_row][new_col].type == ENEMY) {
    Enemy* enemy = (Enemy*)board->tiles[new_row][new_col].value;
    enemy->health -= player->attack;
    if (enemy->health <= 0) {
      board->tiles[new_row][new_col].type = EMPTY;
      free(enemy);
    }
  }
}

// Main game loop
int main() {
  // Create a new game board
  Board* board = create_board();
  
  // Create a new player
  Player* player = create_player(0, 0);
  
  // Place the player on the game board
  place_player(board, player);
  
  // Create a new enemy
  Enemy* enemy = create_enemy(4, 4);
  
  // Place the enemy on the game board
  place_enemy(board, enemy);
  
  // Print the game board
  print_board(board);
  
  // Main game loop
  while (1) {
    // Get the player's input
    char input = getchar();
    
    // Move the player in the given direction
    move_player(board, player, input);
    
    // Attack the enemy in the given direction
    attack_enemy(board, player, input);
    
    // Print the game board
    print_board(board);
  }
  
  return 0;
}