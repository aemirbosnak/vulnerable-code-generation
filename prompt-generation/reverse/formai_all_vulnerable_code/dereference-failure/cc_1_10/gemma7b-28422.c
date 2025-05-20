//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

typedef struct Room {
  int x, y;
  struct Room* up, *right, *down, *left;
} Room;

Room** generateRooms(int numRooms) {
  srand(time(NULL));
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % WIDTH;
    rooms[i]->y = rand() % HEIGHT;
    rooms[i]->up = NULL;
    rooms[i]->right = NULL;
    rooms[i]->down = NULL;
    rooms[i]->left = NULL;
  }
  return rooms;
}

void connectRooms(Room** rooms, int numRooms) {
  for (int i = 0; i < numRooms; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        rooms[i]->up = rooms[rand() % numRooms];
        break;
      case 1:
        rooms[i]->right = rooms[rand() % numRooms];
        break;
      case 2:
        rooms[i]->down = rooms[rand() % numRooms];
        break;
      case 3:
        rooms[i]->left = rooms[rand() % numRooms];
        break;
    }
  }
}

int main() {
  int numRooms = 10;
  Room** rooms = generateRooms(numRooms);
  connectRooms(rooms, numRooms);

  // Print the rooms
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: (%d, %d)\n", i, rooms[i]->x, rooms[i]->y);
  }

  return 0;
}