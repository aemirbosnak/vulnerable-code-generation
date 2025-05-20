//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node {
  int x;
  int y;
  int g;
  int h;
  int f;
  struct Node *parent;
} Node;

typedef struct PriorityQueue {
  Node** nodes;
  int size;
  int capacity;
} PriorityQueue;

Node* create_node(int x, int y, int g, int h, Node* parent) {
  Node *node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->g = g;
  node->h = h;
  node->f = g + h;
  node->parent = parent;
  return node;
}

PriorityQueue* create_priority_queue(int capacity) {
  PriorityQueue *queue = malloc(sizeof(PriorityQueue));
  queue->nodes = malloc(sizeof(Node*) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

void push(PriorityQueue *queue, Node *node) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    queue->nodes = realloc(queue->nodes, sizeof(Node*) * queue->capacity);
  }
  queue->nodes[queue->size++] = node;
}

Node* pop(PriorityQueue *queue) {
  if (queue->size == 0) {
    return NULL;
  }
  int min_index = 0;
  for (int i = 1; i < queue->size; i++) {
    if (queue->nodes[i]->f < queue->nodes[min_index]->f) {
      min_index = i;
    }
  }
  Node *node = queue->nodes[min_index];
  queue->nodes[min_index] = queue->nodes[queue->size - 1];
  queue->size--;
  return node;
}

bool is_valid(int x, int y, int width, int height) {
  return x >= 0 && x < width && y >= 0 && y < height;
}

bool is_obstacle(int x, int y, int** obstacles, int num_obstacles) {
  for (int i = 0; i < num_obstacles; i++) {
    if (obstacles[i][0] == x && obstacles[i][1] == y) {
      return true;
    }
  }
  return false;
}

int heuristic(Node *node, Node *goal) {
  return abs(node->x - goal->x) + abs(node->y - goal->y);
}

Node* a_star(int** grid, int width, int height, Node *start, Node *goal, int** obstacles, int num_obstacles) {
  PriorityQueue *open = create_priority_queue(width * height);
  push(open, start);

  while (open->size > 0) {
    Node *current = pop(open);
    if (current->x == goal->x && current->y == goal->y) {
      return current;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int x = current->x + i;
        int y = current->y + j;
        if (is_valid(x, y, width, height) && !is_obstacle(x, y, obstacles, num_obstacles)) {
          Node *neighbor = create_node(x, y, current->g + grid[x][y], heuristic(neighbor, goal), current);
          push(open, neighbor);
        }
      }
    }
  }

  return NULL;
}

void print_path(Node *node) {
  if (node->parent != NULL) {
    print_path(node->parent);
  }
  printf("(%d, %d)\n", node->x, node->y);
}

int main() {
  int width = 10;
  int height = 10;

  int** grid = malloc(sizeof(int*) * height);
  for (int i = 0; i < height; i++) {
    grid[i] = malloc(sizeof(int) * width);
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      grid[i][j] = 1;
    }
  }

  int** obstacles = malloc(sizeof(int*) * 3);
  obstacles[0] = malloc(sizeof(int) * 2);
  obstacles[0][0] = 2;
  obstacles[0][1] = 2;
  obstacles[1] = malloc(sizeof(int) * 2);
  obstacles[1][0] = 5;
  obstacles[1][1] = 5;
  obstacles[2] = malloc(sizeof(int) * 2);
  obstacles[2][0] = 8;
  obstacles[2][1] = 8;

  Node *start = create_node(0, 0, 0, 0, NULL);
  Node *goal = create_node(9, 9, 0, 0, NULL);

  Node *path = a_star(grid, width, height, start, goal, obstacles, 3);

  if (path != NULL) {
    print_path(path);
  } else {
    printf("No path found.\n");
  }

  for (int i = 0; i < height; i++) {
    free(grid[i]);
  }
  free(grid);

  for (int i = 0; i < 3; i++) {
    free(obstacles[i]);
  }
  free(obstacles);

  free(start);
  free(goal);

  return 0;
}