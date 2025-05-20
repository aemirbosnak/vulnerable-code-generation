//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
  char *name;
  char *description;
  int num_exits;
  int *exits;
} Room;

Room rooms[MAX_ROOMS];

int current_room;

void init_game() {
  // Create the rooms
  rooms[0].name = "The Foyer";
  rooms[0].description = "You are standing in the foyer of a large house. There is a door to the north and a door to the east.";
  rooms[0].num_exits = 2;
  rooms[0].exits = malloc(sizeof(int) * rooms[0].num_exits);
  rooms[0].exits[0] = 1;
  rooms[0].exits[1] = 2;

  rooms[1].name = "The Living Room";
  rooms[1].description = "You are standing in the living room. There is a door to the south and a door to the west.";
  rooms[1].num_exits = 2;
  rooms[1].exits = malloc(sizeof(int) * rooms[1].num_exits);
  rooms[1].exits[0] = 0;
  rooms[1].exits[1] = 3;

  rooms[2].name = "The Dining Room";
  rooms[2].description = "You are standing in the dining room. There is a door to the north.";
  rooms[2].num_exits = 1;
  rooms[2].exits = malloc(sizeof(int) * rooms[2].num_exits);
  rooms[2].exits[0] = 0;

  rooms[3].name = "The Kitchen";
  rooms[3].description = "You are standing in the kitchen. There is a door to the east.";
  rooms[3].num_exits = 1;
  rooms[3].exits = malloc(sizeof(int) * rooms[3].num_exits);
  rooms[3].exits[0] = 1;

  // Set the current room
  current_room = 0;
}

void play_game() {
  while (1) {
    // Display the current room
    printf("%s\n", rooms[current_room].description);

    // Get the player's input
    char input[256];
    printf("> ");
    fgets(input, 256, stdin);

    // Parse the input
    char *verb = strtok(input, " ");
    char *noun = strtok(NULL, " ");

    // Execute the command
    if (strcmp(verb, "go") == 0) {
      if (noun == NULL) {
        printf("Go where?\n");
      } else {
        int exit = atoi(noun);
        if (exit < 0 || exit >= rooms[current_room].num_exits) {
          printf("Invalid exit.\n");
        } else {
          current_room = rooms[current_room].exits[exit];
        }
      }
    } else if (strcmp(verb, "quit") == 0) {
      break;
    } else {
      printf("Invalid command.\n");
    }
  }
}

int main() {
  init_game();
  play_game();
  return 0;
}