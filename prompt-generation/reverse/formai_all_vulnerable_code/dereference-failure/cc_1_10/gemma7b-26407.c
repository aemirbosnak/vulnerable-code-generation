//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room {
  char name[20];
  struct Room* next;
} Room;

void createRoom(char* name) {
  Room* newRoom = malloc(sizeof(Room));
  strcpy(newRoom->name, name);
  newRoom->next = NULL;
}

void connectRooms(Room* room1, Room* room2) {
  room1->next = room2;
}

int main() {
  Room* rooms[MAX_ROOM];

  createRoom("The Foyer");
  createRoom("The Living Room");
  createRoom("The Kitchen");
  createRoom("The Bedroom");
  createRoom("The Bathroom");

  connectRooms(rooms[0], rooms[1]);
  connectRooms(rooms[1], rooms[2]);
  connectRooms(rooms[2], rooms[3]);
  connectRooms(rooms[3], rooms[4]);
  connectRooms(rooms[4], rooms[0]);

  // Player starts in The Foyer
  Room* currentRoom = rooms[0];

  // Game loop
  while (1) {
    // Display room information
    printf("You are in %s.\n", currentRoom->name);

    // Get player input
    char input[20];
    printf("What do you want to do? ");
    scanf("%s", input);

    // Check if player wants to go to another room
    if (strcmp(input, "go") == 0) {
      // Get the direction the player wants to go
      char direction[20];
      printf("What direction do you want to go? ");
      scanf("%s", direction);

      // Check if the direction is valid
      if (strcmp(direction, "north") == 0 || strcmp(direction, "south") == 0 || strcmp(direction, "east") == 0 || strcmp(direction, "west") == 0) {
        // Move to the next room
        currentRoom = currentRoom->next;
      } else {
        printf("Invalid direction.\n");
      }
    }

    // Check if the player wants to quit
    else if (strcmp(input, "quit") == 0) {
      // Quit the game
      break;
    } else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}