//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a room in the haunted house.
typedef struct room {
  char* name;  // The name of the room.
  char* description;  // A description of the room.
  struct room* north;  // The room to the north.
  struct room* east;  // The room to the east.
  struct room* south;  // The room to the south.
  struct room* west;  // The room to the west.
} room;

// Create a new room with the given name and description.
room* create_room(char* name, char* description) {
  room* new_room = malloc(sizeof(room));
  new_room->name = name;
  new_room->description = description;
  new_room->north = NULL;
  new_room->east = NULL;
  new_room->south = NULL;
  new_room->west = NULL;
  return new_room;
}

// Connect two rooms together.
void connect_rooms(room* room1, room* room2, char direction) {
  switch (direction) {
    case 'n':
      room1->north = room2;
      room2->south = room1;
      break;
    case 'e':
      room1->east = room2;
      room2->west = room1;
      break;
    case 's':
      room1->south = room2;
      room2->north = room1;
      break;
    case 'w':
      room1->west = room2;
      room2->east = room1;
      break;
  }
}

// Generate a random haunted house.
room* generate_haunted_house(int num_rooms) {
  // Create the first room.
  room* start_room = create_room("Foyer", "You are standing in the foyer of a large, dark house. The air is thick with tension.");

  // Create the remaining rooms.
  room* rooms[num_rooms];
  for (int i = 0; i < num_rooms; i++) {
    char* names[] = {"Living Room", "Kitchen", "Dining Room", "Bedroom", "Bathroom", "Study", "Library", "Attic", "Basement", "Cellar"};
    char* descriptions[] = {
        "You are standing in a large, open living room. The furniture is old and dusty.",
        "You are standing in a small, cramped kitchen. The walls are covered in grease.",
        "You are standing in a large, formal dining room. The table is set for dinner.",
        "You are standing in a small, cozy bedroom. The bed is unmade.",
        "You are standing in a small, tiled bathroom. The sink is cracked.",
        "You are standing in a large, dusty study. The bookshelves are filled with old books.",
        "You are standing in a large, well-lit library. The shelves are filled with books from floor to ceiling.",
        "You are standing in a small, dusty attic. The air is filled with the smell of mothballs.",
        "You are standing in a dark, damp basement. The floor is covered in cobwebs.",
        "You are standing in a small, windowless cellar. The walls are made of stone."};
    rooms[i] = create_room(names[rand() % 10], descriptions[rand() % 10]);
  }

  // Connect the rooms together randomly.
  for (int i = 0; i < num_rooms; i++) {
    int num_connections = rand() % 4;
    for (int j = 0; j < num_connections; j++) {
      int direction = rand() % 4;
      room* room1 = rooms[i];
      room* room2 = rooms[rand() % num_rooms];
      connect_rooms(room1, room2, direction);
    }
  }

  // Return the starting room.
  return start_room;
}

// Play the haunted house simulator.
void play_game(room* start_room) {
  // Start the player in the starting room.
  room* current_room = start_room;

  // Loop until the player quits or dies.
  while (1) {
    // Print the description of the current room.
    printf("%s\n", current_room->description);

    // Get the player's input.
    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    // Parse the player's input.
    char command[80];
    char argument[80];
    sscanf(input, "%s %s", command, argument);

    // Execute the player's command.
    if (strcmp(command, "quit") == 0) {
      // Quit the game.
      break;
    } else if (strcmp(command, "go") == 0) {
      // Move to the specified room.
      if (strcmp(argument, "north") == 0) {
        current_room = current_room->north;
      } else if (strcmp(argument, "east") == 0) {
        current_room = current_room->east;
      } else if (strcmp(argument, "south") == 0) {
        current_room = current_room->south;
      } else if (strcmp(argument, "west") == 0) {
        current_room = current_room->west;
      } else {
        printf("Invalid direction.\n");
      }
    } else {
      printf("Invalid command.\n");
    }
  }
}

// Main function.
int main() {
  // Set the random seed.
  srand(time(NULL));

  // Generate a random haunted house.
  room* start_room = generate_haunted_house(10);

  // Play the haunted house simulator.
  play_game(start_room);

  return 0;
}