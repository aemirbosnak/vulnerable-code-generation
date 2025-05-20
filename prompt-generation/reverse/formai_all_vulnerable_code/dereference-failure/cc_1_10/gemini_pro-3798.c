//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_X 10
#define MAX_Y 10

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point point;
  int g_score;
  int h_score;
  int f_score;
  struct Node *parent;
} Node;

typedef struct {
  Node *nodes[MAX_X][MAX_Y];
  int open_set_size;
  int closed_set_size;
} Grid;

Node *create_node(Point point, int g_score, int h_score, Node *parent) {
  Node *node = malloc(sizeof(Node));
  node->point = point;
  node->g_score = g_score;
  node->h_score = h_score;
  node->f_score = g_score + h_score;
  node->parent = parent;
  return node;
}

Grid *create_grid() {
  Grid *grid = malloc(sizeof(Grid));
  for (int x = 0; x < MAX_X; x++) {
    for (int y = 0; y < MAX_Y; y++) {
      grid->nodes[x][y] = NULL;
    }
  }
  grid->open_set_size = 0;
  grid->closed_set_size = 0;
  return grid;
}

void add_to_open_set(Grid *grid, Node *node) {
  grid->nodes[node->point.x][node->point.y] = node;
  grid->open_set_size++;
}

void remove_from_open_set(Grid *grid, Node *node) {
  grid->nodes[node->point.x][node->point.y] = NULL;
  grid->open_set_size--;
}

void add_to_closed_set(Grid *grid, Node *node) {
  grid->nodes[node->point.x][node->point.y] = node;
  grid->closed_set_size++;
}

Node *get_node_from_open_set(Grid *grid, int x, int y) {
  return grid->nodes[x][y];
}

Node *get_lowest_f_score_node_from_open_set(Grid *grid) {
  Node *lowest_f_score_node = NULL;
  for (int x = 0; x < MAX_X; x++) {
    for (int y = 0; y < MAX_Y; y++) {
      Node *node = grid->nodes[x][y];
      if (node != NULL && (lowest_f_score_node == NULL || node->f_score < lowest_f_score_node->f_score)) {
        lowest_f_score_node = node;
      }
    }
  }
  return lowest_f_score_node;
}

bool is_valid_point(Point point) {
  return point.x >= 0 && point.x < MAX_X && point.y >= 0 && point.y < MAX_Y;
}

bool is_obstacle(Point point) {
  return point.x == 2 && point.y == 2;
}

int calculate_h_score(Point point, Point goal) {
  return abs(point.x - goal.x) + abs(point.y - goal.y);
}

bool find_path(Grid *grid, Point start, Point goal) {
  Node *start_node = create_node(start, 0, calculate_h_score(start, goal), NULL);
  add_to_open_set(grid, start_node);

  while (grid->open_set_size > 0) {
    Node *current_node = get_lowest_f_score_node_from_open_set(grid);
    if (current_node == NULL) {
      return false;
    }

    if (current_node->point.x == goal.x && current_node->point.y == goal.y) {
      return true;
    }

    remove_from_open_set(grid, current_node);
    add_to_closed_set(grid, current_node);

    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0) {
          continue;
        }

        Point neighbor_point = {current_node->point.x + dx, current_node->point.y + dy};

        if (!is_valid_point(neighbor_point) || is_obstacle(neighbor_point)) {
          continue;
        }

        Node *neighbor_node = get_node_from_open_set(grid, neighbor_point.x, neighbor_point.y);
        if (neighbor_node == NULL) {
          neighbor_node = create_node(neighbor_point, current_node->g_score + 1, calculate_h_score(neighbor_point, goal), current_node);
          add_to_open_set(grid, neighbor_node);
        } else if (neighbor_node->g_score > current_node->g_score + 1) {
          neighbor_node->parent = current_node;
          neighbor_node->g_score = current_node->g_score + 1;
          neighbor_node->f_score = neighbor_node->g_score + neighbor_node->h_score;
        }
      }
    }
  }

  return false;
}

void print_path(Grid *grid, Point start, Point goal) {
  Node *current_node = get_node_from_open_set(grid, goal.x, goal.y);
  while (current_node != NULL) {
    printf("(%d, %d)\n", current_node->point.x, current_node->point.y);
    current_node = current_node->parent;
  }
}

int main() {
  Grid *grid = create_grid();

  Point start = {0, 0};
  Point goal = {9, 9};

  bool found_path = find_path(grid, start, goal);

  if (found_path) {
    printf("Path found!\n");
    print_path(grid, start, goal);
  } else {
    printf("Path not found.\n");
  }

  return 0;
}