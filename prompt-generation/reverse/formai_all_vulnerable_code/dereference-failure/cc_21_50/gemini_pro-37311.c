//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: relaxed
// A text adventure game inspired by "The Hitchhiker's Guide to the Galaxy".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The player's current location.
char *location = "Earth";

// The player's inventory.
char *inventory[10];
int inventory_size = 0;

// The list of possible commands.
char *commands[] = {
  "north", "south", "east", "west",
  "look", "take", "drop", "inventory"
};

// The game's main loop.
int main() {
  // Print the game's introduction.
  printf("You are Arthur Dent, a human from Earth. One day, your planet is destroyed by the Vogons to make way for a hyperspace bypass.\n");
  printf("You are rescued by Ford Prefect, a human from a distant planet, and together you travel the galaxy in search of adventure.\n");

  // Game loop.
  while (1) {
    // Get the player's input.
    char input[100];
    printf("> ");
    scanf("%s", input);

    // Parse the player's input.
    char *command = strtok(input, " ");
    char *argument = strtok(NULL, " ");

    // Execute the player's command.
    if (strcmp(command, "north") == 0) {
      if (strcmp(location, "Earth") == 0) {
        printf("You are now in orbit around Earth.\n");
        location = "Earth Orbit";
      } else if (strcmp(location, "Earth Orbit") == 0) {
        printf("You are now on the Heart of Gold.\n");
        location = "Heart of Gold";
      } else {
        printf("You cannot go north from here.\n");
      }
    } else if (strcmp(command, "south") == 0) {
      if (strcmp(location, "Heart of Gold") == 0) {
        printf("You are now in orbit around Earth.\n");
        location = "Earth Orbit";
      } else if (strcmp(location, "Earth Orbit") == 0) {
        printf("You are now on Earth.\n");
        location = "Earth";
      } else {
        printf("You cannot go south from here.\n");
      }
    } else if (strcmp(command, "east") == 0) {
      if (strcmp(location, "Earth Orbit") == 0) {
        printf("You are now on the Moon.\n");
        location = "Moon";
      } else {
        printf("You cannot go east from here.\n");
      }
    } else if (strcmp(command, "west") == 0) {
      if (strcmp(location, "Moon") == 0) {
        printf("You are now in orbit around Earth.\n");
        location = "Earth Orbit";
      } else {
        printf("You cannot go west from here.\n");
      }
    } else if (strcmp(command, "look") == 0) {
      if (strcmp(location, "Earth") == 0) {
        printf("You are on Earth. It is a blue planet with a green atmosphere.\n");
      } else if (strcmp(location, "Earth Orbit") == 0) {
        printf("You are in orbit around Earth. It is a blue planet with a green atmosphere.\n");
      } else if (strcmp(location, "Heart of Gold") == 0) {
        printf("You are on the Heart of Gold. It is a spaceship.\n");
      } else if (strcmp(location, "Moon") == 0) {
        printf("You are on the Moon. It is a gray planet with no atmosphere.\n");
      }
    } else if (strcmp(command, "take") == 0) {
      if (argument == NULL) {
        printf("What do you want to take?\n");
      } else if (strcmp(location, "Earth") == 0) {
        if (strcmp(argument, "towel") == 0) {
          inventory[inventory_size++] = "towel";
          printf("You have taken a towel.\n");
        } else {
          printf("There is no %s here.\n", argument);
        }
      } else if (strcmp(location, "Earth Orbit") == 0) {
        if (strcmp(argument, "spacesuit") == 0) {
          inventory[inventory_size++] = "spacesuit";
          printf("You have taken a spacesuit.\n");
        } else {
          printf("There is no %s here.\n", argument);
        }
      } else if (strcmp(location, "Heart of Gold") == 0) {
        if (strcmp(argument, "sonic screwdriver") == 0) {
          inventory[inventory_size++] = "sonic screwdriver";
          printf("You have taken a sonic screwdriver.\n");
        } else {
          printf("There is no %s here.\n", argument);
        }
      } else if (strcmp(location, "Moon") == 0) {
        if (strcmp(argument, "moon rock") == 0) {
          inventory[inventory_size++] = "moon rock";
          printf("You have taken a moon rock.\n");
        } else {
          printf("There is no %s here.\n", argument);
        }
      }
    } else if (strcmp(command, "drop") == 0) {
      if (argument == NULL) {
        printf("What do you want to drop?\n");
      } else {
        int i;
        for (i = 0; i < inventory_size; i++) {
          if (strcmp(inventory[i], argument) == 0) {
            inventory[i] = inventory[inventory_size - 1];
            inventory_size--;
            printf("You have dropped a %s.\n", argument);
            break;
          }
        }
        if (i == inventory_size) {
          printf("You do not have a %s.\n", argument);
        }
      }
    } else if (strcmp(command, "inventory") == 0) {
      if (inventory_size == 0) {
        printf("You have no items in your inventory.\n");
      } else {
        int i;
        printf("Your inventory:\n");
        for (i = 0; i < inventory_size; i++) {
          printf("  %s\n", inventory[i]);
        }
      }
    } else {
      printf("I do not understand that command.\n");
    }
  }

  return 0;
}