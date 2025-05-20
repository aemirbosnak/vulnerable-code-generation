//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible room types
#define ROOM_TYPE_EMPTY 0
#define ROOM_TYPE_DOOR 1
#define ROOM_TYPE_GHOST 2
#define ROOM_TYPE_EXIT 3

// Define the possible player actions
#define ACTION_MOVE_NORTH 0
#define ACTION_MOVE_EAST 1
#define ACTION_MOVE_SOUTH 2
#define ACTION_MOVE_WEST 3
#define ACTION_LOOK 4
#define ACTION_QUIT 5

// Define the game state
typedef struct {
  int player_x;
  int player_y;
  int room_type[10][10];
  int num_ghosts;
  int ghosts_x[10];
  int ghosts_y[10];
} game_state;

// Create a new game state
game_state* create_game_state() {
  game_state* state = malloc(sizeof(game_state));
  state->player_x = 0;
  state->player_y = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      state->room_type[i][j] = ROOM_TYPE_EMPTY;
    }
  }
  state->num_ghosts = 0;
  for (int i = 0; i < 10; i++) {
    state->ghosts_x[i] = -1;
    state->ghosts_y[i] = -1;
  }
  return state;
}

// Free a game state
void free_game_state(game_state* state) {
  free(state);
}

// Generate a random room type
int generate_room_type() {
  int r = rand() % 100;
  if (r < 10) {
    return ROOM_TYPE_DOOR;
  } else if (r < 20) {
    return ROOM_TYPE_GHOST;
  } else if (r < 30) {
    return ROOM_TYPE_EXIT;
  } else {
    return ROOM_TYPE_EMPTY;
  }
}

// Generate a new game state with a random layout
game_state* generate_random_game_state() {
  game_state* state = create_game_state();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      state->room_type[i][j] = generate_room_type();
    }
  }
  state->num_ghosts = rand() % 5 + 1;
  for (int i = 0; i < state->num_ghosts; i++) {
    int x, y;
    do {
      x = rand() % 10;
      y = rand() % 10;
    } while (state->room_type[x][y] != ROOM_TYPE_EMPTY);
    state->ghosts_x[i] = x;
    state->ghosts_y[i] = y;
  }
  return state;
}

// Print the game state to the console
void print_game_state(game_state* state) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (state->player_x == i && state->player_y == j) {
        printf("P");
      } else if (state->room_type[i][j] == ROOM_TYPE_DOOR) {
        printf("D");
      } else if (state->room_type[i][j] == ROOM_TYPE_GHOST) {
        printf("G");
      } else if (state->room_type[i][j] == ROOM_TYPE_EXIT) {
        printf("E");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Move the player in the specified direction
int move_player(game_state* state, int direction) {
  switch (direction) {
    case ACTION_MOVE_NORTH:
      if (state->player_y > 0) {
        state->player_y--;
        return 0;
      }
      break;
    case ACTION_MOVE_EAST:
      if (state->player_x < 9) {
        state->player_x++;
        return 0;
      }
      break;
    case ACTION_MOVE_SOUTH:
      if (state->player_y < 9) {
        state->player_y++;
        return 0;
      }
      break;
    case ACTION_MOVE_WEST:
      if (state->player_x > 0) {
        state->player_x--;
        return 0;
      }
      break;
  }
  return -1;
}

// Check if the player is in a room with a ghost
int check_for_ghost(game_state* state) {
  for (int i = 0; i < state->num_ghosts; i++) {
    if (state->player_x == state->ghosts_x[i] && state->player_y == state->ghosts_y[i]) {
      return 1;
    }
  }
  return 0;
}

// Check if the player is in the exit room
int check_for_exit(game_state* state) {
  return state->room_type[state->player_x][state->player_y] == ROOM_TYPE_EXIT;
}

// Play the game
int play_game(game_state* state) {
  int game_over = 0;
  while (!game_over) {
    // Print the game state
    print_game_state(state);

    // Get the player's input
    int action;
    printf("Enter an action (0: move north, 1: move east, 2: move south, 3: move west, 4: look, 5: quit): ");
    scanf("%d", &action);

    // Perform the player's action
    switch (action) {
      case ACTION_MOVE_NORTH:
      case ACTION_MOVE_EAST:
      case ACTION_MOVE_SOUTH:
      case ACTION_MOVE_WEST:
        if (move_player(state, action) == -1) {
          printf("You cannot move in that direction.\n");
        }
        break;
      case ACTION_LOOK:
        if (check_for_ghost(state)) {
          printf("You see a ghost!\n");
        } else if (check_for_exit(state)) {
          printf("You see the exit!\n");
        } else {
          printf("You see nothing.\n");
        }
        break;
      case ACTION_QUIT:
        game_over = 1;
        break;
    }

    // Check if the player has won or lost the game
    if (check_for_ghost(state)) {
      printf("You have been caught by a ghost!\n");
      game_over = 1;
    } else if (check_for_exit(state)) {
      printf("You have found the exit!\n");
      game_over = 1;
    }
  }

  // Free the game state
  free_game_state(state);

  return 0;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random game state
  game_state* state = generate_random_game_state();

  // Play the game
  play_game(state);

  return 0;
}