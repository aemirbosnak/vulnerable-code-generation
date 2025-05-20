//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the player's stats
struct Player {
  char *name;
  int health;
  int attack;
  int defense;
};

// Define the game world
struct World {
  char *name;
  char **locations;
  int num_locations;
};

// Define the game
struct Game {
  struct Player player;
  struct World world;
};

// Create a new game
struct Game *new_game(char *player_name, char *world_name) {
  struct Game *game = malloc(sizeof(struct Game));
  game->player.name = strdup(player_name);
  game->player.health = 100;
  game->player.attack = 10;
  game->player.defense = 10;
  game->world.name = strdup(world_name);
  game->world.locations = malloc(sizeof(char *) * 10);
  game->world.num_locations = 0;
  return game;
}

// Add a location to the game world
void add_location(struct Game *game, char *location_name) {
  game->world.locations[game->world.num_locations++] = strdup(location_name);
}

// Print the game's world
void print_world(struct Game *game) {
  printf("The world of %s contains the following locations:\n", game->world.name);
  for (int i = 0; i < game->world.num_locations; i++) {
    printf("  %s\n", game->world.locations[i]);
  }
}

// Play the game
void play_game(struct Game *game) {
  // Print the game's world
  print_world(game);

  // Get the player's input
  char input[100];
  printf("> ");
  scanf("%s", input);

  // Handle the player's input
  if (strcmp(input, "quit") == 0) {
    // Quit the game
    printf("Thanks for playing!\n");
    exit(0);
  } else if (strcmp(input, "look") == 0) {
    // Look around the current location
    printf("You are in %s.\n", game->world.locations[0]);
  } else if (strcmp(input, "go") == 0) {
    // Go to a different location
    char location[100];
    printf("Where do you want to go? ");
    scanf("%s", location);
    for (int i = 0; i < game->world.num_locations; i++) {
      if (strcmp(location, game->world.locations[i]) == 0) {
        // Go to the specified location
        printf("You are now in %s.\n", location);
        break;
      }
    }
  } else {
    // Print an error message
    printf("I don't understand that command.\n");
  }

  // Play the game again
  play_game(game);
}

// Free the game's memory
void free_game(struct Game *game) {
  free(game->player.name);
  free(game->world.name);
  for (int i = 0; i < game->world.num_locations; i++) {
    free(game->world.locations[i]);
  }
  free(game->world.locations);
  free(game);
}

int main() {
  // Create a new game
  struct Game *game = new_game("Alan Turing", "The Turing Machine");

  // Add some locations to the game world
  add_location(game, "The Enigma Machine");
  add_location(game, "The Bombe");
  add_location(game, "The Colossus");

  // Play the game
  play_game(game);

  // Free the game's memory
  free_game(game);

  return 0;
}