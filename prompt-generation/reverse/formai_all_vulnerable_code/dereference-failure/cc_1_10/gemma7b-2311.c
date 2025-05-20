//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 5

typedef struct Room {
  int num;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room** generateMaze(int numRooms, int numPaths) {
  srand(time(NULL));

  Room** maze = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->num = i + 1;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  for (int i = 0; i < numPaths; i++) {
    int room1 = rand() % numRooms;
    int room2 = rand() % numRooms;

    if (room1 != room2) {
      maze[room1]->east = maze[room2];
      maze[room2]->west = maze[room1];
    }
  }

  return maze;
}

int main() {
  Room** maze = generateMaze(MAX_ROOMS, MAX_PATHS);

  // Print the maze
  for (int i = 0; i < MAX_ROOMS; i++) {
    printf("Room %d: ", maze[i]->num);
    if (maze[i]->north) printf("North to Room %d ", maze[i]->north->num);
    if (maze[i]->south) printf("South to Room %d ", maze[i]->south->num);
    if (maze[i]->east) printf("East to Room %d ", maze[i]->east->num);
    if (maze[i]->west) printf("West to Room %d ", maze[i]->west->num);
    printf("\n");
  }

  return 0;
}