//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of user input
#define MAX_INPUT_LENGTH 100

// Define the game world
typedef struct {
  char *name;
  char *description;
  struct room *north;
  struct room *east;
  struct room *south;
  struct room *west;
} room;

// Define the player
typedef struct {
  char *name;
  struct room *current_room;
  int health;
} player;

// Define the game state
typedef struct {
  player *player;
  room *current_room;
} game_state;

// Create a new room
room *create_room(char *name, char *description) {
  room *new_room = malloc(sizeof(room));
  new_room->name = strdup(name);
  new_room->description = strdup(description);
  new_room->north = NULL;
  new_room->east = NULL;
  new_room->south = NULL;
  new_room->west = NULL;
  return new_room;
}

// Create a new player
player *create_player(char *name) {
  player *new_player = malloc(sizeof(player));
  new_player->name = strdup(name);
  new_player->current_room = NULL;
  new_player->health = 100;
  return new_player;
}

// Create a new game state
game_state *create_game_state(player *player, room *current_room) {
  game_state *new_game_state = malloc(sizeof(game_state));
  new_game_state->player = player;
  new_game_state->current_room = current_room;
  return new_game_state;
}

// Free the memory allocated for a room
void free_room(room *room) {
  free(room->name);
  free(room->description);
  free(room);
}

// Free the memory allocated for a player
void free_player(player *player) {
  free(player->name);
  free(player);
}

// Free the memory allocated for a game state
void free_game_state(game_state *game_state) {
  free_player(game_state->player);
  free_room(game_state->current_room);
  free(game_state);
}

// Get the user's input
char *get_user_input() {
  char *input = malloc(MAX_INPUT_LENGTH);
  fgets(input, MAX_INPUT_LENGTH, stdin);
  return input;
}

// Print the game world
void print_game_world(game_state *game_state) {
  printf("%s\n", game_state->current_room->description);
  printf("Exits: ");
  if (game_state->current_room->north != NULL) {
    printf("north ");
  }
  if (game_state->current_room->east != NULL) {
    printf("east ");
  }
  if (game_state->current_room->south != NULL) {
    printf("south ");
  }
  if (game_state->current_room->west != NULL) {
    printf("west ");
  }
  printf("\n");
}

// Process the user's input
void process_user_input(game_state *game_state, char *input) {
  char *command = strtok(input, " ");
  char *argument = strtok(NULL, " ");

  if (strcmp(command, "go") == 0) {
    if (strcmp(argument, "north") == 0 && game_state->current_room->north != NULL) {
      game_state->current_room = game_state->current_room->north;
    } else if (strcmp(argument, "east") == 0 && game_state->current_room->east != NULL) {
      game_state->current_room = game_state->current_room->east;
    } else if (strcmp(argument, "south") == 0 && game_state->current_room->south != NULL) {
      game_state->current_room = game_state->current_room->south;
    } else if (strcmp(argument, "west") == 0 && game_state->current_room->west != NULL) {
      game_state->current_room = game_state->current_room->west;
    } else {
      printf("Invalid direction\n");
    }
  } else if (strcmp(command, "quit") == 0) {
    exit(0);
  } else {
    printf("Invalid command\n");
  }
}

// Play the game
void play_game(game_state *game_state) {
  while (1) {
    print_game_world(game_state);
    char *input = get_user_input();
    process_user_input(game_state, input);
  }
}

// Main function
int main() {
  // Create the game world
  room *room1 = create_room("Room 1", "This is room 1.");
  room *room2 = create_room("Room 2", "This is room 2.");
  room *room3 = create_room("Room 3", "This is room 3.");
  room *room4 = create_room("Room 4", "This is room 4.");

  room1->north = room2;
  room1->east = room3;
  room2->south = room1;
  room2->east = room4;
  room3->west = room1;
  room3->east = room4;
  room4->west = room2;
  room4->south = room3;

  // Create the player
  player *player = create_player("Player 1");

  // Create the game state
  game_state *game_state = create_game_state(player, room1);

  // Play the game
  play_game(game_state);

  // Free the memory allocated for the game
  free_game_state(game_state);

  return 0;
}