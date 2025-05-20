//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for the game world and player
typedef struct Room {
  char* name;
  char* description;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

typedef struct Player {
  char* name;
  Room* location;
} Player;

// Function to create a new room
Room* createRoom(char* name, char* desc) {
  Room* room = malloc(sizeof(Room));
  room->name = name;
  room->description = desc;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;

  return room;
}

// Function to create the game world
Room* createWorld() {
  Room* livingRoom = createRoom("Living Room", "You are in the living room. There are couches and a TV.");
  Room* kitchen = createRoom("Kitchen", "You are in the kitchen. There is food on the counter and dishes in the sink.");
  Room* bedroom = createRoom("Bedroom", "You are in the bedroom. There is a bed and a dresser.");
  Room* bathroom = createRoom("Bathroom", "You are in the bathroom. There is a sink, toilet, and shower.");

  // Connect the rooms
  livingRoom->east = kitchen;
  kitchen->west = livingRoom;
  livingRoom->north = bedroom;
  bedroom->south = livingRoom;
  bedroom->east = bathroom;
  bathroom->west = bedroom;

  return livingRoom;
}

int main() {

  // Create the game world and player
  Room* world = createWorld();
  Player* player = malloc(sizeof(Player));
  player->name = "John";
  player->location = world;

  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("You are playing as %s.\n", player->name);
  printf("You are currently in the %s.\n", player->location->name);
  printf("%s\n", player->location->description);

  // Game loop
  char input[30];
  while (1) {
    printf("What would you like to do? ");
    fgets(input, 30, stdin);

    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;

    // Check for quit command
    if (strcmp(input, "quit") == 0) {
      printf("Thanks for playing!\n");
      break;
    }
    // Check for movement commands
    else if (strcmp(input, "north") == 0) {
      if (player->location->north != NULL) {
        player->location = player->location->north;
        printf("You move north to the %s.\n", player->location->name);
        printf("%s\n", player->location->description);
      }
      else {
        printf("You can't go that way.\n");
      }
    }
    else if (strcmp(input, "south") == 0) {
      if (player->location->south != NULL) {
        player->location = player->location->south;
        printf("You move south to the %s.\n", player->location->name);
        printf("%s\n", player->location->description);
      }
      else {
        printf("You can't go that way.\n");
      }
    }
    else if (strcmp(input, "east") == 0) {
      if (player->location->east != NULL) {
        player->location = player->location->east;
        printf("You move east to the %s.\n", player->location->name);
        printf("%s\n", player->location->description);
      }
      else {
        printf("You can't go that way.\n");
      }
    }
    else if (strcmp(input, "west") == 0) {
      if (player->location->west != NULL) {
        player->location = player->location->west;
        printf("You move west to the %s.\n", player->location->name);
        printf("%s\n", player->location->description);
      }
      else {
        printf("You can't go that way.\n");
      }
    }
    // Invalid command
    else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}