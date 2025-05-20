//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a room
typedef struct Room {
  char* name;
  char* description;
  struct Room* exits[4]; // North, East, South, West
} Room;

// Function to create a new room
Room* createRoom(char* name, char* description) {
  Room* room = malloc(sizeof(Room));
  room->name = strdup(name);
  room->description = strdup(description);
  for (int i = 0; i < 4; i++) {
    room->exits[i] = NULL;
  }
  return room;
}

// Function to connect two rooms
void connectRooms(Room* room1, Room* room2, int direction1, int direction2) {
  room1->exits[direction1] = room2;
  room2->exits[direction2] = room1;
}

// Function to print the description of a room
void printRoom(Room* room) {
  printf("%s\n", room->name);
  printf("%s\n", room->description);
  printf("Exits:");
  for (int i = 0; i < 4; i++) {
    if (room->exits[i] != NULL) {
      printf(" %s", room->exits[i]->name);
    }
  }
  printf("\n");
}

// Function to play the game
void playGame(Room* startingRoom) {
  Room* currentRoom = startingRoom;

  while (1) {
    printRoom(currentRoom);

    char input[80];
    printf("> ");
    fgets(input, 80, stdin);

    if (strcmp(input, "n\n") == 0) {
      currentRoom = currentRoom->exits[0];
    } else if (strcmp(input, "e\n") == 0) {
      currentRoom = currentRoom->exits[1];
    } else if (strcmp(input, "s\n") == 0) {
      currentRoom = currentRoom->exits[2];
    } else if (strcmp(input, "w\n") == 0) {
      currentRoom = currentRoom->exits[3];
    } else if (strcmp(input, "exit\n") == 0) {
      break;
    } else {
      printf("Invalid input\n");
    }
  }
}

// Main function
int main() {
  // Create the rooms
  Room* foyer = createRoom("Foyer", "A large, open room with a high ceiling.");
  Room* livingRoom = createRoom("Living Room", "A cozy room with a fireplace and a large couch.");
  Room* diningRoom = createRoom("Dining Room", "A formal room with a long table and chairs.");
  Room* kitchen = createRoom("Kitchen", "A large room with a stove, oven, and refrigerator.");
  Room* masterBedroom = createRoom("Master Bedroom", "A large room with a king-sized bed and a private bathroom.");
  Room* guestBedroom = createRoom("Guest Bedroom", "A small room with a twin bed and a dresser.");
  Room* bathroom = createRoom("Bathroom", "A small room with a toilet, sink, and shower.");
  Room* attic = createRoom("Attic", "A small, dusty room with a few old boxes.");
  Room* basement = createRoom("Basement", "A dark, damp room with a few old pieces of furniture.");

  // Connect the rooms
  connectRooms(foyer, livingRoom, 1, 1);
  connectRooms(foyer, diningRoom, 2, 2);
  connectRooms(foyer, kitchen, 3, 3);
  connectRooms(livingRoom, masterBedroom, 2, 0);
  connectRooms(livingRoom, guestBedroom, 3, 3);
  connectRooms(diningRoom, kitchen, 1, 3);
  connectRooms(diningRoom, bathroom, 2, 2);
  connectRooms(kitchen, basement, 4, 4);
  connectRooms(masterBedroom, attic, 4, 4);

  // Seed the random number generator
  srand(time(NULL));

  // Start the game
  playGame(foyer);

  return 0;
}