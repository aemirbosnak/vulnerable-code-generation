//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define constants for the size of the game board
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

// Define constants for the different types of entities
#define PLAYER 'P'
#define ALIEN 'A'
#define EMPTY ' '

/*
 * Represents an entity on the game board.
 */
typedef struct Entity {
  char type;  // The type of entity, either PLAYER, ALIEN, or EMPTY
  int x, y;   // The location of the entity on the board
  bool alive; // True if the entity is alive, false otherwise
} Entity;

/*
 * Initializes the game board with empty cells, except for the player entity.
 */
void initialize_board(Entity *board[BOARD_WIDTH][BOARD_HEIGHT], Entity *player) {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      if (i == player->x && j == player->y) {
        board[i][j] = player;
      } else {
        Entity *new_entity = malloc(sizeof(Entity));
        new_entity->type = EMPTY;
        new_entity->x = i;
        new_entity->y = j;
        new_entity->alive = false;
        board[i][j] = new_entity;
      }
    }
  }
}

/*
 * Moves the player entity to the left, if possible.
 */
void move_left(Entity *board[BOARD_WIDTH][BOARD_HEIGHT], Entity *player) {
  if (player->x > 0) {
    board[player->x][player->y] = malloc(sizeof(Entity));
    board[player->x][player->y]->type = EMPTY;
    board[player->x][player->y]->x = player->x;
    board[player->x][player->y]->y = player->y;
    board[player->x][player->y]->alive = false;
    player->x--;
    board[player->x][player->y] = player;
  }
}

/*
 * Moves the player entity to the right, if possible.
 */
void move_right(Entity *board[BOARD_WIDTH][BOARD_HEIGHT], Entity *player) {
  if (player->x < BOARD_WIDTH - 1) {
    board[player->x][player->y] = malloc(sizeof(Entity));
    board[player->x][player->y]->type = EMPTY;
    board[player->x][player->y]->x = player->x;
    board[player->x][player->y]->y = player->y;
    board[player->x][player->y]->alive = false;
    player->x++;
    board[player->x][player->y] = player;
  }
}

/*
 * Spawns a new alien entity at a random location on the board.
 */
void spawn_alien(Entity *board[BOARD_WIDTH][BOARD_HEIGHT]) {
  int x = rand() % BOARD_WIDTH;
  int y = rand() % BOARD_HEIGHT;
  Entity *alien = malloc(sizeof(Entity));
  alien->type = ALIEN;
  alien->x = x;
  alien->y = y;
  alien->alive = true;
  board[x][y] = alien;
}

/*
 * Randomly moves each alien entity on the board.
 */
void move_aliens(Entity *board[BOARD_WIDTH][BOARD_HEIGHT]) {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      Entity *entity = board[i][j];
      if (entity->type == ALIEN && entity->alive) {
        int direction = rand() % 4;
        switch (direction) {
          case 0: // Move up
            if (j > 0 && board[i][j-1]->type == EMPTY) {
              board[i][j-1] = entity;
              entity->y--;
              board[i][j] = malloc(sizeof(Entity));
              board[i][j]->type = EMPTY;
              board[i][j]->x = i;
              board[i][j]->y = j;
              board[i][j]->alive = false;
            }
            break;
          case 1: // Move down
            if (j < BOARD_HEIGHT - 1 && board[i][j+1]->type == EMPTY) {
              board[i][j+1] = entity;
              entity->y++;
              board[i][j] = malloc(sizeof(Entity));
              board[i][j]->type = EMPTY;
              board[i][j]->x = i;
              board[i][j]->y = j;
              board[i][j]->alive = false;
            }
            break;
          case 2: // Move left
            if (i > 0 && board[i-1][j]->type == EMPTY) {
              board[i-1][j] = entity;
              entity->x--;
              board[i][j] = malloc(sizeof(Entity));
              board[i][j]->type = EMPTY;
              board[i][j]->x = i;
              board[i][j]->y = j;
              board[i][j]->alive = false;
            }
            break;
          case 3: // Move right
            if (i < BOARD_WIDTH - 1 && board[i+1][j]->type == EMPTY) {
              board[i+1][j] = entity;
              entity->x++;
              board[i][j] = malloc(sizeof(Entity));
              board[i][j]->type = EMPTY;
              board[i][j]->x = i;
              board[i][j]->y = j;
              board[i][j]->alive = false;
            }
            break;
        }
      }
    }
  }
}

/*
 * Updates the game board by spawning new aliens,
 * moving existing aliens, and checking for collisions
 * between the player and aliens.
 */
void update_board(Entity *board[BOARD_WIDTH][BOARD_HEIGHT], Entity *player) {
  spawn_alien(board);
  move_aliens(board);
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      Entity *entity = board[i][j];
      if (entity->type == ALIEN && entity->alive) {
        if (entity->x == player->x && entity->y == player->y) {
          player->alive = false;
        }
      }
    }
  }
}

/*
 * Renders the game board by printing each entity to the console.
 */
void render_board(Entity *board[BOARD_WIDTH][BOARD_HEIGHT]) {
  for (int j = 0; j < BOARD_HEIGHT; j++) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
      printf("%c ", board[i][j]->type);
    }
    printf("\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the player entity
  Entity *player = malloc(sizeof(Entity));
  player->type = PLAYER;
  player->x = BOARD_WIDTH / 2;
  player->y = BOARD_HEIGHT - 1;
  player->alive = true;

  // Create the game board and initialize it
  Entity *board[BOARD_WIDTH][BOARD_HEIGHT];
  initialize_board(board, player);

  // Main game loop
  while (player->alive) {
    // Update and render the game board
    update_board(board, player);
    render_board(board);

    // Get user input and move the player entity accordingly
    char input;
    scanf(" %c", &input);
    if (input == 'a') {
      move_left(board, player);
    } else if (input == 'd') {
      move_right(board, player);
    }
  }

  printf("Game over!\n");

  return 0;
}