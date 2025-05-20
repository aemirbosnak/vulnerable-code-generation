//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_MONSTER_COUNT 5

typedef struct Room {
  int x, y;
  int monsters;
  struct Room* north, *south, *east, *west;
} Room;

Room* generate_room(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->monsters = rand() % MAX_MONSTER_COUNT;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

void connect_rooms(Room* room1, Room* room2) {
  room1->east = room2;
  room2->west = room1;
}

int main() {
  srand(time(NULL));
  Room* start = generate_room(0, 0);
  Room* current = start;

  // Explore the dungeon...
  while (current) {
    // Fight the monsters...
    for (int i = 0; i < current->monsters; i++) {
      // ...
    }

    // Go to the next room...
    if (current->north) {
      current = current->north;
    } else if (current->south) {
      current = current->south;
    } else if (current->east) {
      current = current->east;
    } else if (current->west) {
      current = current->west;
    } else {
      // You're dead!
      break;
    }
  }

  // You win!
  printf("Congratulations!");

  return 0;
}