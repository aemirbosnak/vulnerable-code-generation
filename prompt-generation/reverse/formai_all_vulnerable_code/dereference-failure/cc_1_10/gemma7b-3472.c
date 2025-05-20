//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_Rooms 10

typedef struct Room {
  int num;
  struct Room* north;
  struct Room* south;
  struct Room* east;
  struct Room* west;
} Room;

Room** generateMaze(int numRooms) {
  Room** maze = malloc(numRooms * sizeof(Room*));
  for (int i = 0; i < numRooms; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->num = i + 1;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  // Connect rooms randomly
  for (int i = 0; i < numRooms; i++) {
    int randomDirection = rand() % 4;
    switch (randomDirection) {
      case 0:
        maze[i]->north = maze[rand() % numRooms];
        break;
      case 1:
        maze[i]->south = maze[rand() % numRooms];
        break;
      case 2:
        maze[i]->east = maze[rand() % numRooms];
        break;
      case 3:
        maze[i]->west = maze[rand() % numRooms];
        break;
    }
  }

  return maze;
}

int main() {
  int numRooms = MAX_Rooms;
  Room** maze = generateMaze(numRooms);

  // Print the maze
  for (int i = 0; i < numRooms; i++) {
    printf("Room %d: ", maze[i]->num);
    if (maze[i]->north) printf("North to Room %d, ", maze[i]->north->num);
    if (maze[i]->south) printf("South to Room %d, ", maze[i]->south->num);
    if (maze[i]->east) printf("East to Room %d, ", maze[i]->east->num);
    if (maze[i]->west) printf("West to Room %d\n", maze[i]->west->num);
  }

  return 0;
}