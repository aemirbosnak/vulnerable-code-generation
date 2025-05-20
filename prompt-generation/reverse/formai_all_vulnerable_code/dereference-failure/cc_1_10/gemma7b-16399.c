//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

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
  room1->north = room2;
  room2->south = room1;
}

int generateMaze(int rooms, int paths) {
  srand(time(NULL));
  Room** roomsArray = malloc(rooms * sizeof(Room*));
  for (int i = 0; i < rooms; i++) {
    roomsArray[i] = createRoom(i + 1);
  }

  for (int i = 0; i < paths; i++) {
    int room1 = rand() % rooms;
    int room2 = rand() % rooms;
    if (room1 != room2) {
      connectRooms(roomsArray[room1], roomsArray[room2]);
    }
  }

  return roomsArray[0]->number;
}

int main() {
  int rooms = generateMaze(MAX_ROOMS, MAX_PATHS);
  printf("The first room number is: %d", rooms);
  return 0;
}