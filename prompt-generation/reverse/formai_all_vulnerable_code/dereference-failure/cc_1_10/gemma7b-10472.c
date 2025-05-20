//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define EMPTY_SPACE ' '
#define WALL_SPACE '#'
#define PLAYER_SPACE 'P'

typedef struct Node {
  struct Node* next;
  int x;
  int y;
} Node;

void initializeMaze(char** maze, int w, int h) {
  for (int i = 0; i < h; i++) {
    maze[i] = (char*)malloc(w * sizeof(char));
    for (int j = 0; j < w; j++) {
      maze[i][j] = EMPTY_SPACE;
    }
  }
}

void generateMaze(char** maze) {
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      if (rand() % 2 == 0) {
        maze[i][j] = WALL_SPACE;
      }
    }
  }
}

void findPath(Node* current, char** maze) {
  if (current->x == MAZE_WIDTH - 1 && current->y == MAZE_HEIGHT - 1) {
    return;
  }

  maze[current->x][current->y] = PLAYER_SPACE;

  findPath(current->next, maze);

  if (current->next) {
    maze[current->next->x][current->next->y] = PLAYER_SPACE;
  }
}

int main() {
  char** maze = NULL;
  initializeMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
  generateMaze(maze);
  findPath(malloc(sizeof(Node)), maze);

  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      printf("%c ", maze[i][j]);
    }
    printf("\n");
  }

  return 0;
}