//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAZE_SIZE 10

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  char *data;
  int width;
  int height;
} Maze;

Maze *createMaze(int width, int height) {
  Maze *maze = malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;
  maze->data = malloc(width * height * sizeof(char));
  memset(maze->data, ' ', width * height);
  return maze;
}

void destroyMaze(Maze *maze) {
  free(maze->data);
  free(maze);
}

void printMaze(Maze *maze) {
  for (int y = 0; y < maze->height; y++) {
    for (int x = 0; x < maze->width; x++) {
      printf("%c", maze->data[y * maze->width + x]);
    }
    printf("\n");
  }
  printf("\n");
}

void generateMaze(Maze *maze) {
  srand(time(NULL));
  int x = rand() % maze->width;
  int y = rand() % maze->height;
  maze->data[y * maze->width + x] = '*';
  while (1) {
    int directions[4];
    directions[0] = x - 1;
    directions[1] = x + 1;
    directions[2] = y - 1;
    directions[3] = y + 1;
    int numDirections = 4;
    for (int i = 0; i < numDirections; i++) {
      int index = rand() % numDirections;
      int direction = directions[index];
      directions[index] = directions[numDirections - 1];
      directions[numDirections - 1] = direction;
      numDirections--;
      if (direction >= 0 && direction < maze->width && maze->data[y * maze->width + direction] == ' ') {
        x = direction;
        maze->data[y * maze->width + x] = '*';
        break;
      } else if (direction >= 0 && direction < maze->height && maze->data[direction * maze->width + x] == ' ') {
        y = direction;
        maze->data[y * maze->width + x] = '*';
        break;
      }
    }
    if (numDirections == 0) {
      break;
    }
  }
}

int main() {
  Maze *maze = createMaze(MAZE_SIZE, MAZE_SIZE);
  generateMaze(maze);
  printMaze(maze);
  destroyMaze(maze);
  return 0;
}