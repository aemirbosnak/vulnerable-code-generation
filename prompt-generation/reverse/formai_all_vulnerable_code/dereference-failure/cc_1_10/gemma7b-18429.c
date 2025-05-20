//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_Rooms 10

typedef struct Room {
  int number;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room* createRoom(int number) {
  Room* room = malloc(sizeof(Room));
  room->number = number;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

void connectRooms(Room* room1, Room* room2) {
  room1->east = room2;
  room2->west = room1;
}

void generateMaze(int numRooms) {
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = createRoom(i + 1);
  }

  int numConnections = rand() % (numRooms - 1) + 1;
  for (int i = 0; i < numConnections; i++) {
    connectRooms(rooms[rand() % numRooms], rooms[rand() % numRooms]);
  }

  // Print the maze
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: ", rooms[i]->number);
    if (rooms[i]->north) {
      printf("North to Room %d\n", rooms[i]->north->number);
    }
    if (rooms[i]->south) {
      printf("South to Room %d\n", rooms[i]->south->number);
    }
    if (rooms[i]->east) {
      printf("East to Room %d\n", rooms[i]->east->number);
    }
    if (rooms[i]->west) {
      printf("West to Room %d\n", rooms[i]->west->number);
    }
  }
}

int main() {
  generateMaze(MAX_Rooms);
  return 0;
}