//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct node {
  int x, y;
  struct node *prev;
} node_t;

int map[ROWS][COLS] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

node_t *frontier = NULL;
node_t *visited = NULL;
node_t *start = NULL;
node_t *end = NULL;
int found = 0;

node_t *create_node(int x, int y, node_t *prev);
void add_to_frontier(node_t *n);
node_t *pop_frontier();
void add_to_visited(node_t *n);
int in_visited(int x, int y);
int is_valid(int x, int y);
void print_map();
void print_path();

void main() {
  srand(time(NULL));
  int sx = rand() % COLS;
  int sy = rand() % ROWS;
  int ex = rand() % COLS;
  int ey = rand() % ROWS;
  start = create_node(sx, sy, NULL);
  end = create_node(ex, ey, NULL);
  add_to_frontier(start);
  while (frontier != NULL) {
    node_t *current = pop_frontier();
    if (current == end) {
      end->prev = current->prev;
      found = 1;
      break;
    }
    int x = current->x;
    int y = current->y;
    if (is_valid(x + 1, y)) {
      node_t *new_node = create_node(x + 1, y, current);
      add_to_frontier(new_node);
    }
    if (is_valid(x - 1, y)) {
      node_t *new_node = create_node(x - 1, y, current);
      add_to_frontier(new_node);
    }
    if (is_valid(x, y + 1)) {
      node_t *new_node = create_node(x, y + 1, current);
      add_to_frontier(new_node);
    }
    if (is_valid(x, y - 1)) {
      node_t *new_node = create_node(x, y - 1, current);
      add_to_frontier(new_node);
    }
    add_to_visited(current);
    print_map();
  }
  if (found) {
    print_path();
  } else {
    printf("No path found.\n");
  }
}

node_t *create_node(int x, int y, node_t *prev) {
  node_t *n = malloc(sizeof(node_t));
  n->x = x;
  n->y = y;
  n->prev = prev;
  return n;
}

void add_to_frontier(node_t *n) {
  if (n == NULL) {
    return;
  }
  n->prev = frontier;
  frontier = n;
}

node_t *pop_frontier() {
  node_t *n = frontier;
  if (n != NULL) {
    frontier = frontier->prev;
    n->prev = NULL;
  }
  return n;
}

void add_to_visited(node_t *n) {
  if (n == NULL) {
    return;
  }
  n->prev = visited;
  visited = n;
}

int in_visited(int x, int y) {
  node_t *n = visited;
  while (n != NULL) {
    if (n->x == x && n->y == y) {
      return 1;
    }
    n = n->prev;
  }
  return 0;
}

int is_valid(int x, int y) {
  if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
    return 0;
  }
  if (map[x][y] == 1) {
    return 0;
  }
  if (in_visited(x, y)) {
    return 0;
  }
  return 1;
}

void print_map() {
  if (found) {
    return;
  }
  system("clear");
  for (int x = 0; x < COLS; x++) {
    for (int y = 0; y < ROWS; y++) {
      if (map[x][y] == 1) {
        printf("#");
      } else if (start->x == x && start->y == y) {
        printf("S");
      } else if (end->x == x && end->y == y) {
        printf("E");
      } else if (in_visited(x, y)) {
        printf(".");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  usleep(100000);
}

void print_path() {
  node_t *n = end;
  while (n != NULL) {
    map[n->x][n->y] = 2;
    n = n->prev;
  }
  print_map();
}