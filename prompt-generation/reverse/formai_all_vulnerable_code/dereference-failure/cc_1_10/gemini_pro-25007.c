//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_PATH_LEN 1000

typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Node {
  Point point;
  struct Node *parent;
  int g_score;
  int h_score;
  int f_score;
} Node;

typedef struct PriorityQueue {
  Node **nodes;
  int size;
  int capacity;
} PriorityQueue;

PriorityQueue *create_priority_queue() {
  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->nodes = (Node **)malloc(sizeof(Node *) * MAX_PATH_LEN);
  pq->size = 0;
  pq->capacity = MAX_PATH_LEN;
  return pq;
}

void destroy_priority_queue(PriorityQueue *pq) {
  free(pq->nodes);
  free(pq);
}

void insert_node(PriorityQueue *pq, Node *node) {
  int i;

  if (pq->size == pq->capacity) {
    pq->nodes = (Node **)realloc(pq->nodes, sizeof(Node *) * pq->capacity * 2);
    pq->capacity *= 2;
  }

  for (i = pq->size - 1; i >= 0; i--) {
    if (node->f_score < pq->nodes[i]->f_score) {
      pq->nodes[i + 1] = pq->nodes[i];
    } else {
      break;
    }
  }

  pq->nodes[i + 1] = node;
  pq->size++;
}

Node *pop_node(PriorityQueue *pq) {
  Node *node = pq->nodes[0];

  pq->size--;
  pq->nodes[0] = pq->nodes[pq->size];

  return node;
}

int is_empty(PriorityQueue *pq) {
  return pq->size == 0;
}

int calculate_h_score(Point start, Point end) {
  return abs(end.x - start.x) + abs(end.y - start.y);
}

int calculate_g_score(Node *node, Point start) {
  return abs(node->point.x - start.x) + abs(node->point.y - start.y);
}

Node *create_node(Point point, Node *parent, Point start, Point end) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->point = point;
  node->parent = parent;
  node->g_score = calculate_g_score(node, start);
  node->h_score = calculate_h_score(node->point, end);
  node->f_score = node->g_score + node->h_score;
  return node;
}

void destroy_node(Node *node) {
  free(node);
}

int is_valid_point(Point point, int rows, int cols) {
  return point.x >= 0 && point.x < rows && point.y >= 0 && point.y < cols;
}

int is_obstacle(Point point, int **grid, int rows, int cols) {
  return grid[point.x][point.y] == 1;
}

Point *get_neighbors(Point point, int **grid, int rows, int cols) {
  Point *neighbors = (Point *)malloc(sizeof(Point) * 4);
  int i = 0;

  if (is_valid_point((Point){point.x - 1, point.y}, rows, cols) &&
      !is_obstacle((Point){point.x - 1, point.y}, grid, rows, cols)) {
    neighbors[i++] = (Point){point.x - 1, point.y};
  }

  if (is_valid_point((Point){point.x + 1, point.y}, rows, cols) &&
      !is_obstacle((Point){point.x + 1, point.y}, grid, rows, cols)) {
    neighbors[i++] = (Point){point.x + 1, point.y};
  }

  if (is_valid_point((Point){point.x, point.y - 1}, rows, cols) &&
      !is_obstacle((Point){point.x, point.y - 1}, grid, rows, cols)) {
    neighbors[i++] = (Point){point.x, point.y - 1};
  }

  if (is_valid_point((Point){point.x, point.y + 1}, rows, cols) &&
      !is_obstacle((Point){point.x, point.y + 1}, grid, rows, cols)) {
    neighbors[i++] = (Point){point.x, point.y + 1};
  }

  return neighbors;
}

Node *a_star(Point start, Point end, int **grid, int rows, int cols) {
  PriorityQueue *open_set = create_priority_queue();
  int **closed_set = (int **)malloc(sizeof(int *) * rows);

  for (int i = 0; i < rows; i++) {
    closed_set[i] = (int *)malloc(sizeof(int) * cols);
    for (int j = 0; j < cols; j++) {
      closed_set[i][j] = 0;
    }
  }

  insert_node(open_set, create_node(start, NULL, start, end));

  while (!is_empty(open_set)) {
    Node *current = pop_node(open_set);

    if (current->point.x == end.x && current->point.y == end.y) {
      return current;
    }

    closed_set[current->point.x][current->point.y] = 1;

    Point *neighbors = get_neighbors(current->point, grid, rows, cols);

    for (int i = 0; i < 4; i++) {
      Point neighbor = neighbors[i];

      if (closed_set[neighbor.x][neighbor.y] || is_obstacle(neighbor, grid, rows, cols)) {
        continue;
      }

      Node *neighbor_node = create_node(neighbor, current, start, end);

      insert_node(open_set, neighbor_node);
    }

    free(neighbors);
  }

  return NULL;
}

void print_path(Node *node) {
  if (node->parent == NULL) {
    printf("start");
  } else {
    print_path(node->parent);
    printf(" -> ");
    printf("(%d, %d)", node->point.x, node->point.y);
  }
}

int main() {
  int **grid = (int **)malloc(sizeof(int *) * MAX_ROWS);
  for (int i = 0; i < MAX_ROWS; i++) {
    grid[i] = (int *)malloc(sizeof(int) * MAX_COLS);
    for (int j = 0; j < MAX_COLS; j++) {
      grid[i][j] = 0;
    }
  }

  grid[0][0] = 1;
  grid[0][1] = 1;
  grid[0][2] = 1;
  grid[0][3] = 1;
  grid[0][4] = 1;
  grid[1][4] = 1;
  grid[2][4] = 1;
  grid[3][4] = 1;
  grid[4][4] = 1;
  grid[5][4] = 1;
  grid[6][4] = 1;
  grid[7][4] = 1;
  grid[8][4] = 1;
  grid[9][4] = 1;
  grid[10][4] = 1;

  Node *path =
      a_star((Point){0, 0}, (Point){9, 9}, grid, MAX_ROWS, MAX_COLS);

  if (path == NULL) {
    printf("No path found.\n");
  } else {
    printf("Path found:\n");
    print_path(path);
    printf("\n");
  }

  return 0;
}