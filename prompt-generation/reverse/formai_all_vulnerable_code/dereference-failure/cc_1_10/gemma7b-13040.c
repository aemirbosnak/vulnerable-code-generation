//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

#define MAX_NUM_ROOMS 10

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room* createRoom(int x, int y) {
  Room* room = malloc(sizeof(Room));
  room->x = x;
  room->y = y;
  room->next = NULL;
  return room;
}

void generateMaze(Room** rooms) {
  srand(time(NULL));
  int numRooms = rand() % MAX_NUM_ROOMS + 1;
  for (int i = 0; i < numRooms; i++) {
    rooms[i] = createRoom(rand() % MAZE_WIDTH, rand() % MAZE_HEIGHT);
  }

  for (int i = 0; i < numRooms; i++) {
    if (i > 0) {
      rooms[i]->next = rooms[rand() % i];
    }
  }
}

int main() {
  Room* rooms[MAX_NUM_ROOMS];
  generateMaze(rooms);

  for (int i = 0; i < MAX_NUM_ROOMS; i++) {
    printf("(%d, %d)\n", rooms[i]->x, rooms[i]->y);
  }

  return 0;
}