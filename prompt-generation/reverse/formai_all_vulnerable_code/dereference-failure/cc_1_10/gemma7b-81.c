//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 10

typedef struct Room {
  int x, y;
  char name[20];
  struct Room* north, *south, *east, *west;
} Room;

Room** generateRooms(int roomCount) {
  Room** rooms = malloc(roomCount * sizeof(Room*));
  for (int i = 0; i < roomCount; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % 10;
    rooms[i]->y = rand() % 10;
    rooms[i]->name[0] = 'A' + i;
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
  }
  return rooms;
}

void connectRooms(Room** rooms) {
  for (int i = 0; i < ROOM_COUNT; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        rooms[i]->north = rooms[rand() % ROOM_COUNT];
        break;
      case 1:
        rooms[i]->south = rooms[rand() % ROOM_COUNT];
        break;
      case 2:
        rooms[i]->east = rooms[rand() % ROOM_COUNT];
        break;
      case 3:
        rooms[i]->west = rooms[rand() % ROOM_COUNT];
        break;
    }
  }
}

int main() {
  srand(time(NULL));
  Room** rooms = generateRooms(ROOM_COUNT);
  connectRooms(rooms);

  // Play the game
  for (int i = 0; i < ROOM_COUNT; i++) {
    printf("You are in room %c.\n", rooms[i]->name[0]);
    if (rooms[i]->north) {
      printf("You can go north to room %c.\n", rooms[i]->north->name[0]);
    }
    if (rooms[i]->south) {
      printf("You can go south to room %c.\n", rooms[i]->south->name[0]);
    }
    if (rooms[i]->east) {
      printf("You can go east to room %c.\n", rooms[i]->east->name[0]);
    }
    if (rooms[i]->west) {
      printf("You can go west to room %c.\n", rooms[i]->west->name[0]);
    }
  }

  return 0;
}