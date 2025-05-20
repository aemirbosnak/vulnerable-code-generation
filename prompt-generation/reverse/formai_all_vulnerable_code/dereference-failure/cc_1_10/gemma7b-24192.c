//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
  int x, y;
  struct Room* up, *right, *down, *left;
} Room;

Room* createRoom(int x, int y) {
  Room* room = malloc(sizeof(struct Room));
  room->x = x;
  room->y = y;
  room->up = NULL;
  room->right = NULL;
  room->down = NULL;
  room->left = NULL;
  return room;
}

void generateMap(int width, int height) {
  Room* rooms = NULL;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      rooms = createRoom(x, y);
    }
  }

  // Connect rooms
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      rooms = rooms->up;
      if (rooms) {
        rooms->down = createRoom(x, y);
      }
    }
  }

  // Create exits
  for (int i = 0; i < 5; i++) {
    int x = rand() % width;
    int y = rand() % height;
    rooms = createRoom(x, y);
    rooms->up = NULL;
  }
}

int main() {
  generateMap(10, 10);
  return 0;
}