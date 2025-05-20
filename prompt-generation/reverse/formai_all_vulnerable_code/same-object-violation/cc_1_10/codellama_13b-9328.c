//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAZE_SIZE 100
#define MAX_PATH_LENGTH 100

typedef struct {
  int x, y;
} Position;

typedef struct {
  int visited[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
  int path[MAX_PATH_LENGTH][2];
  int path_length;
} MazeState;

int is_valid_position(MazeState *maze, Position pos) {
  return pos.x >= 0 && pos.x < maze->visited[0] && pos.y >= 0 && pos.y < maze->visited[1];
}

void mark_position(MazeState *maze, Position pos) {
  maze->visited[pos.x][pos.y] = 1;
}

void unmark_position(MazeState *maze, Position pos) {
  maze->visited[pos.x][pos.y] = 0;
}

void add_to_path(MazeState *maze, Position pos) {
  maze->path[maze->path_length][0] = pos.x;
  maze->path[maze->path_length][1] = pos.y;
  maze->path_length++;
}

void remove_from_path(MazeState *maze, Position pos) {
  maze->path_length--;
}

void print_maze(MazeState *maze) {
  for (int i = 0; i < maze->visited[0]; i++) {
    for (int j = 0; j < maze->visited[1]; j++) {
      printf("%d ", maze->visited[i][j]);
    }
    printf("\n");
  }
}

void print_path(MazeState *maze) {
  for (int i = 0; i < maze->path_length; i++) {
    printf("(%d, %d) ", maze->path[i][0], maze->path[i][1]);
  }
  printf("\n");
}

void solve_maze(MazeState *maze, Position start, Position goal) {
  Position pos = start;
  mark_position(maze, pos);
  add_to_path(maze, pos);
  while (pos.x != goal.x || pos.y != goal.y) {
    int x = pos.x;
    int y = pos.y;
    if (is_valid_position(maze, (Position){x+1, y}) && maze->visited[x+1][y] == 0) {
      pos.x++;
      mark_position(maze, pos);
      add_to_path(maze, pos);
    } else if (is_valid_position(maze, (Position){x-1, y}) && maze->visited[x-1][y] == 0) {
      pos.x--;
      mark_position(maze, pos);
      add_to_path(maze, pos);
    } else if (is_valid_position(maze, (Position){x, y+1}) && maze->visited[x][y+1] == 0) {
      pos.y++;
      mark_position(maze, pos);
      add_to_path(maze, pos);
    } else if (is_valid_position(maze, (Position){x, y-1}) && maze->visited[x][y-1] == 0) {
      pos.y--;
      mark_position(maze, pos);
      add_to_path(maze, pos);
    } else {
      remove_from_path(maze, pos);
      unmark_position(maze, pos);
      pos = (Position){maze->path[maze->path_length-1][0], maze->path[maze->path_length-1][1]};
      maze->path_length--;
    }
  }
  print_path(maze);
}

int main() {
  MazeState maze;
  memset(maze.visited, 0, sizeof(maze.visited));
  maze.path_length = 0;
  Position start = (Position){0, 0};
  Position goal = (Position){maze.visited[0]-1, maze.visited[1]-1};
  solve_maze(&maze, start, goal);
  print_maze(&maze);
  return 0;
}