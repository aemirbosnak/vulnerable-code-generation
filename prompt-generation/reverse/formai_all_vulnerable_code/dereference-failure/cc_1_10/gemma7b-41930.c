//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room* createRoom() {
  Room* room = malloc(sizeof(Room));
  room->x = rand() % MAP_WIDTH;
  room->y = rand() % MAP_HEIGHT;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

void connectRooms(Room* a, Room* b) {
  a->east = b;
  b->west = a;
}

int main() {
  srand(time(NULL));

  Room* start = createRoom();
  Room* end = createRoom();

  connectRooms(start, end);

  // Traverse the dungeon
  Room* current = start;
  while (current) {
    // Print the room's location
    printf("You are in room (%d, %d).\n", current->x, current->y);

    // Move in a direction
    char direction = getchar();

    // Go to the next room
    switch (direction) {
      case 'n':
        current = current->north;
        break;
      case 's':
        current = current->south;
        break;
      case 'e':
        current = current->east;
        break;
      case 'w':
        current = current->west;
        break;
    }
  }

  // You have reached the end of the dungeon
  printf("You have reached the end of the dungeon!");

  return 0;
}