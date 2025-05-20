//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PATHS 2

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

Room** createMaze(int w, int h) {
  Room** maze = malloc(w * h * sizeof(Room*));
  for (int i = 0; i < w * h; i++) {
    maze[i] = malloc(sizeof(Room));
    maze[i]->x = -1;
    maze[i]->y = -1;
    maze[i]->north = NULL;
    maze[i]->south = NULL;
    maze[i]->east = NULL;
    maze[i]->west = NULL;
  }
  return maze;
}

void generateMaze(Room** maze, int w, int h) {
  srand(time(NULL));
  for (int i = 0; i < w * h; i++) {
    maze[i]->x = rand() % w;
    maze[i]->y = rand() % h;
  }
}

void connectRooms(Room** maze, int w, int h) {
  for (int i = 0; i < w * h; i++) {
    int x = maze[i]->x;
    int y = maze[i]->y;
    if (x - 1 >= 0) maze[i]->west = maze[rand() % MAX_PATHS]->north;
    if (x + 1 < w) maze[i]->east = maze[rand() % MAX_PATHS]->south;
    if (y - 1 >= 0) maze[i]->north = maze[rand() % MAX_PATHS]->west;
    if (y + 1 < h) maze[i]->south = maze[rand() % MAX_PATHS]->east;
  }
}

void printMaze(Room** maze, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      Room* current = maze[x + w * y];
      if (current->x == -1 && current->y == -1) {
        printf(" ");
      } else {
        printf("%c ", current->x + 'a' - 'a');
      }
    }
    printf("\n");
  }
}

int main() {
  int w = 5;
  int h = 5;

  Room** maze = createMaze(w, h);
  generateMaze(maze, w, h);
  connectRooms(maze, w, h);
  printMaze(maze, w, h);

  return 0;
}