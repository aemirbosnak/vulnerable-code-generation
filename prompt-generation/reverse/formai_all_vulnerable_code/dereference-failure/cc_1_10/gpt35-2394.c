//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Represents a node on the grid
typedef struct {
  int row, col;
  int g, h, f;
  bool closed;
  bool blocked;
  struct node* parent;
} node;

node* start;
node* goal;

node* nodes[ROWS][COLS];

void init_nodes() {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      node* n = malloc(sizeof(node));
      n->row = i;
      n->col = j;
      n->g = 0;
      n->h = 0;
      n->f = 0;
      n->closed = false;
      n->blocked = false;
      n->parent = NULL;
      nodes[i][j] = n;
    }
  }
  // Set the start and goal nodes
  start = nodes[0][0];
  goal = nodes[ROWS - 1][COLS - 1];
}

void init_blocks() {
  // Add some blocked nodes (obstacles)
  nodes[2][2]->blocked = true;
  nodes[3][2]->blocked = true;
  nodes[4][2]->blocked = true;
  nodes[6][5]->blocked = true;
  nodes[7][5]->blocked = true;
  nodes[8][5]->blocked = true;
}

// Returns the Manhattan distance between two nodes
int heuristic(node* n1, node* n2) {
  return abs(n1->row - n2->row) + abs(n1->col - n2->col);
}

// Returns the node with the lowest f value
node* min_f(node** open_set, int open_set_size) {
  node* n = open_set[0];
  for(int i = 1; i < open_set_size; i++) {
    if(open_set[i]->f < n->f) {
      n = open_set[i];
    }
  }
  return n;
}

// Returns the path from the start to the goal node
void get_path(node* current, node* path[ROWS * COLS]) {
  int i = 0;
  while(current != NULL) {
    path[i] = current;
    current = current->parent;
    i++;
  }
}

// Returns whether a node is in the array
bool in_array(node* n, node** array, int size) {
  for(int i = 0; i < size; i++) {
    if(array[i] == n) {
      return true;
    }
  }
  return false;
}

// Returns whether a node is blocked or not
bool is_blocked(node* n) {
  return n->blocked;
}

// Returns the neighbors of a node that are not blocked
void get_neighbors(node* n, node** neighbors, int* neighbors_size) {
  *neighbors_size = 0;
  int row = n->row;
  int col = n->col;
  if(row > 0 && !is_blocked(nodes[row - 1][col])) {
    neighbors[*neighbors_size] = nodes[row - 1][col];
    (*neighbors_size)++;
  }
  if(row < (ROWS - 1) && !is_blocked(nodes[row + 1][col])) {
    neighbors[*neighbors_size] = nodes[row + 1][col];
    (*neighbors_size)++;
  }
  if(col > 0 && !is_blocked(nodes[row][col - 1])) {
    neighbors[*neighbors_size] = nodes[row][col - 1];
    (*neighbors_size)++;
  }
  if(col < (COLS - 1) && !is_blocked(nodes[row][col + 1])) {
    neighbors[*neighbors_size] = nodes[row][col + 1];
    (*neighbors_size)++;
  }
}

// A* Pathfinding Algorithm
bool a_star() {
  node* open_set[ROWS * COLS];
  int open_set_size = 0;
  node* closed_set[ROWS * COLS];
  int closed_set_size = 0;

  start->g = 0;
  start->h = heuristic(start, goal);
  start->f = start->g + start->h;

  open_set[open_set_size] = start;
  open_set_size++;

  while(open_set_size > 0) {
    node* current = min_f(open_set, open_set_size);
    if(current == goal) {
      return true;
    }

    for(int i = 0; i < open_set_size; i++) {
      if(open_set[i] == current) {
        open_set[i] = open_set[open_set_size - 1];
        open_set_size--;
      }
    }

    closed_set[closed_set_size] = current;
    closed_set_size++;
    current->closed = true;

    node* neighbors[4];
    int neighbors_size;
    get_neighbors(current, neighbors, &neighbors_size);

    for(int i = 0; i < neighbors_size; i++) {
      node* neighbor = neighbors[i];
      if(neighbor->closed) {
        continue;
      }

      int tentative_g_score = current->g + heuristic(current, neighbor);

      if(!in_array(neighbor, open_set, open_set_size)) {
        open_set[open_set_size] = neighbor;
        open_set_size++;
      } else if(tentative_g_score >= neighbor->g) {
        continue;
      }

      neighbor->parent = current;
      neighbor->g = tentative_g_score;
      neighbor->h = heuristic(neighbor, goal);
      neighbor->f = neighbor->g + neighbor->h;
    }
  }
  return false;
}

int main() {
  init_nodes();
  init_blocks();

  node* path[ROWS * COLS];
  if(a_star()) {
    get_path(goal, path);
    printf("Path found!\n");
    for(int i = 0; i < ROWS * COLS; i++) {
      if(path[i] == NULL) {
        break;
      }
      printf("(%d,%d) ", path[i]->row, path[i]->col);
    }
    printf("\n");
  } else {
    printf("No path found!\n");
  }

  return 0;
}