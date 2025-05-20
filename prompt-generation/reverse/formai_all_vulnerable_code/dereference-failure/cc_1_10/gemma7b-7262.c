//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

int main() {
  int currentRoom = 0;
  char direction;

  // Create an array of rooms
  char **rooms = (char **)malloc(MAX_ROOM * sizeof(char *));
  for (int i = 0; i < MAX_ROOM; i++) {
    rooms[i] = (char *)malloc(10 * sizeof(char));
  }

  // Initialize the rooms
  rooms[0] = "You are in a small room with a single door to the east.";
  rooms[1] = "You are in a grand hall with a statue of a lion.";
  rooms[2] = "You are in a secret chamber with a hidden treasure.";
  rooms[3] = "You are in a dungeon with a dragon.";
  rooms[4] = "You are in a room with a portal to another dimension.";

  // Game loop
  while (1) {
    // Display the current room
    printf("%s", rooms[currentRoom]);

    // Get the direction
    printf("Enter direction (e/w/s/n): ");
    scanf("%c", &direction);

    // Move in the direction
    switch (direction) {
      case 'e':
        currentRoom++;
        break;
      case 'w':
        currentRoom--;
        break;
      case 's':
        currentRoom += MAX_ROOM;
        break;
      case 'n':
        currentRoom -= MAX_ROOM;
        break;
    }

    // Check if the player has reached the end of the game
    if (currentRoom == MAX_ROOM - 1) {
      printf("You have won!");
      break;
    }
  }

  // Free the memory
  for (int i = 0; i < MAX_ROOM; i++) {
    free(rooms[i]);
  }
  free(rooms);

  return 0;
}