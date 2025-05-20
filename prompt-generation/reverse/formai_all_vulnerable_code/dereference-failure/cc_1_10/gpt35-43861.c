//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 1, 0, 1, 1, 1, 0},
  {0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int start_row = 1;
int start_col = 1;
int end_row = 8;
int end_col = 8;

typedef struct node {
  int x;
  int y;
  struct node* parent;
  int g;
  int h;
  int f;
} node_t;

node_t* create_node(int x, int y, node_t* parent, int g, int h) {
  node_t* node = malloc(sizeof(node_t));
  node->x = x;
  node->y = y;
  node->parent = parent;
  node->g = g;
  node->h = h;
  node->f = g + h;
  return node;
}

int get_h(node_t* node) {
  return abs(node->x - end_row) + abs(node->y - end_col);
}

bool is_valid(int row, int col) {
  if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
    return false;
  }
  if (maze[row][col] == 0) {
    return false;
  }
  return true;
}

bool is_occupied(node_t* current, int row, int col) {
  node_t* temp = current;
  while(temp != NULL) {
    if (temp->x == row && temp->y == col) {
      return true;
    }
    temp = temp->parent;
  }
  return false;
}

bool is_node_in_list(node_t* node, node_t** list, int list_length) {
  for (int i = 0; i < list_length; i++) {
    if (list[i]->x == node->x && list[i]->y == node->y) {
      return true;
    }
  }
  return false;
}

void print_path(node_t* end_node) {
  printf("Path Found!\n\n");
  node_t* current = end_node;
  while(current != NULL) {
    printf("(%d, %d)\n", current->x, current->y);
    current = current->parent;
  }
}

void search() {
  node_t* start_node = create_node(start_row, start_col, NULL, 0, get_h(create_node(start_row, start_col, NULL, 0, 0)));
  node_t* end_node = create_node(end_row, end_col, NULL, 0, 0);
  node_t* open_list[ROWS*COLS] = {NULL};
  node_t* closed_list[ROWS*COLS] = {NULL};
  int open_length = 0;
  int closed_length = 0;
  open_list[open_length] = start_node;
  open_length++;

  while(open_length > 0) {
    int current_index = 0;
    for (int i = 0; i < open_length; i++) {
      if (open_list[i]->f < open_list[current_index]->f) {
        current_index = i;
      }
    }

    node_t* current = open_list[current_index];

    if (current->x == end_node->x && current->y == end_node->y) {
      print_path(current);
      return;
    }

    open_list[current_index] = NULL;
    open_length--;

    closed_list[closed_length] = current;
    closed_length++;

    for(int i = -1; i <= 1; i++) {
      for(int j = -1; j <= 1; j++) {
        if(i == 0 && j == 0) {
          continue;
        }
        int row = current->x + i;
        int col = current->y + j;
        if(!is_valid(row, col)) {
          continue;
        }
        if(is_occupied(current, row, col)) {
          continue;
        }
        int g = current->g + 1;
        int h = get_h(create_node(row, col, NULL, 0, 0));
        node_t* node = create_node(row, col, current, g, h);
        if (is_node_in_list(node, closed_list, closed_length)) {
          free(node);
          continue;
        }
        if (!is_node_in_list(node, open_list, open_length)) {
          open_list[open_length] = node;
          open_length++;
        } else {
          free(node);
        }
      }
    }
  }
  printf("No path found.");
}

int main() {
  search();
  return 0;
}