//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

Room** generateMaze(int size) {
  Room** maze = (Room**)malloc(size * sizeof(Room*));
  for (int i = 0; i < size; i++) {
    maze[i] = (Room*)malloc(sizeof(Room));
    maze[i]->x = -1;
    maze[i]->y = -1;
    maze[i]->next = NULL;
  }

  return maze;
}

void createRooms(Room** maze, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    maze[i]->x = rand() % size;
    maze[i]->y = rand() % size;
  }
}

void connectRooms(Room** maze, int size) {
  for (int i = 0; i < size; i++) {
    int numConnections = rand() % 3;
    for (int j = 0; j < numConnections; j++) {
      int targetRoom = rand() % size;
      if (targetRoom != i) {
        maze[i]->next = maze[targetRoom];
      }
    }
  }
}

int main() {
  int size = 10;
  Room** maze = generateMaze(size);
  createRooms(maze, size);
  connectRooms(maze, size);

  return 0;
}