//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MATRIX_SIZE 10
#define OBSTACLE '#'
#define PATH '.'

typedef struct {
  int x;
  int y;
} Cell;

typedef struct {
  Cell **matrix;
  int width;
  int height;
} Matrix;

Matrix *create_matrix(int width, int height) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->width = width;
  matrix->height = height;
  matrix->matrix = malloc(sizeof(Cell *) * height);
  for (int i = 0; i < height; i++) {
    matrix->matrix[i] = malloc(sizeof(Cell) * width);
  }
  return matrix;
}

void destroy_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    free(matrix->matrix[i]);
  }
  free(matrix->matrix);
  free(matrix);
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      printf("%c", matrix->matrix[i][j].x == -1 ? OBSTACLE : PATH);
    }
    printf("\n");
  }
}

int manhattan_distance(Cell a, Cell b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

Cell *find_path(Matrix *matrix, Cell start, Cell end) {
  int **distance = malloc(sizeof(int *) * matrix->height);
  int **visited = malloc(sizeof(int *) * matrix->height);
  for (int i = 0; i < matrix->height; i++) {
    distance[i] = malloc(sizeof(int) * matrix->width);
    visited[i] = malloc(sizeof(int) * matrix->width);
  }
  for (int i = 0; i < matrix->height; i++) {
    for (int j = 0; j < matrix->width; j++) {
      distance[i][j] = INT_MAX;
      visited[i][j] = 0;
    }
  }
  distance[start.y][start.x] = 0;
  while (1) {
    Cell current = {-1, -1};
    int min_distance = INT_MAX;
    for (int i = 0; i < matrix->height; i++) {
      for (int j = 0; j < matrix->width; j++) {
        if (!visited[i][j] && distance[i][j] < min_distance) {
          current.x = j;
          current.y = i;
          min_distance = distance[i][j];
        }
      }
    }
    if (current.x == -1) {
      break;
    }
    visited[current.y][current.x] = 1;
    if (current.x == end.x && current.y == end.y) {
      return &current;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int new_x = current.x + i;
        int new_y = current.y + j;
        if (new_x >= 0 && new_x < matrix->width && new_y >= 0 && new_y < matrix->height && matrix->matrix[new_y][new_x].x != -1) {
          int new_distance = distance[current.y][current.x] + 1;
          if (new_distance < distance[new_y][new_x]) {
            distance[new_y][new_x] = new_distance;
          }
        }
      }
    }
  }
  return NULL;
}

int main() {
  Matrix *matrix = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
  matrix->matrix[0][0].x = -1;
  matrix->matrix[0][1].x = -1;
  matrix->matrix[0][2].x = -1;
  matrix->matrix[1][0].x = -1;
  matrix->matrix[1][2].x = -1;
  matrix->matrix[2][0].x = -1;
  matrix->matrix[2][1].x = -1;
  matrix->matrix[2][2].x = -1;
  Cell start = {0, 3};
  Cell end = {9, 6};
  Cell *path = find_path(matrix, start, end);
  if (path) {
    printf("Path found:\n");
    while (path->x != start.x || path->y != start.y) {
      matrix->matrix[path->y][path->x].x = 0;
      path = &matrix->matrix[path->y][path->x];
    }
    print_matrix(matrix);
  } else {
    printf("No path found.\n");
  }
  destroy_matrix(matrix);
  return 0;
}