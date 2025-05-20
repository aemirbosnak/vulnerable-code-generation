//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 10

typedef struct Room {
  int num;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room* createRoom(int num) {
  Room* room = malloc(sizeof(Room));
  room->num = num;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;

  return room;
}

void generateMaze(int numRooms) {
  time_t t = time(NULL);
  srand(t);

  Room* rooms[numRooms];
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = createRoom(i + 1);
  }

  for (int i = 0; i < numRooms; i++) {
    int direction = rand() % 4;

    switch (direction) {
      case 0:
        rooms[i]->north = rooms[rand() % numRooms];
        break;
      case 1:
        rooms[i]->south = rooms[rand() % numRooms];
        break;
      case 2:
        rooms[i]->east = rooms[rand() % numRooms];
        break;
      case 3:
        rooms[i]->west = rooms[rand() % numRooms];
        break;
    }
  }

  rooms[0]->north = rooms[1];
  rooms[numRooms - 1]->south = rooms[numRooms - 2];
}

int main() {
  generateMaze(MAX_ROOM_NUM);

  return 0;
}