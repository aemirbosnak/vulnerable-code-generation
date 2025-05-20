//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

typedef struct node {
  int x;
  int y;
  struct node *parent;
} node_t;

node_t *open_list[ROWS * COLS];
int open_list_count = 0;

node_t *closed_list[ROWS * COLS];
int closed_list_count = 0;

node_t *path[ROWS * COLS];
int path_count = 0;

node_t *start_node;
node_t *end_node;

node_t *get_min_f_node() {
  if (open_list_count == 0) {
    return NULL;
  }

  node_t *min_node = open_list[0];
  int min_f = min_node->x + min_node->y;

  for (int i = 1; i < open_list_count; i++) {
    node_t *current_node = open_list[i];
    int current_f = current_node->x + current_node->y;

    if (current_f < min_f) {
      min_node = current_node;
      min_f = current_f;
    }
  }

  return min_node;
}

int node_in_list(node_t *node, node_t **list, int list_count) {
  for (int i = 0; i < list_count; i++) {
    node_t *current_node = list[i];

    if (current_node->x == node->x && current_node->y == node->y) {
      return 1;
    }
  }

  return 0;
}

void add_node_to_list(node_t *node, node_t **list, int *list_count) {
  if (!node_in_list(node, list, *list_count)) {
    list[*list_count] = node;
    (*list_count)++;
  }
}

void remove_node_from_list(node_t *node, node_t **list, int *list_count) {
  for (int i = 0; i < *list_count; i++) {
    node_t *current_node = list[i];

    if (current_node == node) {
      list[i] = list[*list_count - 1];
      (*list_count)--;
    }
  }
}

int is_valid_node(node_t *node) {
  if (node->x < 0 || node->x >= ROWS || node->y < 0 || node->y >= COLS) {
    return 0;
  }

  if (map[node->x][node->y] != 0) {
    return 0;
  }

  return 1;
}

int is_connected(node_t *node_1, node_t *node_2) {
  int dx = abs(node_1->x - node_2->x);
  int dy = abs(node_1->y - node_2->y);

  if ((dx == 0 && dy == 1) || (dx == 1 && dy == 0) || (dx == 1 && dy == 1)) {
    return 1;
  }

  return 0;
}

void add_valid_neighbors_to_list(node_t *node) {
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (dx == 0 && dy == 0) {
        continue;
      }

      node_t *neighbor_node = (node_t *) malloc(sizeof(node_t));
      neighbor_node->x = node->x + dx;
      neighbor_node->y = node->y + dy;
      neighbor_node->parent = node;

      if (is_valid_node(neighbor_node) && is_connected(node, neighbor_node)) {
        add_node_to_list(neighbor_node, open_list, &open_list_count);
      } else {
        free(neighbor_node);
      }
    }
  }
}

void find_path() {
  start_node = (node_t *) malloc(sizeof(node_t));
  start_node->x = 1;
  start_node->y = 1;
  start_node->parent = NULL;

  end_node = (node_t *) malloc(sizeof(node_t));
  end_node->x = 8;
  end_node->y = 8;
  end_node->parent = NULL;

  add_node_to_list(start_node, open_list, &open_list_count);

  while (open_list_count > 0) {
    node_t *current_node = get_min_f_node();

    remove_node_from_list(current_node, open_list, &open_list_count);
    add_node_to_list(current_node, closed_list, &closed_list_count);

    if (current_node->x == end_node->x && current_node->y == end_node->y) {
      node_t *path_node = current_node;

      while (path_node != NULL) {
        path[path_count] = path_node;
        path_node = path_node->parent;
        path_count++;
      }

      break;
    }

    add_valid_neighbors_to_list(current_node);
  }

  free(start_node);
  free(end_node);
}

void print_map() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 1 && j == 1) {
        printf("S ");
      } else if (i == 8 && j == 8) {
        printf("E ");
      } else if (map[i][j] != 0) {
        printf("X ");
      } else {
        printf("  ");
      }
    }

    printf("\n");
  }
}

void print_path() {
  for (int i = path_count - 1; i >= 0; i--) {
    printf("(%d,%d) ", path[i]->x, path[i]->y);
  }

  printf("\n");
}

int main() {
  find_path();
  print_map();
  print_path();

  return 0;
}