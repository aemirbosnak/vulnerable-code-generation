//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room* generateRooms() {
  int numRooms = rand() % 10 + 10;
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % WIDTH;
    rooms[i]->y = rand() % HEIGHT;
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
  }
  return rooms[0];
}

void playGame() {
  Room* currentRoom = generateRooms();
  while (1) {
    printf("You are in room (%d, %d).\n", currentRoom->x, currentRoom->y);
    printf("What direction do you want to go (n/s/e/w)? ");
    char direction = getchar();
    switch (direction) {
      case 'n':
        currentRoom = currentRoom->north;
        break;
      case 's':
        currentRoom = currentRoom->south;
        break;
      case 'e':
        currentRoom = currentRoom->east;
        break;
      case 'w':
        currentRoom = currentRoom->west;
        break;
      default:
        printf("Invalid direction.\n");
    }
    if (currentRoom == NULL) {
      printf("You have died. Game over.\n");
      break;
    }
  }
}

int main() {
  playGame();
  return 0;
}