//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Path 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** generateMaze(int rooms, int path) {
  Room** maze = malloc(rooms * sizeof(Room*));
  for (int i = 0; i < rooms; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->x = i;
    maze[i]->y = 0;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }

  // Connect rooms randomly
  for (int i = 0; i < path; i++) {
    int room1 = rand() % rooms;
    int room2 = rand() % rooms;
    if (room1 != room2) {
      maze[room1]->east = maze[room2];
      maze[room2]->west = maze[room1];
    }
  }

  return maze;
}

int main() {
  srand(time(NULL));
  int rooms = rand() % MAX_Rooms + 1;
  int path = rand() % MAX_Path + 1;

  Room** maze = generateMaze(rooms, path);

  // Print the maze
  for (int i = 0; i < rooms; i++) {
    for (int j = 0; j < 20; j++) {
      printf("%c ", maze[i]->north ? '*' : '.');
    }
    printf("\n");
  }

  return 0;
}