//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define GRID_WIDTH  5
#define GRID_HEIGHT 5

struct Node {
  int x, y;
  struct Node *parent;
  int g, h, f;
};

bool is_valid_node(int x, int y) {
  return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}

bool is_obstacle(int x, int y) {
  return x == 2 && y == 2;
}

int calculate_h(struct Node *node, struct Node *goal) {
  return abs(node->x - goal->x) + abs(node->y - goal->y);
}

int calculate_g(struct Node *node, struct Node *parent) {
  return parent->g + 1;
}

int calculate_f(struct Node *node, struct Node *goal) {
  return node->g + node->h;
}

struct Node *create_node(int x, int y, struct Node *parent) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->x = x;
  node->y = y;
  node->parent = parent;
  return node;
}

struct Node *find_lowest_f(struct Node **open_nodes) {
  int lowest_f = INT_MAX;
  struct Node *lowest_node = NULL;

  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
    if (open_nodes[i] != NULL && open_nodes[i]->f < lowest_f) {
      lowest_f = open_nodes[i]->f;
      lowest_node = open_nodes[i];
    }
  }

  return lowest_node;
}

void remove_node(struct Node *node, struct Node **open_nodes) {
  open_nodes[node->y * GRID_WIDTH + node->x] = NULL;
  free(node);
}

struct Node *a_star(struct Node *start, struct Node *goal) {
  struct Node *open_nodes[GRID_WIDTH * GRID_HEIGHT];
  struct Node *closed_nodes[GRID_WIDTH * GRID_HEIGHT];

  for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
    open_nodes[i] = NULL;
    closed_nodes[i] = NULL;
  }

  open_nodes[start->y * GRID_WIDTH + start->x] = start;

  while (open_nodes[goal->y * GRID_WIDTH + goal->x] == NULL) {
    struct Node *current_node = find_lowest_f(open_nodes);

    if (current_node == NULL) {
      return NULL;
    }

    remove_node(current_node, open_nodes);
    closed_nodes[current_node->y * GRID_WIDTH + current_node->x] = current_node;

    for (int x = -1; x <= 1; x++) {
      for (int y = -1; y <= 1; y++) {
        if (x == 0 && y == 0) {
          continue;
        }

        int next_x = current_node->x + x;
        int next_y = current_node->y + y;

        if (!is_valid_node(next_x, next_y) || is_obstacle(next_x, next_y) || closed_nodes[next_y * GRID_WIDTH + next_x] != NULL) {
          continue;
        }

        struct Node *next_node = create_node(next_x, next_y, current_node);
        next_node->h = calculate_h(next_node, goal);
        next_node->g = calculate_g(next_node, current_node);
        next_node->f = calculate_f(next_node, goal);

        if (open_nodes[next_y * GRID_WIDTH + next_x] == NULL || next_node->f < open_nodes[next_y * GRID_WIDTH + next_x]->f) {
          open_nodes[next_y * GRID_WIDTH + next_x] = next_node;
        } else {
          free(next_node);
        }
      }
    }
  }

  return goal;
}

void print_path(struct Node *node) {
  if (node == NULL) {
    return;
  }

  print_path(node->parent);
  printf("(%d, %d)\n", node->x, node->y);
}

int main() {
  struct Node *start = create_node(0, 0, NULL);
  struct Node *goal = create_node(4, 4, NULL);

  struct Node *path = a_star(start, goal);

  if (path == NULL) {
    printf("No path found.\n");
  } else {
    printf("Path found:\n");
    print_path(path);
  }

  return 0;
}