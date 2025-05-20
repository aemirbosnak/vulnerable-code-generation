//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Items 5

typedef struct Room {
  char name[20];
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
  struct Item* items;
} Room;

typedef struct Item {
  char name[20];
  int quantity;
} Item;

void generateMaze(Room** rooms) {
  srand(time(NULL));
  int numRooms = rand() % MAX_Rooms + 1;
  rooms = (Room**)malloc(numRooms * sizeof(Room));

  for (int i = 0; i < numRooms; i++) {
    rooms[i] = (Room*)malloc(sizeof(Room));
    rooms[i]->name[0] = '\0';
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
    rooms[i]->items = NULL;
  }

  for (int i = 0; i < numRooms - 1; i++) {
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        rooms[i]->north = rooms[i + 1];
        break;
      case 1:
        rooms[i]->south = rooms[i + 1];
        break;
      case 2:
        rooms[i]->east = rooms[i + 1];
        break;
      case 3:
        rooms[i]->west = rooms[i + 1];
        break;
    }
  }
}

int main() {
  Room** rooms;
  generateMaze(&rooms);

  for (Room* room = rooms[0]; room; room = room->north) {
    printf("%s\n", room->name);
  }

  return 0;
}