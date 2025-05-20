//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Paths 5

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

void connectRooms(Room* room1, Room* room2) {
  room1->north = room2;
  room2->south = room1;
}

void generateMaze(int numRooms) {
  srand(time(NULL));
  Room** rooms = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = createRoom(i + 1);
  }

  for (int i = 0; i < numRooms - 1; i++) {
    int numPaths = rand() % MAX_Paths;
    for (int j = 0; j < numPaths; j++) {
      connectRooms(rooms[i], rooms[rand() % numRooms]);
    }
  }

  // Print the maze
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: ", rooms[i]->num);
    if (rooms[i]->north) {
      printf("North to Room %d\n", rooms[i]->north->num);
    }
    if (rooms[i]->south) {
      printf("South to Room %d\n", rooms[i]->south->num);
    }
    if (rooms[i]->east) {
      printf("East to Room %d\n", rooms[i]->east->num);
    }
    if (rooms[i]->west) {
      printf("West to Room %d\n", rooms[i]->west->num);
    }
    printf("\n");
  }
}

int main() {
  generateMaze(MAX_Rooms);
  return 0;
}